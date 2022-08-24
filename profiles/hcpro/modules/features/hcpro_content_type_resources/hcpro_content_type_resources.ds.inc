<?php
/**
 * @file
 * hcpro_content_type_resources.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hcpro_content_type_resources_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h1',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'ds_post_date_standard',
    ),
    'field_file_download' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'styled-download',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
    'field_generic_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'button',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
          'fi-first-last' => FALSE,
        ),
      ),
    ),
  );
  $export['node|resource|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|resource|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'resource';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'sponsor_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '8',
      'label' => 'hidden',
      'format' => 'ds_post_date_standard',
    ),
  );
  $export['node|resource|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hcpro_content_type_resources_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'flag_favorites',
        1 => 'title',
        2 => 'group_details',
        3 => 'body',
        4 => 'group_buttons',
        5 => 'field_file_download',
        6 => 'field_embed_code',
        7 => 'post_date',
        8 => 'field_resource_type',
        9 => 'field_category',
        10 => 'field_generic_link',
      ),
    ),
    'fields' => array(
      'flag_favorites' => 'ds_content',
      'title' => 'ds_content',
      'group_details' => 'ds_content',
      'body' => 'ds_content',
      'group_buttons' => 'ds_content',
      'field_file_download' => 'ds_content',
      'field_embed_code' => 'ds_content',
      'post_date' => 'ds_content',
      'field_resource_type' => 'ds_content',
      'field_category' => 'ds_content',
      'field_generic_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'detail' => 'detail',
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
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|resource|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|resource|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'resource';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sponsor_heading',
        1 => 'title',
        2 => 'group_details',
        3 => 'body',
        4 => 'post_date',
        5 => 'field_resource_type',
        6 => 'field_category',
      ),
    ),
    'fields' => array(
      'sponsor_heading' => 'ds_content',
      'title' => 'ds_content',
      'group_details' => 'ds_content',
      'body' => 'ds_content',
      'post_date' => 'ds_content',
      'field_resource_type' => 'ds_content',
      'field_category' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'teaser' => 'teaser',
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
  $export['node|resource|teaser'] = $ds_layout;

  return $export;
}
