<?php
/**
 * @file
 * hcpro_content_type_masthead.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function hcpro_content_type_masthead_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'masthead';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Masthead';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Masthead';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['optionset'] = 'masthead';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Slides (field_slides) */
  $handler->display->display_options['relationships']['field_slides_value']['id'] = 'field_slides_value';
  $handler->display->display_options['relationships']['field_slides_value']['table'] = 'field_data_field_slides';
  $handler->display->display_options['relationships']['field_slides_value']['field'] = 'field_slides_value';
  $handler->display->display_options['relationships']['field_slides_value']['required'] = TRUE;
  $handler->display->display_options['relationships']['field_slides_value']['delta'] = '-1';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_masthead_node']['id'] = 'reverse_field_masthead_node';
  $handler->display->display_options['relationships']['reverse_field_masthead_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_masthead_node']['field'] = 'reverse_field_masthead_node';
  /* Field: Field collection item: Rendered Field collection item */
  $handler->display->display_options['fields']['rendered_entity']['id'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['table'] = 'views_entity_field_collection_item';
  $handler->display->display_options['fields']['rendered_entity']['field'] = 'rendered_entity';
  $handler->display->display_options['fields']['rendered_entity']['relationship'] = 'field_slides_value';
  $handler->display->display_options['fields']['rendered_entity']['label'] = '';
  $handler->display->display_options['fields']['rendered_entity']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['rendered_entity']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['rendered_entity']['display'] = 'view';
  $handler->display->display_options['fields']['rendered_entity']['view_mode'] = 'full';
  $handler->display->display_options['fields']['rendered_entity']['bypass_access'] = 0;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'reverse_field_masthead_node';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
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
    'masthead' => 'masthead',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $export['masthead'] = $view;

  return $export;
}
