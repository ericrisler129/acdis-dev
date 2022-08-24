<?php

class AcdisResourceMigration extends AcdisXmlMigration {

  protected $baseDir;

  public function __construct($arguments) {
    parent::__construct($arguments);

    $fields = array(
      'content_id' => t('Legacy ID'),
      'title' => t('Title'),
      'published' => t('Published Date'),
      'status' => t('Published Status'),
      'content_type' => t('Content Type'),
      'summary' => t('Summary'),
      'body1' => t('Body 1'),
      'body2' => t('Body 2'),
      'body3' => t('Body 3'),
      'body4' => t('Body 4'),
      'body5' => t('Body 5'),
      'meta_keywords' => t('Meta Keywords'),
      'filename' => t('File Name'),
      'file_uri' => t('File URI'),
    );

    $this->baseDir = '/mnt/data/sites/acdis.blrstage.com/resource-files';
    $files = array_diff(scandir($this->baseDir), array("..", "."));
    $this->file_names = array();
    foreach ($files as $file) {
      $name = pathinfo($file, PATHINFO_FILENAME);
      $this->file_names[$name] = $file;
    }

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'migrate_acdis') . '/xml/';
    $items_url = $xml_folder . 'articles.xml';

    $item_xpath = '/root/content';
    $item_ID_xpath = 'content_id';
    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    $this->destination = new MigrateDestinationNode('resource');

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'content_id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        )
      ),
      MigrateDestinationNode::getKeySchema()
    );

    // NODE MAPPING
    $this->addFieldMapping('field_legacy_id', 'content_id')->xpath('content_id');
    $this->addFieldMapping('title', 'title')->xpath('title')->callbacks('strip_tags', 'html_entity_decode');
    $this->addFieldMapping('created', 'published')->xpath('published');
    $this->addFieldMapping('status', 'status')->xpath('status');
    $this->addFieldMapping('body', 'body1')->xpath('body1');
    $this->addFieldMapping('body:summary', 'summary')->xpath('summary');
    $this->addFieldMapping('body:format')->defaultValue('full_html');
    $this->addFieldMapping('metatag_keywords', 'meta_keywords')->xpath('meta_keywords');
    $this->addFieldMapping('promote')->defaultValue(0);
    $this->addFieldMapping('sticky')->defaultValue(0);
    $this->addFieldMapping('revision')->defaultValue(0);
    $this->addFieldMapping('field_category', 'category')->xpath('category');
    $this->addFieldMapping('field_category:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_category:ignore_case')->defaultValue(TRUE);
    $this->addFieldMapping('field_resource_type', 'resource_type')->xpath('resource_type');
    $this->addFieldMapping('field_resource_type:source_type')->defaultValue('tid');
    $this->addFieldMapping('field_resource_type:ignore_case')->defaultValue(TRUE);

    // FILE MAPPING
    $this->addFieldMapping('field_file_download', 'filename')->sourceMigration('ResourceFiles');
    $this->addFieldMapping('field_file_download:source_dir', $this->baseDir);
    $this->addFieldMapping('field_file_download:destination_dir')->defaultValue('private://resources');
    $this->addFieldMapping('field_file_download:destination_file', 'filename');

    // Unmapped source fields
    $this->addUnmigratedSources(array(
      'content_type',
      'body2',
      'body3',
      'body4',
      'body5',
    ));

    // Unmapped destination fields
    $this->addUnmigratedDestinations(array(
      'changed',
      'log',
      'language',
      'tnid',
      'translate',
      'revision_uid',
      'is_new',
      'path',
      'comment',
      'uid',
    ));

    // Map terms provided in csv
    if (empty($this->terms)) {
      $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'migrate_acdis') . '/taxonomy/taxonomy-resources.csv';
      $handle = fopen($filename, 'r');
      if ($handle) {
        while ($data = fgetcsv($handle)) {
          unset($terms);
          $legacy_id = $data[0];
          $terms[] = $data[3];
          $terms[] = $data[4];
          $terms[] = $data[5];
          $this->terms[$legacy_id] = $terms;
          $this->resource_type[$legacy_id] = $data[1];
          $this->pub_status[$legacy_id] = $data[6];
        }
        fclose($handle);
      }
    }
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ((string)$row->xml->content_type != "Forms and Tools") {
      return FALSE;
    }

    // Combine body fields
    $break = "";
    $row->xml->body1 =
      $row->xml->body1.$break
      .$row->xml->body2.$break
      .$row->xml->body3.$break
      .$row->xml->body4.$break
      .$row->xml->body5;

    $legacy_id = (string) $row->xml->content_id;
    $terms = $this->terms[$legacy_id];
    if(isset($terms)) {
      foreach($this->terms[$legacy_id] as $term) {
        $row->xml->category[] = $term;
      }
    }

    $resource_type = $this->resource_type[$legacy_id];
    if(isset($resource_type)) {
      $row->xml->resource_type = $resource_type;
    }

    $status = $this->pub_status[$legacy_id];
    if (isset($status)) {
      $row->xml->status = $status;
    }

    if (isset($this->file_names[$legacy_id])) {
      $row->xml->file_uri = $this->baseDir . "/" . $this->file_names[$legacy_id];
      $row->xml->filename = $this->file_names[$legacy_id];
      $row->xml->destination_file = $this->file_names[$legacy_id];
    }
  }
}

class ResourceFileMigration extends AcdisXmlMigration {

  protected $baseDir;

  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->baseDir = '/mnt/data/sites/acdis.blrstage.com/resource-files';

    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sourceid' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
          'description' => t('Source ID'),
        ),
      ),
      MigrateDestinationFile::getKeySchema()
    );

    $directories = array(
      $this->baseDir,
    );

    $allowed = 'jpg jpeg xls ppt doc txt dot mht mp3 mp4 pptx xlsx docx pdf rtf zip';
    if (module_exists('file_entity')) {
      $allowed = variable_get('file_entity_default_allowed_extensions', $allowed);
    }
    $file_mask = '/^.*\.(' . str_replace(array(',', ' '), '|', $allowed) . ')$/i';
    $list = new MigrateListFiles($directories, $this->baseDir, $file_mask);
    $item = new MigrateItemFile($this->baseDir, FALSE);
    $fields = array('sourceid' => t('File name with path'));
    $this->source = new MigrateSourceList($list, $item, $fields);
    $this->destination = new MigrateDestinationFile('file', 'MigrateFileUri');

    $this->addFieldMapping('destination_dir')->defaultValue('private://resources');
    $this->addFieldMapping('destination_file', 'destination_file');
    $this->addFieldMapping('value', 'file_uri');
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    $row->file_uri = $this->baseDir . $row->sourceid;
    $row->destination_file = substr($row->sourceid, 1);
  }
}
