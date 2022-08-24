<?php
/**
 * @file
 * hcpro_content_type_masthead.ds.inc
 */

/**
 * Implements hook_ds_layout_settings_info().
 */
function hcpro_content_type_masthead_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|masthead|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'masthead';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_slides',
      ),
    ),
    'fields' => array(
      'field_slides' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|masthead|default'] = $ds_layout;

  return $export;
}
