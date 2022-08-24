<?php

function blr_webauth_user_profile_page() {
  global $user;
  drupal_set_title("Your Account Information");
  $profile = blr_webauth_get_profile();

  $profile['membership tier'] = $user->roles;
  unset($profile['membership tier'][2]);
  $profile['membership tier'] = ucwords(implode(', ', $profile['membership tier']));

  return theme('mbprofile',['profile'=>$profile]);
}

