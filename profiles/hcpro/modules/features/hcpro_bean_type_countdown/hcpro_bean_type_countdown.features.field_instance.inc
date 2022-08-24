<?php
/**
 * @file
 * hcpro_bean_type_countdown.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function hcpro_bean_type_countdown_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-countdown-field_countdown_description'.
  $field_instances['bean-countdown-field_countdown_description'] = array(
    'bundle' => 'countdown',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_countdown_description',
    'label' => 'Countdown Description',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 3,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'bean-countdown-field_date'.
  $field_instances['bean-countdown-field_date'] = array(
    'bundle' => 'countdown',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'countdown',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => 0,
        ),
        'type' => 'date_default',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => 'theme_ds_field_minimal',
    'entity_type' => 'bean',
    'field_name' => 'field_date',
    'label' => 'Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 30,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-0:+3',
      ),
      'type' => 'date_popup',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'bean-countdown-field_generic_link'.
  $field_instances['bean-countdown-field_generic_link'] = array(
    'bundle' => 'countdown',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'bean',
    'field_name' => 'field_generic_link',
    'label' => 'Generic Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 0,
      'attributes' => array(
        'class' => 'button-grey',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => 'nofollow',
        'target' => 'user',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => '',
      ),
      'enable_tokens' => 0,
      'rel_remove' => 'rel_remove_internal',
      'title' => 'value',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => 'More Information',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Countdown Description');
  t('Date');
  t('Generic Link');

  return $field_instances;
}
