<?php

/**
 * Implements hook_preprocess_page().
 */
function hcprobt_preprocess_page(&$variables) {

  /////////////////////////////////////////////////////////////
  // Examples of setting faux title on different types of pages
  /////////////////////////////////////////////////////////////


  // Add faux titles to pages
  $variables['page']['faux_title'] = '';
  $variables['page']['faux_title_icon'] = '';

  /*
  // My Account
  if ($variables['theme_hook_suggestions'][0]  == 'page__edit_profile') {
    $variables['page']['faux_title_icon'] = 'fa fa-users';
    drupal_set_title("Membership");
  }

  // Free Samples
  if (isset($variables['node']) && $variables['node']->nid == 883) {
    $variables['page']['faux_title_icon'] = 'fa fa-star';
  }

  // Detail pages
  if (isset($variables['node']->type)) {
    switch($variables['node']->type) {
      case 'news_analysis':
        $variables['page']['faux_title_icon'] = 'fa fa-file-text-o fa-flip-vertical fa-flip-horizontal';
        $variables['page']['faux_title'] = 'News &amp; Analysis';
        break;
    }
  }

  // Main pages
  if (isset($variables['node']->nid)) {
    switch($variables['node']->nid) {
      case 2:
        $variables['page']['faux_title_icon'] = 'fa fa-file-text-o fa-flip-vertical fa-flip-horizontal';
        break;
      case 3:
        $variables['page']['faux_title_icon'] = 'fa fa-list-alt';
        break;
    }
  }
  */

  // Remove "no associated content..." from taxonomy terms
  if(isset($variables['page']['content']['system_main']['no_content'])) {
    unset($variables['page']['content']['system_main']['no_content']);
  }
}

