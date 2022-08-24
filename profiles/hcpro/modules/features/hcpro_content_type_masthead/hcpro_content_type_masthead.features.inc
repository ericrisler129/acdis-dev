<?php
/**
 * @file
 * hcpro_content_type_masthead.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcpro_content_type_masthead_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hcpro_content_type_masthead_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hcpro_content_type_masthead_image_default_styles() {
  $styles = array();

  // Exported image style: masthead.
  $styles['masthead'] = array(
    'label' => 'masthead',
    'effects' => array(
      4 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 1070,
          'height' => 300,
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
function hcpro_content_type_masthead_node_info() {
  $items = array(
    'masthead' => array(
      'name' => t('Masthead'),
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
