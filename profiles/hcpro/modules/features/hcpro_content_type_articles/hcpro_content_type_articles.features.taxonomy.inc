<?php
/**
 * @file
 * hcpro_content_type_articles.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function hcpro_content_type_articles_taxonomy_default_vocabularies() {
  return array(
    'article_categories' => array(
      'name' => 'Article Categories',
      'machine_name' => 'article_categories',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'article_section' => array(
      'name' => 'Article Section',
      'machine_name' => 'article_section',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'publications' => array(
      'name' => 'Publications',
      'machine_name' => 'publications',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
    'volume_and_issue' => array(
      'name' => 'Volume and Issue',
      'machine_name' => 'volume_and_issue',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
    ),
  );
}
