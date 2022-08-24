<?php
/**
 * @file
 * hcpro_content_type_resources.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hcpro_content_type_resources_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets|node|resource|form';
  $field_group->group_name = 'group_assets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '2',
    'children' => array(
      0 => 'field_file_download',
      1 => 'field_embed_code',
      2 => 'field_generic_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-assets field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_assets|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buttons|node|resource|full';
  $field_group->group_name = 'group_buttons';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Buttons',
    'weight' => '4',
    'children' => array(
      0 => 'field_generic_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Buttons',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-buttons field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_buttons|node|resource|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categorization|node|resource|form';
  $field_group->group_name = 'group_categorization';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categorization',
    'weight' => '3',
    'children' => array(
      0 => 'field_resource_type',
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
  $field_groups['group_categorization|node|resource|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|resource|default';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '1',
    'children' => array(
      0 => 'field_resource_type',
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
  $field_groups['group_details|node|resource|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|resource|full';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_resource_type',
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
  $field_groups['group_details|node|resource|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|resource|teaser';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_resource_type',
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
  $field_groups['group_details|node|resource|teaser'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_details|node|resource|teaser_small';
  $field_group->group_name = 'group_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'resource';
  $field_group->mode = 'teaser_small';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Details',
    'weight' => '2',
    'children' => array(
      0 => 'field_resource_type',
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
  $field_groups['group_details|node|resource|teaser_small'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assets');
  t('Buttons');
  t('Categorization');
  t('Details');

  return $field_groups;
}
