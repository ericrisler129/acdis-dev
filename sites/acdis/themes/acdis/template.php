<?php

function acdis_form_alter(&$form, &$form_state, $form_id) {
  if ($form['#id'] == "views-exposed-form-resources-block" || $form['#id'] == "views-exposed-form-free-resources-block") {
    $form['keywords']['#attributes']['placeholder'] = "Keywords";
    $form['#prefix'] = "<div class='filter-label'><span>Filter By:</span></div>";
  } elseif ($form['#id'] == "views-exposed-form-articles-page-1") {
    $form['keywords']['#attributes']['placeholder'] = "Keywords";
  } elseif ($form_id == 'poll_view_voting') {
    $form['vote']['#value'] = "Submit Poll";
    $form['vote']['#attributes']['class'][] = 'button-input';
    $form['vote']['#attributes']['class'][] = 'button-input-brand1';
    $form['#node']->links = array();
  } elseif ($form_id == 'blr_sample_signup_signup_form') {
    $chapter_tree = taxonomy_get_tree(5);
    $chapters = [];
    foreach ($chapter_tree as $chapter_term) {
      $chapters[] = $chapter_term->name;
    }

    $form['LocalChapter'] = array(
      '#type' => 'select',
      '#title' => 'Local Chapter',
      '#options' => $chapters,
      '#required' => false,
      '#weight' => -5,
      '#empty_option' => "I am not a member of a local chapter",
    );
  }
}

function acdis_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    unset($breadcrumb[0]);
    unset($breadcrumb[1]);
    $breadcrumb[] = drupal_get_title();
    $output = '<ul class="breadcrumb"><li>' . implode('</li><li>', $breadcrumb) . '</li></ul>';
    return $output;
  }
}

function acdis_block_view_search_form_alter(&$data, $block) {
  /*
  $data['content']['powered_by'] = array(
    '#markup' => '<img class="powered-by" src="/sites/acdis/themes/acdis/debug/images/powered-by-hcpro.png" />',
  );
  */
  $data['content']['powered_by'] = array();
}

function acdis_menu_link($variables) {
  if ($variables['theme_hook_original'] == "menu_link__user_menu") {
    if ($variables['element']['#title'] == "Renew") {
      $variables['element']['#attributes']['class']['hidden'] = "element-hidden";

      if (function_exists('blr_webauth_renewal_remind') && blr_webauth_renewal_remind()) {
        unset($variables['element']['#attributes']['class']['hidden']);
      }
    }
  }

  return theme_menu_link($variables);
}
