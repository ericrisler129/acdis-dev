<?php

/**
 * DEBUG token for development environments
 * This will enable additional debug output by the theme and is used in the theme's `template.php` file. This is enabled by default and should be disabled from staging and production environments.
**/
$conf['use_debug_theme'] = TRUE;

/**
 * For a single database configuration, the following is sufficient:
**/
$databases['default']['default'] = array(
  'driver' => 'mysql',
  'database' => 'databasename',
  'username' => 'username',
  'password' => 'password',
  'host' => 'localhost',
  'prefix' => 'main_',
  'collation' => 'utf8_general_ci',
);
