<?php

/**
 * @file
 * View listing candidates standing in an election, per election or per post.
 */

$view = new view();
$view->name = 'election_candidates';
$view->description = 'A list of candidates (intended for the public / all viewers of the election).';
$view->tag = 'election';
$view->base_table = 'election_candidate';
$view->human_name = 'Election candidates';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Candidates';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['access']['perm'] = 'view published elections';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['query']['options']['slave'] = TRUE;
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'candidate_category',
    'rendered' => 1,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['row_class'] = 'election-candidate-row clearfix';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
/* No results behavior: Global: Text area */
$handler->display->display_options['empty']['area']['id'] = 'area';
$handler->display->display_options['empty']['area']['table'] = 'views';
$handler->display->display_options['empty']['area']['field'] = 'area';
$handler->display->display_options['empty']['area']['label'] = 'No candidates found';
$handler->display->display_options['empty']['area']['content'] = 'No candidates found.';
$handler->display->display_options['empty']['area']['format'] = 'filtered_html';
/* Field: Election candidate: Candidate category */
$handler->display->display_options['fields']['candidate_category']['id'] = 'candidate_category';
$handler->display->display_options['fields']['candidate_category']['table'] = 'election_candidate';
$handler->display->display_options['fields']['candidate_category']['field'] = 'candidate_category';
$handler->display->display_options['fields']['candidate_category']['label'] = '';
$handler->display->display_options['fields']['candidate_category']['exclude'] = TRUE;
$handler->display->display_options['fields']['candidate_category']['element_label_colon'] = FALSE;
/* Field: Election candidate: Candidate ID */
$handler->display->display_options['fields']['candidate_id']['id'] = 'candidate_id';
$handler->display->display_options['fields']['candidate_id']['table'] = 'election_candidate';
$handler->display->display_options['fields']['candidate_id']['field'] = 'candidate_id';
$handler->display->display_options['fields']['candidate_id']['exclude'] = TRUE;
/* Field: Election candidate: Name */
$handler->display->display_options['fields']['candidate_name']['id'] = 'candidate_name';
$handler->display->display_options['fields']['candidate_name']['table'] = 'field_data_candidate_name';
$handler->display->display_options['fields']['candidate_name']['field'] = 'candidate_name';
$handler->display->display_options['fields']['candidate_name']['label'] = '';
$handler->display->display_options['fields']['candidate_name']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['candidate_name']['alter']['path'] = 'election-candidate/[candidate_id]';
$handler->display->display_options['fields']['candidate_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['candidate_name']['click_sort_column'] = 'title';
$handler->display->display_options['fields']['candidate_name']['settings'] = array(
  'format' => 'default',
  'markup' => 0,
  'output' => 'default',
  'multiple' => 'default',
  'multiple_delimiter' => ', ',
  'multiple_and' => 'text',
  'multiple_delimiter_precedes_last' => 'never',
  'multiple_el_al_min' => '3',
  'multiple_el_al_first' => '1',
);
/* Sort criterion: Election post: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'election_post';
$handler->display->display_options['sorts']['title']['field'] = 'title';
/* Sort criterion: Election candidate: Candidate category */
$handler->display->display_options['sorts']['candidate_category']['id'] = 'candidate_category';
$handler->display->display_options['sorts']['candidate_category']['table'] = 'election_candidate';
$handler->display->display_options['sorts']['candidate_category']['field'] = 'candidate_category';
/* Sort criterion: Global: Random */
$handler->display->display_options['sorts']['random']['id'] = 'random';
$handler->display->display_options['sorts']['random']['table'] = 'views';
$handler->display->display_options['sorts']['random']['field'] = 'random';
/* Contextual filter: Election: Election ID */
$handler->display->display_options['arguments']['election_id']['id'] = 'election_id';
$handler->display->display_options['arguments']['election_id']['table'] = 'election';
$handler->display->display_options['arguments']['election_id']['field'] = 'election_id';
$handler->display->display_options['arguments']['election_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['election_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['election_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['election_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['election_id']['specify_validation'] = TRUE;
$handler->display->display_options['arguments']['election_id']['validate']['type'] = 'numeric';
$handler->display->display_options['arguments']['election_id']['validate']['fail'] = 'empty';
/* Filter criterion: Election: Published or admin */
$handler->display->display_options['filters']['published_or_admin']['id'] = 'published_or_admin';
$handler->display->display_options['filters']['published_or_admin']['table'] = 'election';
$handler->display->display_options['filters']['published_or_admin']['field'] = 'published_or_admin';
$handler->display->display_options['filters']['published_or_admin']['group'] = 1;
/* Filter criterion: Election candidate: Published or admin */
$handler->display->display_options['filters']['published_or_admin_1']['id'] = 'published_or_admin_1';
$handler->display->display_options['filters']['published_or_admin_1']['table'] = 'election_candidate';
$handler->display->display_options['filters']['published_or_admin_1']['field'] = 'published_or_admin';
$handler->display->display_options['filters']['published_or_admin_1']['group'] = 1;
/* Filter criterion: Election candidate: Candidate status */
$handler->display->display_options['filters']['cstatus']['id'] = 'cstatus';
$handler->display->display_options['filters']['cstatus']['table'] = 'election_candidate';
$handler->display->display_options['filters']['cstatus']['field'] = 'cstatus';
$handler->display->display_options['filters']['cstatus']['operator'] = 'not in';
$handler->display->display_options['filters']['cstatus']['value'] = array(
  -2 => '-2',
);
$handler->display->display_options['filters']['cstatus']['group'] = 1;

/* Display: Candidates per election */
$handler = $view->new_display('embed', 'Candidates per election', 'embed_candidates_per_election');
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'list';
$handler->display->display_options['style_options']['grouping'] = array(
  0 => array(
    'field' => 'title',
    'rendered' => 0,
    'rendered_strip' => 0,
  ),
);
$handler->display->display_options['style_options']['row_class'] = 'election-candidate-row clearfix';
$handler->display->display_options['style_options']['default_row_class'] = FALSE;
$handler->display->display_options['style_options']['row_class_special'] = FALSE;
$handler->display->display_options['style_options']['uses_fields'] = TRUE;
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['row_plugin'] = 'fields';
$handler->display->display_options['row_options']['default_field_elements'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Election post: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'election_post';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Standing for';
$handler->display->display_options['fields']['title']['exclude'] = TRUE;
/* Field: Election candidate: Name */
$handler->display->display_options['fields']['candidate_name']['id'] = 'candidate_name';
$handler->display->display_options['fields']['candidate_name']['table'] = 'field_data_candidate_name';
$handler->display->display_options['fields']['candidate_name']['field'] = 'candidate_name';
$handler->display->display_options['fields']['candidate_name']['label'] = '';
$handler->display->display_options['fields']['candidate_name']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['candidate_name']['click_sort_column'] = 'title';
$handler->display->display_options['fields']['candidate_name']['settings'] = array(
  'format' => 'default',
  'markup' => 0,
  'output' => 'default',
  'multiple' => 'default',
  'multiple_delimiter' => ', ',
  'multiple_and' => 'text',
  'multiple_delimiter_precedes_last' => 'never',
  'multiple_el_al_min' => '3',
  'multiple_el_al_first' => '1',
);

/* Display: Candidates per post */
$handler = $view->new_display('embed', 'Candidates per post', 'embed_candidates_per_post');
$handler->display->display_options['defaults']['css_class'] = FALSE;
$handler->display->display_options['css_class'] = 'election-post-candidates';
$handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
$handler->display->display_options['defaults']['header'] = FALSE;
$handler->display->display_options['defaults']['empty'] = FALSE;
$handler->display->display_options['defaults']['arguments'] = FALSE;
/* Contextual filter: Election post: Post ID */
$handler->display->display_options['arguments']['post_id']['id'] = 'post_id';
$handler->display->display_options['arguments']['post_id']['table'] = 'election_post';
$handler->display->display_options['arguments']['post_id']['field'] = 'post_id';
$handler->display->display_options['arguments']['post_id']['default_action'] = 'empty';
$handler->display->display_options['arguments']['post_id']['default_argument_type'] = 'fixed';
$handler->display->display_options['arguments']['post_id']['summary']['number_of_records'] = '0';
$handler->display->display_options['arguments']['post_id']['summary']['format'] = 'default_summary';
$handler->display->display_options['arguments']['post_id']['summary_options']['items_per_page'] = '25';
$handler->display->display_options['arguments']['post_id']['validate']['type'] = 'numeric';
$handler->display->display_options['arguments']['post_id']['validate']['fail'] = 'empty';

$views[$view->name] = $view;
