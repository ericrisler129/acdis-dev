<?php
/**
 * @file
 * podcast_feed.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function podcast_feed_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'delete terms in views_rss_itunes_category'.
  $permissions['delete terms in views_rss_itunes_category'] = array(
    'name' => 'delete terms in views_rss_itunes_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in views_rss_itunes_category'.
  $permissions['edit terms in views_rss_itunes_category'] = array(
    'name' => 'edit terms in views_rss_itunes_category',
    'roles' => array(),
    'module' => 'taxonomy',
  );

  return $permissions;
}
