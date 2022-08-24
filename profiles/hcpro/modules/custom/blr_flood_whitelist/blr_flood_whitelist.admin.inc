<?php

/**
 * @file
 * Callback for the BLR Flood Whitelist module.
 */

/**
 * Page callback for the BLR Flood Whitelist admin page
 * @return mixed
 */
function blr_flood_whitelist_page() {
  $rows = array();
  $header = array(t('whitelisted IP addresses'), t('Operations'));
  $ip_list = blr_flood_whitelist_get_ip_list();
  foreach ($ip_list as $ip) {
    $rows[] = array(
      str_replace('-', ' - ',$ip->ip),
      l(t('delete'), "admin/config/people/flood-whitelist/delete/$ip->id/$ip->ip"),
    );
  }

  $build['_blr_flood_whitelist_settings_form'] = drupal_get_form('_blr_flood_whitelist_settings_form');

  $build['whitelist_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}

/**
 * Settings page form callback
 *
 * @return array
 */
function _blr_flood_whitelist_settings_form() {
  $form = array();

  $form['ip_start'] = array(
    '#title' => t('IP address'),
    '#type' => 'textfield',
    '#size' => 30,
    '#required' => TRUE,
    '#maxlength' => 15,
    '#description' => t('Enter IP-address (100.100.100.100). If range end is specified, it will be used as start of the range, otherwise as a single IP-address.'),
  );
  $form['ip_end'] = array(
    '#title' => t('IP range end (optional)'),
    '#type' => 'textfield',
    '#size' => 30,
    '#required' => FALSE,
    '#maxlength' => 15,
    '#description' => t('If entered, the whitelisted ip will be treated as a range.'),
  );

  $form['actions'] = array('#type' => 'actions');
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Add'),
  );

  $form['#validate'][] = '_blr_flood_whitelist_settings_validate';
  $form['#submit'][] = '_blr_flood_whitelist_settings_submit';
  return $form;
}

/**
 * Settings form validation callback
 *
 * @param $form
 * @param $form_state
 */
function _blr_flood_whitelist_settings_validate($form, &$form_state) {
  $ip_start = trim($form_state['values']['ip_start']);
  $ip_end = isset($form_state['values']['ip_end']) ? trim($form_state['values']['ip_end']) : FALSE;
  if (filter_var($ip_start, FILTER_VALIDATE_IP, FILTER_FLAG_NO_RES_RANGE) == FALSE) {
    form_set_error('ip_start', t("This is not a valid IP address."));
  }
  elseif ($ip_end && filter_var($ip_end, FILTER_VALIDATE_IP, FILTER_FLAG_NO_RES_RANGE) == FALSE) {
    form_set_error('ip_end', t("This is not a valid IP address."));
  }
}

/**
 * Settings form submit callback
 *
 * @param $form
 * @param $form_state
 */
function _blr_flood_whitelist_settings_submit($form, &$form_state) {
  $ip_start = trim($form_state['values']['ip_start']);
  $ip_start = preg_replace('/\s+/', '', $ip_start);
  $ip = $ip_start;

  if ($form_state['values']['ip_end']) {
    $ip_end = trim($form_state['values']['ip_end']);
    $ip_end = preg_replace('/\s+/', '', $ip_end);
    $ip.='-'.$ip_end;
  }

  db_insert('flood_ip_whitelist')
    ->fields(array('ip' => $ip))
    ->execute();

  drupal_set_message(t('The IP address %ip has been whitelisted.', array('%ip' => $ip)));
  $form_state['redirect'] = 'admin/config/people/flood-whitelist';
  return;
}

/**
 * Settings form delete entry confirm callback
 *
 * @param $form
 * @param $form_state
 * @param $id
 * @param $ip
 * @return mixed
 */
function _blr_flood_whitelist_delete($form, &$form_state, $id, $ip) {
  $form['ip_range'] = array(
    '#type' => 'value',
    '#value' => $id,
  );
  return confirm_form($form, t('Are you sure you want to delete ip/range %ip?', array('%ip' => str_replace('-',' - ',$ip))), 'admin/config/people/flood-whitelist', t('This action cannot be undone.'), t('Delete'), t('Cancel'));
}

/**
 * Settings form delete entry submit callback
 *
 * @param $form
 * @param $form_state
 */
function _blr_flood_whitelist_delete_submit($form, &$form_state) {
  $ip = $form_state['build_info']['args']['1'];
  $id = $form_state['values']['ip_range'];
  db_delete('flood_ip_whitelist')
    ->condition('id', $id)
    ->execute();
  watchdog('user', 'Deleted %ip from whitelist', array('%ip' => $ip));
  drupal_set_message(t('The IP address/range %ip was deleted.', array('%ip' => str_replace('-',' - ',$ip))));
  $form_state['redirect'] = 'admin/config/people/flood-whitelist';
}
