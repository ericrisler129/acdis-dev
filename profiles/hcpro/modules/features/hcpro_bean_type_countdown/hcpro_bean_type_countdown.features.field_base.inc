<?php
/**
 * @file
 * hcpro_bean_type_countdown.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function hcpro_bean_type_countdown_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_countdown_description'.
  $field_bases['field_countdown_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_countdown_description',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  return $field_bases;
}
