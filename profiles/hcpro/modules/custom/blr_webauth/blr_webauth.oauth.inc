<?php

class WebauthOAuth {
  private $clientId;
  private $secret;

  function __construct() {
    $this->clientId = variable_get('webauth_oauth_client_id');
    $this->secret = variable_get('webauth_oauth_secret');
  }

  public function getToken($refresh = false) {
    $cacheKey = 'blr_webauth_oauth_token';
    $path = 'oauth/v2/token?';
    $url = strpos($path, "http") === FALSE ? rtrim(variable_get('webauth_url'),'/') . '/' . $path : $path;

    if(!$refresh) {
      $token = cache_get($cacheKey);
      if($token && REQUEST_TIME < $token->expire)
        return $token->data;
    }

    $params = [
      'grant_type' => 'application_access',
      'client_id' => $this->clientId,
      'client_secret' => $this->secret,
    ];

    $options = [
      'method' => 'POST',
      'timeout' => 5,
      'max_redirects' => 0,
      'headers' => [
        'Accept' => 'application/json',
        'Content-Type' => 'application/x-www-form-urlencoded',
        'X-APPLICATION' => variable_get('webauth_app'),
      ]
    ];

    $response = drupal_http_request($url . http_build_query($params), $options);

    if($response->code < 200 || $response->code > 299) {
      watchdog('webauth', "Failed to get OAuth token from webauth service.", WATCHDOG_ERROR);
    } else {
      $result = json_decode($response->data, true);
    }

    if(!isset($result['access_token'])) {
      watchdog('webauth', 'Unable to authenticate with BLR service.');
      return FALSE;
    }

    cache_set($cacheKey, $result['access_token'], 'cache', REQUEST_TIME + $result['expires_in']);
    return $result['access_token'];
  }
}
