<?php
/**
 * @file
 * hcpro_flagging.features.inc
 */

/**
 * Implements hook_views_api().
 */
function hcpro_flagging_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function hcpro_flagging_flag_default_flags() {
  $flags = array();
  // Exported flag: "Favorites".
  $flags['favorites'] = array(
    'entity_type' => 'node',
    'title' => 'Favorites',
    'global' => 0,
    'types' => array(
      0 => 'article',
      1 => 'radio',
      2 => 'resource',
    ),
    'flag_short' => '<i class="fa fa-star-o fa-2x"></i>',
    'flag_long' => 'Add this content to your favorites',
    'flag_message' => 'This page has been added to your favorites',
    'unflag_short' => '<i class="fa fa-star fa-2x"></i>',
    'unflag_long' => 'Remove this content from your favorites',
    'unflag_message' => 'This page has been removed from your favorites',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 'full',
      'teaser' => 'teaser',
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'token' => 0,
      'teaser_with_meta' => 0,
      'slider' => 0,
      'teaser_small' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 1,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'api_version' => 3,
    'module' => 'hcpro_flagging',
    'locked' => array(
      0 => 'name',
    ),
  );
  return $flags;

}
