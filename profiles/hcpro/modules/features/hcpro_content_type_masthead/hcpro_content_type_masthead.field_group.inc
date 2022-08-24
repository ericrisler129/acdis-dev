<?php
/**
 * @file
 * hcpro_content_type_masthead.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function hcpro_content_type_masthead_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_buttons|field_collection_item|field_slides|default';
  $field_group->group_name = 'group_buttons';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slides';
  $field_group->mode = 'default';
  $field_group->parent_name = 'group_overlay';
  $field_group->data = array(
    'label' => 'Buttons',
    'weight' => '2',
    'children' => array(
      0 => 'field_link',
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
  $field_groups['group_buttons|field_collection_item|field_slides|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_slides|default';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slides';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Overlay',
    'weight' => '1',
    'children' => array(
      0 => 'field_body_fc',
      1 => 'field_title_fc',
      2 => 'group_buttons',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Overlay',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'group-overlay field-group-div',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_overlay|field_collection_item|field_slides|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_overlay|field_collection_item|field_slides|form';
  $field_group->group_name = 'group_overlay';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_slides';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Text Overlay',
    'weight' => '2',
    'children' => array(
      0 => 'field_link',
      1 => 'field_title_fc',
      2 => 'field_body_fc',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Text Overlay',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-overlay field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_overlay|field_collection_item|field_slides|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Buttons');
  t('Overlay');
  t('Text Overlay');

  return $field_groups;
}
