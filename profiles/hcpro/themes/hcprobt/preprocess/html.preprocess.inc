<?php

/**
 * @file
 * Short description.
 */

/**
 * Implements hook_preprocess_html().
 */
function hcprobt_preprocess_html(&$variables) {

  /*
  drupal_add_css('/profiles/hcpro/themes/hcprobt/release/styles/css/hcprobt.hacks.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css('/profiles/hcpro/themes/hcprobt/release/styles/css/hcprobt.no-query.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css('/profiles/hcpro/themes/hcprobt/release/styles/css/hcprobt.normalize.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css('/profiles/hcpro/themes/hcprobt/release/styles/css/hcprobt.styles.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  drupal_add_css('/profiles/hcpro/themes/hcprobt/release/styles/css/screen.css', array('group' => CSS_THEME, 'preprocess' => FALSE));
  */

  drupal_add_js('/profiles/hcpro/themes/hcprobt/js/hcprobt.behaviors.js',
  array(
    'type' => 'file',
    'every_page' => TRUE,
    'scope' => 'footer',
    'preprocess' => TRUE,
  ));

  $variables['theme_name'] = $GLOBALS['theme'];
}
