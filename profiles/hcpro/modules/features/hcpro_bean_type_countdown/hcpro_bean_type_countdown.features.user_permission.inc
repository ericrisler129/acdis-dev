<?php
/**
 * @file
 * hcpro_bean_type_countdown.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function hcpro_bean_type_countdown_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create any countdown bean'.
  $permissions['create any countdown bean'] = array(
    'name' => 'create any countdown bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'delete any countdown bean'.
  $permissions['delete any countdown bean'] = array(
    'name' => 'delete any countdown bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'edit any countdown bean'.
  $permissions['edit any countdown bean'] = array(
    'name' => 'edit any countdown bean',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'bean',
  );

  // Exported permission: 'view any countdown bean'.
  $permissions['view any countdown bean'] = array(
    'name' => 'view any countdown bean',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'bean',
  );

  return $permissions;
}
