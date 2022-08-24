<?php

/**
 * Field handler for the candidate category.
 */
class election_candidate_views_handler_field_candidate_category extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  public function render($values) {
    $post = election_post_load((int) $values->_field_data['candidate_id']['entity']->post_id);
    return isset($post->settings['candidate_categories'][$values->election_candidate_candidate_category]['name']) ? $post->settings['candidate_categories'][$values->election_candidate_candidate_category]['name'] : NULL;
  }

}
