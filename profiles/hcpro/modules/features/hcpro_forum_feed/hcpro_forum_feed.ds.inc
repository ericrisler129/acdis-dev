<?php
/**
 * @file
 * hcpro_forum_feed.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hcpro_forum_feed_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|forum_feed|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'forum_feed';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_standard',
    ),
  );
  $export['node|forum_feed|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hcpro_forum_feed_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|forum_feed|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'forum_feed';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_generic_link',
        1 => 'field_author',
        2 => 'post_date',
      ),
    ),
    'fields' => array(
      'field_generic_link' => 'ds_content',
      'field_author' => 'ds_content',
      'post_date' => 'ds_content',
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
    'layout_disable_css' => FALSE,
  );
  $export['node|forum_feed|teaser'] = $ds_layout;

  return $export;
}
