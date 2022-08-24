<?php
/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function hcpro_form_install_configure_form_alter(&$form, $form_state) {
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
  $form['admin_account']['account']['name']['#default_value'] = 'admin';
  $form['server_settings']['site_default_country']['#default_value'] = 'US';
  $form['server_settings']['date_default_timezone']['#default_value'] = 'America/Los_Angeles';
  $form['update_notifications']['update_status_module']['#default_value'][0] = FALSE;
  $form['update_notifications']['update_status_module']['#default_value'][1] = FALSE;

  if (valid_email_address('noreply@' . $_SERVER['HTTP_HOST'])) {
    $form['site_information']['site_mail']['#default_value'] = 'noreply@' . $_SERVER['HTTP_HOST'];
  }
}

/**
 * Set's the default site theme.
 */
function hcpro_set_themes()
{
  $main_theme = 'hcprobt';
  $admin_theme = 'seven';
  theme_enable(array($main_theme));
  // Set default theme
  variable_set('theme_default', $main_theme);
  // Set admin theme
  variable_set('admin_theme', $admin_theme);
  // Use admin theme for content editing
  variable_set('node_admin_theme', 1);
}

/**
 * Set the weight of the homepage link in the main menu so that all other
 * items created get created such that they are weighted heavier.
 */
function hcpro_set_home_link_weight() {
  $links = menu_load_links('main-menu');
  foreach ($links as $item) {
    if ($item['link_path'] == '<front>') {
      $item['weight'] = -50;
      menu_link_save($item);
    }
  }
}
