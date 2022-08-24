<?php

/**
 * @file
 * Class election_post_views_handler_filter_published.
 */

/**
 * Views handler to filter election posts by 'published' status.
 */
class election_post_views_handler_filter_published extends views_handler_filter {

  /**
   *
   */
  public function admin_summary() {
  }

  /**
   *
   */
  public function operator_form(&$form, &$form_state) {
  }

  /**
   * Overrides parent::can_expose().
   *
   * It makes no sense to expose this filter.
   */
  public function can_expose() {
    return FALSE;
  }

  /**
   *
   */
  public function query() {
    // Join to the election table: posts should not be displayed if the election
    // is not published.
    $join = new views_join();
    $join->construct('election', 'election_post', 'election_id', 'election_id');
    $post_table = $this->ensure_my_table();
    $election_table = $this->query->add_relationship('election', $join, $this->table_alias, $this->relationship);
    $this->query->add_where_expression($this->options['group'], "($post_table.published = 1 AND $election_table.published = 1) OR ($election_table.uid = ***CURRENT_USER*** AND ***CURRENT_USER*** <> 0) OR ***EDIT_ANY_ELECTION*** = 1");
  }

}
