<?php

define('DRUPAL_ROOT', getcwd());
require_once DRUPAL_ROOT . '/includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);

$query = drupal_get_query_parameters();
$legacy_id = $query['legacy_id'];

$node = new EntityFieldQuery();
$node->entityCondition('entity_type', 'node')
  ->entityCondition('bundle', array('article', 'resource'))
  ->fieldCondition('field_legacy_id', 'value', $legacy_id)
  ->addTag('DANGEROUS_ACCESS_CHECK_OPT_OUT');
$result = $node->execute();

if ($result) {
  $node = array_keys($result['node']);
  $nid = $node[0];
  $new_url = drupal_get_path_alias("/node/{$nid}");
  drupal_goto($new_url, array(), 301);
} else {
  drupal_not_found();
}
