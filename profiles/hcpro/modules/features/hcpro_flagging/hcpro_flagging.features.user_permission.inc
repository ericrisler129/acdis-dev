<?php
/**
 * @file
 * hcpro_flagging.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hcpro_flagging_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer flags'.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'flag favorites'.
  $permissions['flag favorites'] = array(
    'name' => 'flag favorites',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'basic' => 'basic',
      'editor' => 'editor',
      'free' => 'free',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'unflag favorites'.
  $permissions['unflag favorites'] = array(
    'name' => 'unflag favorites',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'basic' => 'basic',
      'editor' => 'editor',
      'free' => 'free',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use flag import'.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'flag',
  );

  return $permissions;
}
