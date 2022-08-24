<?php
/**
 * @file
 * acdis_conference.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function acdis_conference_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_assets|node|conference|form';
  $field_group->group_name = 'group_assets';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Assets',
    'weight' => '3',
    'children' => array(
      0 => 'field_file_download',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Assets',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-assets field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_assets|node|conference|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sponsors|node|conference|form';
  $field_group->group_name = 'group_sponsors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'conference';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sponsors',
    'weight' => '2',
    'children' => array(
      0 => 'field_exclusive_sponsor',
      1 => 'field_platinum_sponsors',
      2 => 'field_welcome_sponsors',
      3 => 'field_exhibitors',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sponsors',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-sponsors field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_sponsors|node|conference|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Assets');
  t('Sponsors');

  return $field_groups;
}
