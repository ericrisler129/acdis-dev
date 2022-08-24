<?php
/**
 * @file
 * hcpro_content_type_articles.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hcpro_content_type_articles_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets|node|article|form';
  $field_group->group_name = 'group_assets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '2',
    'children' => array(
      0 => 'field_image',
      1 => 'field_file_download',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Assets',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-assets field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_assets|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categorization|node|article|form';
  $field_group->group_name = 'group_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '3',
    'children' => array(
      0 => 'field_publication',
      1 => 'field_category',
      2 => 'field_sponsor',
      3 => 'field_legacy_id',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-categorization field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_categorization|node|article|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|article|full';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_publication',
      1 => 'post_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details|node|article|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|article|teaser';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_publication',
      1 => 'field_category',
      2 => 'post_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details|node|article|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|article|teaser_small';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'teaser_small';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_publication',
      1 => 'field_category',
      2 => 'post_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details|node|article|teaser_small'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|article|teaser_with_meta';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'article';
  $field_group->mode = 'teaser_with_meta';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '3',
    'children' => array(
      0 => 'field_category',
      1 => 'post_date',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Details',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-details field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_details|node|article|teaser_with_meta'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assets');
  t('Categorization');
  t('Details');

  return $field_groups;
}
