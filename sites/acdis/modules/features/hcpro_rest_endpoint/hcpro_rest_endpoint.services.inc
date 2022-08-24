<?php
/**
 * @file
 * hcpro_rest_endpoint.services.inc
 */

/**
 * Implements hook_default_services_endpoint().
 */
function hcpro_rest_endpoint_default_services_endpoint() {
  $export = array();

  $endpoint = new stdClass();
  $endpoint->disabled = FALSE; /* Edit this to true to make a default endpoint disabled initially */
  $endpoint->api_version = 3;
  $endpoint->name = 'rest';
  $endpoint->server = 'rest_server';
  $endpoint->path = 'rest';
  $endpoint->authentication = array();
  $endpoint->server_settings = array(
    'formatters' => array(
      'json' => TRUE,
      'bencode' => FALSE,
      'jsonp' => FALSE,
      'php' => FALSE,
      'xml' => FALSE,
    ),
    'parsers' => array(
      'application/json' => TRUE,
      'application/vnd.php.serialized' => TRUE,
      'application/xml' => TRUE,
      'multipart/form-data' => TRUE,
      'text/xml' => TRUE,
      'application/x-www-form-urlencoded' => FALSE,
    ),
  );
  $endpoint->resources = array(
    'content' => array(
      'operations' => array(
        'index' => array(
          'enabled' => '1',
        ),
      ),
    ),
  );
  $endpoint->debug = 0;
  $export['rest'] = $endpoint;

  return $export;
}
