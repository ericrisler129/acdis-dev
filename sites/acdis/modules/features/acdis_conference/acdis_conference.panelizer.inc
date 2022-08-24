<?php
/**
 * @file
 * acdis_conference.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function acdis_conference_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->name = 'node:conference:default';
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'conference';
  $panelizer->no_blocks = FALSE;
  $panelizer->css_id = '';
  $panelizer->css = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->css_class = '';
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f0f636bd-2963-4639-9f8f-a53c9701abaf';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-9173894b-478f-4661-a00d-dc3f95cba538';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9173894b-478f-4661-a00d-dc3f95cba538';
    $display->content['new-9173894b-478f-4661-a00d-dc3f95cba538'] = $pane;
    $display->panels['center'][0] = 'new-9173894b-478f-4661-a00d-dc3f95cba538';
    $pane = new stdClass();
    $pane->pid = 'new-87c55d0e-13ef-4d89-a36c-61525d12b4cb';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_exclusive_sponsor';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '87c55d0e-13ef-4d89-a36c-61525d12b4cb';
    $display->content['new-87c55d0e-13ef-4d89-a36c-61525d12b4cb'] = $pane;
    $display->panels['center'][1] = 'new-87c55d0e-13ef-4d89-a36c-61525d12b4cb';
    $pane = new stdClass();
    $pane->pid = 'new-6a40f5c4-f6da-470a-aee9-77133c41de17';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_platinum_sponsors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6a40f5c4-f6da-470a-aee9-77133c41de17';
    $display->content['new-6a40f5c4-f6da-470a-aee9-77133c41de17'] = $pane;
    $display->panels['center'][2] = 'new-6a40f5c4-f6da-470a-aee9-77133c41de17';
    $pane = new stdClass();
    $pane->pid = 'new-56cc9c3d-9c0d-4df5-88bf-74139714b5c6';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_masthead';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '56cc9c3d-9c0d-4df5-88bf-74139714b5c6';
    $display->content['new-56cc9c3d-9c0d-4df5-88bf-74139714b5c6'] = $pane;
    $display->panels['center'][3] = 'new-56cc9c3d-9c0d-4df5-88bf-74139714b5c6';
    $pane = new stdClass();
    $pane->pid = 'new-65cd5b88-fb99-4a25-985e-ed772cdd0c52';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_welcome_sponsors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '65cd5b88-fb99-4a25-985e-ed772cdd0c52';
    $display->content['new-65cd5b88-fb99-4a25-985e-ed772cdd0c52'] = $pane;
    $display->panels['center'][4] = 'new-65cd5b88-fb99-4a25-985e-ed772cdd0c52';
    $pane = new stdClass();
    $pane->pid = 'new-2fd539ad-2013-4223-b684-53e1dd08dbb8';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_exhibitors';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'entityreference_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'link' => FALSE,
      ),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2fd539ad-2013-4223-b684-53e1dd08dbb8';
    $display->content['new-2fd539ad-2013-4223-b684-53e1dd08dbb8'] = $pane;
    $display->panels['center'][5] = 'new-2fd539ad-2013-4223-b684-53e1dd08dbb8';
    $pane = new stdClass();
    $pane->pid = 'new-ab488bcc-8c73-4daf-91e7-554970430ac6';
    $pane->panel = 'center';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_file_download';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'file_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ab488bcc-8c73-4daf-91e7-554970430ac6';
    $display->content['new-ab488bcc-8c73-4daf-91e7-554970430ac6'] = $pane;
    $display->panels['center'][6] = 'new-ab488bcc-8c73-4daf-91e7-554970430ac6';
    $pane = new stdClass();
    $pane->pid = 'new-169ffef5-9166-443d-878f-29652ff5313e';
    $pane->panel = 'center';
    $pane->type = 'node_links';
    $pane->subtype = 'node_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => FALSE,
      'override_title_text' => '',
      'build_mode' => 'page_manager',
      'identifier' => '',
      'link' => TRUE,
      'context' => 'panelizer',
    );
    $pane->cache = array();
    $pane->style = array();
    $pane->css = array(
      'css_class' => 'link-wrapper',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '169ffef5-9166-443d-878f-29652ff5313e';
    $display->content['new-169ffef5-9166-443d-878f-29652ff5313e'] = $pane;
    $display->panels['center'][7] = 'new-169ffef5-9166-443d-878f-29652ff5313e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-169ffef5-9166-443d-878f-29652ff5313e';
  $panelizer->display = $display;
  $export['node:conference:default'] = $panelizer;

  return $export;
}
