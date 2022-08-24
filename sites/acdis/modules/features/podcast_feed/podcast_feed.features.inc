<?php
/**
 * @file
 * podcast_feed.features.inc
 */

/**
 * Implements hook_views_api().
 */
function podcast_feed_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
