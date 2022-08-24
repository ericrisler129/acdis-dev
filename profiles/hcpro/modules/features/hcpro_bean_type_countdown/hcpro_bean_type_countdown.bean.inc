<?php
/**
 * @file
 * hcpro_bean_type_countdown.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function hcpro_bean_type_countdown_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'countdown';
  $bean_type->label = 'Countdown';
  $bean_type->options = '';
  $bean_type->description = '';
  $export['countdown'] = $bean_type;

  return $export;
}
