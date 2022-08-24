<?php
/**
 * @file
 * hcpro_ds_view_modes.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function hcpro_ds_view_modes_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'favorites';
  $ds_view_mode->label = 'Favorites';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['favorites'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'samples';
  $ds_view_mode->label = 'Samples';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['samples'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_short';
  $ds_view_mode->label = 'Teaser Short';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_short'] = $ds_view_mode;

  return $export;
}
