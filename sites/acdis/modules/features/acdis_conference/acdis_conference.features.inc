<?php
/**
 * @file
 * acdis_conference.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function acdis_conference_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panelizer" && $api == "panelizer") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function acdis_conference_image_default_styles() {
  $styles = array();

  // Exported image style: sponsor_grid.
  $styles['sponsor_grid'] = array(
    'label' => 'Sponsor Grid',
    'effects' => array(
      6 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 230,
          'height' => 80,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function acdis_conference_node_info() {
  $items = array(
    'conference' => array(
      'name' => t('Conference'),
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
