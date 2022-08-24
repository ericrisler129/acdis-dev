<?php
/**
 * @file
 * hcpro_content_type_resources.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hcpro_content_type_resources_taxonomy_default_vocabularies() {
  return array(
    'resource_categories' => array(
      'name' => 'Resource Categories',
      'machine_name' => 'resource_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'resource_type' => array(
      'name' => 'Resource Type',
      'machine_name' => 'resource_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
