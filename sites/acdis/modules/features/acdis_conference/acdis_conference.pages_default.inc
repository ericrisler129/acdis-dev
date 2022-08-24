<?php
/**
 * @file
 * acdis_conference.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function acdis_conference_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'conference';
  $page->task = 'page';
  $page->admin_title = 'Conference';
  $page->admin_description = '';
  $page->path = 'conference/%title/%nid/!page';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array(
    'title' => array(
      'id' => 1,
      'identifier' => 'Title',
      'name' => 'string',
      'settings' => array(
        'use_tail' => 0,
      ),
    ),
    'nid' => array(
      'id' => 1,
      'identifier' => 'Content: ID',
      'name' => 'entity_id:node',
      'settings' => array(),
    ),
    'page' => array(
      'settings' => array(),
      'identifier' => 'No context',
    ),
  );
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_conference__panel';
  $handler->task = 'page';
  $handler->subtask = 'conference';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Sponsors',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => '*/sponsors',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'top' => NULL,
      'left' => NULL,
      'right' => NULL,
      'bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7f0c1584-70d0-4c16-ba66-dc5d53f9dc4e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-cb2c679d-29a0-49d4-a0dd-8310341b6920';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_exclusive_sponsor';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
        'links' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Exclusive Title Sponsor',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sponsor-grid standard-block',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'cb2c679d-29a0-49d4-a0dd-8310341b6920';
    $display->content['new-cb2c679d-29a0-49d4-a0dd-8310341b6920'] = $pane;
    $display->panels['middle'][0] = 'new-cb2c679d-29a0-49d4-a0dd-8310341b6920';
    $pane = new stdClass();
    $pane->pid = 'new-77ffb65a-515c-4bd3-a203-458ea2999224';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_platinum_sponsors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
        'links' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sponsor-grid standard-block',
    );
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '77ffb65a-515c-4bd3-a203-458ea2999224';
    $display->content['new-77ffb65a-515c-4bd3-a203-458ea2999224'] = $pane;
    $display->panels['middle'][1] = 'new-77ffb65a-515c-4bd3-a203-458ea2999224';
    $pane = new stdClass();
    $pane->pid = 'new-6a4fb8cc-3b29-4ed0-bf48-fa2348ea766f';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_welcome_sponsors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
        'links' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Welcome Sponsor',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sponsor-grid standard-block',
    );
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6a4fb8cc-3b29-4ed0-bf48-fa2348ea766f';
    $display->content['new-6a4fb8cc-3b29-4ed0-bf48-fa2348ea766f'] = $pane;
    $display->panels['middle'][2] = 'new-6a4fb8cc-3b29-4ed0-bf48-fa2348ea766f';
    $pane = new stdClass();
    $pane->pid = 'new-a9bf48af-0a08-4de6-81af-4d1b6ed81b36';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_exhibitors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'view_mode' => 'teaser',
        'links' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
      'style' => 'block',
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'sponsor-grid standard-block',
    );
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a9bf48af-0a08-4de6-81af-4d1b6ed81b36';
    $display->content['new-a9bf48af-0a08-4de6-81af-4d1b6ed81b36'] = $pane;
    $display->panels['middle'][3] = 'new-a9bf48af-0a08-4de6-81af-4d1b6ed81b36';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-77ffb65a-515c-4bd3-a203-458ea2999224';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['conference'] = $page;

  return $pages;

}
