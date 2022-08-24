<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * hcpro theme.
 */

/**
 * Implements hcprobt_get_path().
 */
function hcprobt_get_path(){
  if (variable_get('use_debug_theme')){
    return  drupal_get_path('theme', $GLOBALS['theme']) . '/debug';
  } else {
    return drupal_get_path('theme', $GLOBALS['theme']) . '/release';
  }
}

function blr_video_embed($sku) {
  try {
    db_set_active('wistia');

    // Per Jim: change last letter of sku to A, if ending with a letter
    if(ctype_alpha(substr($sku,-1)))
      $sku = substr($sku,0,-1) . 'A';

    $video_id = db_query('select wistia_id from conferences where pub_code = :sku',
      [ ':sku' => $sku ])->fetchField();
    if(!$video_id) return false;
    return '<iframe src="//fast.wistia.net/embed/iframe/'.$video_id.'?videoFoam=true" allowtransparency="true" frameborder="0" scrolling="no" class="wistia_embed" name="wistia_embed" allowfullscreen mozallowfullscreen webkitallowfullscreen oallowfullscreen msallowfullscreen width="640" height="480"></iframe><script src="//fast.wistia.net/assets/external/E-v1.js"></script>';

  } finally {
    db_set_active();
  }
}

function hcprobt_facetapi_count($variables) {
  return '';
}

function hcprobt_block_view_search_form_alter(&$data, $block) {
  $data['content']['#sorted'] = TRUE;
  $data['content']['actions']['submit'] = array('#type' => 'image_button', '#src' => '/profiles/hcpro/themes/hcprobt/debug/images/search.png');
  $data['content']['search_block_form']['#attributes']['placeholder'] = "Search Site";
  $data['content']['powered_by'] = array(
    '#markup' => '<img class="powered-by" src="/profiles/hcpro/themes/hcprobt/debug/images/powered-by-hcpro.png" />',
  );
}

/*
function hcprobt_menu_alter(&$items) {
  $items['taxonomy/term/%taxonomy_term']['page callback'] = 'hcpro_taxonomy_term_redirect';
}

function hcprobt_taxonomy_term_redirect($term) {
  $options = array(
    'query' => array(
      'news_category' => $term->tid,
    ),
  );

  if($term->vocabulary_machine_name == 'resource_categories')
    drupal_goto('resources', $options);
  else if($term->vocabulary_machine_name == 'news_analysis_categories')
    drupal_goto('news-analysis', $options);
  else
    return taxonomy_term_page($term);
}
*/
