<?php

/**
 * @file
 * Election hooks for the Election FPTP module.
 */

/**
 * Implements hook_election_type_info().
 */
function election_fptp_election_type_info() {
  return array(
    'fptp' => array(
      'name' => t('FPTP election'),
      'description' => t('A First-past-the-post election: the candidate(s) with the greatest number of votes wins.'),
      'post name' => t('position'),
      'has candidates' => TRUE,
      'may anonymize' => TRUE,
      'vote form' => 'election_fptp_vote_form',
      'export' => TRUE,
    ),
  );
}
