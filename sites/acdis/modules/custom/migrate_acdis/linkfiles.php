<?php
$baseDir = '/mnt/data/sites/acdis.blrstage.com/resource-files';
$files = array_diff(scandir($baseDir), array("..", "."));
$file_names = array();
foreach ($files as $file) {
  $name = pathinfo($file, PATHINFO_FILENAME);
  $file_names[$name] = $file;
}

$query = new EntityFieldQuery();
$query->entityCondition('entity_type', 'node')->entityCondition('bundle', 'resource');
$result = $query->execute();

if (isset($result['node'])) {
  $resource_nids = array_keys($result['node']);

  foreach ($resource_nids as $nid) {
    $resource_node = node_load($nid);

    $legacy_id = $resource_node->field_legacy_id[LANGUAGE_NONE][0]['value'];

    if (isset($file_names[$legacy_id])) {
      $file_query = db_query("SELECT * FROM {file_managed} WHERE filename LIKE :pattern", array(':pattern' => db_like($legacy_id) . '%'))->fetchAssoc();
      $resource_node->field_file_download[LANGUAGE_NONE][0]['fid'] = $file_query['fid'];
      $resource_node->field_file_download['und'][0]['filename'] = $file_query['fid'];
      $resource_node->field_file_download['und'][0]['uri'] = $file_query['uri'];
      $resource_node->field_file_download['und'][0]['display'] = 1;
      node_save($resource_node);
    }
  }
}
