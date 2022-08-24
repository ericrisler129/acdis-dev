<?php

/**
 * @file
 * Short description.
 */

/**
 * Implements hcpro_get_path().
 *
 * This will control the debug/release output of there files.
 */
function hcpro_theme_sub_get_path() {
  if (variable_get('use_debug_theme')) {
    return drupal_get_path('theme', $GLOBALS['theme']) . '/debug';
  }
  else {
    return drupal_get_path('theme', $GLOBALS['theme']) . '/release';
  }
}

/**
 * Implements hook_preprocess_html().
 */
function hcpro_theme_preprocess_html(&$variables) {

  drupal_add_css(hcpro_theme_sub_get_path() . '/styles/css/hcprobt.hacks.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css(hcpro_theme_sub_get_path() . '/styles/css/hcprobt.no-query.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css(hcpro_theme_sub_get_path() . '/styles/css/hcprobt.normalize.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css(hcpro_theme_sub_get_path() . '/styles/css/hcprobt.styles.css', array('group' => CSS_THEME, 'preprocess' => FALSE));

  // If the HCPro base layout plugin is overridden, include the new plugins css here
  drupal_add_css(hcpro_theme_sub_get_path() . '/styles/css/hcpro.layout.css', array('group' => CSS_THEME, 'preprocess' => FALSE));

  drupal_add_js(drupal_get_path('theme', $GLOBALS['theme']) . '/js/hcpro_theme.behaviors.js',
  array(
    'type' => 'file',
    'every_page' => TRUE,
    'scope' => 'footer',
    'preprocess' => TRUE,
  ));

  $variables['theme_name'] = $GLOBALS['theme'];
}
