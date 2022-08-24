<?php
/**
 * @file
 * hcpro_view_articles.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function hcpro_view_articles_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "flexslider" && $api == "flexslider_default_preset") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function hcpro_view_articles_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function hcpro_view_articles_image_default_styles() {
  $styles = array();

  // Exported image style: slider_home.
  $styles['slider_home'] = array(
    'label' => 'Slider Home',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 395,
          'height' => 200,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
