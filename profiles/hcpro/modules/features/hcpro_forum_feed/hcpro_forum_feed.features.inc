<?php
/**
 * @file
 * hcpro_forum_feed.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcpro_forum_feed_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hcpro_forum_feed_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function hcpro_forum_feed_node_info() {
  $items = array(
    'forum_feed' => array(
      'name' => t('Forum Feed'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
