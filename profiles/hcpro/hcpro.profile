<?php
/**
 * @file
 * Enables modules and site configuration for a HCPRO site installation.
 */

/**
 * Implements hook_install_tasks()
 *
 * Allows the profile to have custom installation steps
 */
function hcpro_install_tasks() {
  // Include install task functions only during installation
  include_once 'hcpro.install.inc';

  $tasks = array();

  $tasks['hcpro_set_themes'] = array(
    'display' => FALSE,
    'type' => 'normal',
  );

  $tasks['hcpro_set_home_link_weight'] = array(
    'display' => FALSE,
    'type' => 'normal',
  );

  return $tasks;
}
