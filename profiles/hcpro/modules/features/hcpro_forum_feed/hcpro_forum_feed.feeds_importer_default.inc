<?php
/**
 * @file
 * hcpro_forum_feed.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function hcpro_forum_feed_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'forums';
  $feeds_importer->config = array(
    'name' => 'Forums',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => FALSE,
        'use_pubsubhubbub' => FALSE,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
        'accept_invalid_cert' => FALSE,
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '2592000',
        'author' => 0,
        'authorize' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          1 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'author_name',
            'target' => 'field_author',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'url',
            'target' => 'field_generic_link:url',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'title',
            'target' => 'field_generic_link:title',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'full_html',
        'skip_hash_check' => 0,
        'bundle' => 'forum_feed',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '21600',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['forums'] = $feeds_importer;

  return $export;
}
