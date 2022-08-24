<?php
/**
 * @file
 * Declares our migrations.
 */


/**
 * Implements hook_migrate_api().
 */
function migrate_acdis_migrate_api() {
  $api = array(
    'api' => 2,
    'groups' => array(
      'articles' => array(
        'title' => t('ACDIS Articles'),
      ),
      'resources' => array(
        'title' => t('ACDIS Resources'),
      ),
    ),
    'migrations' => array(
      'Articles' => array(
        'class_name' => 'AcdisArticleMigration',
        'group_name' => 'articles',
      ),
      'Resources' => array(
        'class_name' => 'AcdisResourceMigration',
        'group_name' => 'resources',
        'soft_dependencies' => array('ResourceFiles'),
      ),
      'ResourceFiles' => array(
        'class_name' => 'ResourceFileMigration',
        'group_name' => 'resources',
      ),
    ),
  );
  return $api;
}
