<?php
/**
 * @file
 * hcpro_rest_endpoint.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hcpro_rest_endpoint_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rest';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'REST';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Content: Category */
  $handler->display->display_options['fields']['field_category']['id'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['table'] = 'field_data_field_category';
  $handler->display->display_options['fields']['field_category']['field'] = 'field_category';
  $handler->display->display_options['fields']['field_category']['label'] = 'category';
  $handler->display->display_options['fields']['field_category']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_category']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_category']['delta_offset'] = '0';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'standard';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Publication */
  $handler->display->display_options['fields']['field_publication']['id'] = 'field_publication';
  $handler->display->display_options['fields']['field_publication']['table'] = 'field_data_field_publication';
  $handler->display->display_options['fields']['field_publication']['field'] = 'field_publication';
  $handler->display->display_options['fields']['field_publication']['label'] = 'publication';
  $handler->display->display_options['fields']['field_publication']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_publication']['click_sort_column'] = 'publication';
  $handler->display->display_options['fields']['field_publication']['type'] = 'volume_with_publication';
  $handler->display->display_options['fields']['field_publication']['settings'] = array(
    'data_element_key' => '',
    'skip_safe' => 0,
    'skip_empty_values' => 0,
  );
  /* Field: Content: Resource Type */
  $handler->display->display_options['fields']['field_resource_type']['id'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['field'] = 'field_resource_type';
  $handler->display->display_options['fields']['field_resource_type']['label'] = 'resource_type';
  $handler->display->display_options['fields']['field_resource_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_resource_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'url';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'article' => 'article',
    'radio' => 'radio',
    'resource' => 'resource',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'node';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'article' => 'article',
    'radio' => 'radio',
    'resource' => 'resource',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Nid */
  $handler->display->display_options['filters']['nid']['id'] = 'nid';
  $handler->display->display_options['filters']['nid']['table'] = 'node';
  $handler->display->display_options['filters']['nid']['field'] = 'nid';
  $handler->display->display_options['filters']['nid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['nid']['expose']['operator_id'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['label'] = 'Nid';
  $handler->display->display_options['filters']['nid']['expose']['operator'] = 'nid_op';
  $handler->display->display_options['filters']['nid']['expose']['identifier'] = 'nid';
  $handler->display->display_options['filters']['nid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Resource Type (field_resource_type) */
  $handler->display->display_options['filters']['field_resource_type_tid']['id'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['table'] = 'field_data_field_resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['field'] = 'field_resource_type_tid';
  $handler->display->display_options['filters']['field_resource_type_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator_id'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['label'] = 'Resource Type (field_resource_type)';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['operator'] = 'field_resource_type_tid_op';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['identifier'] = 'resource_type';
  $handler->display->display_options['filters']['field_resource_type_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_resource_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_resource_type_tid']['vocabulary'] = 'resource_type';
  /* Filter criterion: Content: Category (field_category) */
  $handler->display->display_options['filters']['field_category_tid']['id'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['table'] = 'field_data_field_category';
  $handler->display->display_options['filters']['field_category_tid']['field'] = 'field_category_tid';
  $handler->display->display_options['filters']['field_category_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_category_tid']['expose']['operator_id'] = 'field_category_tid_op';
  $handler->display->display_options['filters']['field_category_tid']['expose']['label'] = 'Category (field_category)';
  $handler->display->display_options['filters']['field_category_tid']['expose']['operator'] = 'field_category_tid_op';
  $handler->display->display_options['filters']['field_category_tid']['expose']['identifier'] = 'category';
  $handler->display->display_options['filters']['field_category_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  $handler->display->display_options['filters']['field_category_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_category_tid']['vocabulary'] = 'category';
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'node';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>=';
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'date_start';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Post date */
  $handler->display->display_options['filters']['created_1']['id'] = 'created_1';
  $handler->display->display_options['filters']['created_1']['table'] = 'node';
  $handler->display->display_options['filters']['created_1']['field'] = 'created';
  $handler->display->display_options['filters']['created_1']['operator'] = '<=';
  $handler->display->display_options['filters']['created_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created_1']['expose']['operator_id'] = 'created_1_op';
  $handler->display->display_options['filters']['created_1']['expose']['label'] = 'Post date';
  $handler->display->display_options['filters']['created_1']['expose']['operator'] = 'created_1_op';
  $handler->display->display_options['filters']['created_1']['expose']['identifier'] = 'date_end';
  $handler->display->display_options['filters']['created_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Body (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'allwords';
  $handler->display->display_options['filters']['body_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['body_value']['expose']['operator_id'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['label'] = 'Body (body)';
  $handler->display->display_options['filters']['body_value']['expose']['operator'] = 'body_value_op';
  $handler->display->display_options['filters']['body_value']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['body_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Publication (field_publication:issue) */
  $handler->display->display_options['filters']['field_publication_issue']['id'] = 'field_publication_issue';
  $handler->display->display_options['filters']['field_publication_issue']['table'] = 'field_data_field_publication';
  $handler->display->display_options['filters']['field_publication_issue']['field'] = 'field_publication_issue';
  $handler->display->display_options['filters']['field_publication_issue']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_issue']['expose']['operator_id'] = 'field_publication_issue_op';
  $handler->display->display_options['filters']['field_publication_issue']['expose']['label'] = 'Publication (field_publication:issue)';
  $handler->display->display_options['filters']['field_publication_issue']['expose']['operator'] = 'field_publication_issue_op';
  $handler->display->display_options['filters']['field_publication_issue']['expose']['identifier'] = 'issue';
  $handler->display->display_options['filters']['field_publication_issue']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Publication (field_publication:publication) */
  $handler->display->display_options['filters']['field_publication_publication']['id'] = 'field_publication_publication';
  $handler->display->display_options['filters']['field_publication_publication']['table'] = 'field_data_field_publication';
  $handler->display->display_options['filters']['field_publication_publication']['field'] = 'field_publication_publication';
  $handler->display->display_options['filters']['field_publication_publication']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_publication']['expose']['operator_id'] = 'field_publication_publication_op';
  $handler->display->display_options['filters']['field_publication_publication']['expose']['label'] = 'Publication (field_publication:publication)';
  $handler->display->display_options['filters']['field_publication_publication']['expose']['operator'] = 'field_publication_publication_op';
  $handler->display->display_options['filters']['field_publication_publication']['expose']['identifier'] = 'publication';
  $handler->display->display_options['filters']['field_publication_publication']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );
  /* Filter criterion: Content: Publication (field_publication:volume) */
  $handler->display->display_options['filters']['field_publication_volume']['id'] = 'field_publication_volume';
  $handler->display->display_options['filters']['field_publication_volume']['table'] = 'field_data_field_publication';
  $handler->display->display_options['filters']['field_publication_volume']['field'] = 'field_publication_volume';
  $handler->display->display_options['filters']['field_publication_volume']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_publication_volume']['expose']['operator_id'] = 'field_publication_volume_op';
  $handler->display->display_options['filters']['field_publication_volume']['expose']['label'] = 'Publication (field_publication:volume)';
  $handler->display->display_options['filters']['field_publication_volume']['expose']['operator'] = 'field_publication_volume_op';
  $handler->display->display_options['filters']['field_publication_volume']['expose']['identifier'] = 'volume';
  $handler->display->display_options['filters']['field_publication_volume']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    3 => 0,
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'content';
  $export['rest'] = $view;

  return $export;
}
