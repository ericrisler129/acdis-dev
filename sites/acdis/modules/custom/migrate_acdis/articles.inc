<?php

abstract class AcdisXmlMigration extends XMLMigration {
  public function __construct($arguments) {
    parent::__construct($arguments);

    $this->team = array(
      new MigrateTeamMember('Patrick Ryan', 'patrick@fractalonline.com',
        t('Implementor')),
    );
  }
}

class AcdisArticleMigration extends AcdisXmlMigration {
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
      'volume' => t('Volume'),
      'issue' => t('Issue'),
      'article_position' => t('Article Position'),
      'article_publication' => t('Publication'),
    );

    $xml_folder = DRUPAL_ROOT . '/' . drupal_get_path('module', 'migrate_acdis') . '/xml/';
    $items_url = $xml_folder . 'articles.xml';

    $item_xpath = '/root/content';
    $item_ID_xpath = 'content_id';

    $items_class = new MigrateItemsXML($items_url, $item_xpath, $item_ID_xpath);
    $this->source = new MigrateSourceMultiItems($items_class, $fields);
    $this->destination = new MigrateDestinationNode('article');

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

    $this->addFieldMapping('field_legacy_id', 'content_id')->xpath('content_id');
    $this->addFieldMapping('title', 'title')->xpath('title')->callbacks('strip_tags', 'html_entity_decode');
    $this->addFieldMapping('created', 'published')->xpath('published');
    $this->addFieldMapping('status', 'status')->xpath('status');
    $this->addFieldMapping('field_publication', 'article_publication')->xpath('article_publication');
    $this->addFieldMapping('field_publication:volume', 'volume')->xpath('volume');
    $this->addFieldMapping('field_publication:issue', 'issue')->xpath('issue');
    $this->addFieldMapping('field_publication:position', 'article_position')->xpath('article_position');
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
      $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'migrate_acdis') . '/taxonomy/taxonomy.csv';
      $handle = fopen($filename, 'r');
      if ($handle) {
        while ($data = fgetcsv($handle)) {
          unset($terms);
          $legacy_id = $data[0];
          $terms[] = $data[1];
          $terms[] = $data[2];
          $terms[] = $data[3];
          $this->terms[$legacy_id] = $terms;
          $this->pub_status[$legacy_id] = $data[4];
        }
        fclose($handle);
      }
    }
  }

  public function prepareRow($row) {
    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }

    if ((string)$row->xml->content_type != "Article") {
      return FALSE;
    }

    // Only import journal/strategies
    if ($row->xml->article_publication == "CDI Journal") {
      $row->xml->article_publication = 1;
    } elseif ($row->xml->article_publication == "CDI Strategies") {
      $row->xml->article_publication = 2;
    } else {
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

    $status = $this->pub_status[$legacy_id];
    if (isset($status)) {
      $row->xml->status = $status;
    }
  }
}
