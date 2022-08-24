<?php
/**
 * @file
 * wistia_radio.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function wistia_radio_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-radio-field_video_url'.
  $field_instances['node-radio-field_video_url'] = array(
    'bundle' => 'radio',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Must be in this format with the ID at the end: https://hrhero.wistia.com/medias/cap8k8i4kd',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 6,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'node',
    'field_name' => 'field_video_url',
    'label' => 'Video URL',
    'required' => 1,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 120,
      ),
      'enable_tokens' => 1,
      'rel_remove' => 'default',
      'title' => 'none',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Video URL');

  return $field_instances;
}
