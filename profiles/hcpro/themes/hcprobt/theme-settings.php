<?php

/**
 * @file
 * Theme settings file for the hcprobt theme.
 */

require_once dirname(__FILE__) . '/template.php';

/**
 * Implements hook_form_FORM_alter().
 */
function hcprobt_form_system_theme_settings_alter(&$form, $form_state) {
  $form['hcpro_copyright'] = array(
    '#type'          => 'textfield',
    '#title'         => t('HCPro Copyright'),
    '#default_value' => theme_get_setting('hcpro_copyright'),
    '#description'   => t("Sitewide footer copyright"),
  );
}
