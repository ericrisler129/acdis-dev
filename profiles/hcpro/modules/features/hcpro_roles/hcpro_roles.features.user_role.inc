<?php
/**
 * @file
 * hcpro_roles.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function hcpro_roles_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 5,
  );

  // Exported role: basic.
  $roles['basic'] = array(
    'name' => 'basic',
    'weight' => 3,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 4,
  );

  // Exported role: free.
  $roles['free'] = array(
    'name' => 'free',
    'weight' => 2,
  );

  return $roles;
}
