<?php

/**
 * @file
 * Views integration for the Election Vote module.
 */

/**
 * Implements hook_views_data().
 */
function election_vote_views_data() {

  $data = array();

  $data['election_post']['vote_link'] = array(
    'field' => array(
      'title' => t('Vote link'),
      'help' => t('Provide a link to cast a vote for this post.'),
      'handler' => 'election_vote_views_handler_field_vote_link',
    ),
  );

  $data['election_post']['eligibility'] = array(
    'title' => t('Eligibility'),
    'help' => t('A detailed description of whether the current user is eligible to vote.'),
    'real field' => 'post_id',
    'field' => array(
      'handler' => 'election_vote_views_handler_field_eligibility',
      'click sortable' => FALSE,
    ),
  );

  $data['election_post']['eligibility_boolean'] = array(
    'title' => t('Eligible to vote?'),
    'help' => t('A Boolean (yes/no) for whether the current user is eligible to vote.'),
    'real field' => 'post_id',
    'field' => array(
      'handler' => 'election_vote_views_handler_field_eligibility_boolean',
      'click sortable' => TRUE,
    ),
  );

  $data['election_ballot'] = array(
    'table' => array(
      'base' => array(
        'field' => 'ballot_id',
        'title' => t('Election ballot'),
        'help' => t('The ballots table for the Election module. This records the act of voting, but the voting preferences themselves are in the table {election_vote}.'),
      ),
      'group' => 'Election ballot',
    ),
    'ballot_id' => array(
      'title' => t('Ballot ID'),
      'help' => t('Primary key: identifier for a ballot.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
    ),
    'election_id' => array(
      'title' => t('Election ID'),
      'help' => t('The election in which the ballot was cast. Relates to election.election_id.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_numeric',
      ),
      'argument' => array(
        'handler' => 'views_handler_argument_numeric',
      ),
    ),
    'post_id' => array(
      'title' => t('Post ID'),
      'help' => t('The post for which the ballot was cast. Relates to election_post.post_id.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
      'relationship' => array(
        'base' => 'election_post',
        'base field' => 'post_id',
        'handler' => 'views_handler_relationship',
        'label' => t('Election post information'),
        'title' => t('Election post information'),
        'help' => t('Fields from the election_post table about the post.'),
      ),
    ),
    'uid' => array(
      'title' => t('UID'),
      'help' => t('The users.uid of the voter.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
      'relationship' => array(
        'base' => 'users',
        'base field' => 'uid',
        'handler' => 'views_handler_relationship',
        'label' => t('Voter information'),
        'title' => t('Voter information'),
        'help' => t('Fields from the users table about the voter.'),
      ),
    ),
    'ip' => array(
      'title' => t('IP'),
      'help' => t('The IP address of the voter (v4 or v6).'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
    ),
    'agent' => array(
      'title' => t('User agent'),
      'help' => t('The HTTP user agent (browser identifier) of the voter.'),
      'field' => array(
        'handler' => 'views_handler_field',
      ),
    ),
    'sid_hash' => array(
      'title' => t('Session ID hash'),
      'help' => t("An MD5 hash of the voter's session ID (used for preventing duplicate anonymous votes)."),
      'field' => array(
        'handler' => 'views_handler_field',
        'click sortable' => FALSE,
      ),
    ),
    'timestamp' => array(
      'title' => t('Timestamp'),
      'help' => t('A UNIX timestamp for when the ballot was cast.'),
      'field' => array(
        'handler' => 'views_handler_field_date',
      ),
      'sort' => array(
        'handler' => 'views_handler_sort_date',
      ),
      'filter' => array(
        'handler' => 'views_handler_filter_date',
      ),
    ),
    'abstain' => array(
      'title' => t('Abstain'),
      'help' => t('Whether or not the voter abstained.'),
      'field' => array(
        'handler' => 'views_handler_field_boolean',
      ),
    ),
    'value' => array(
      'title' => t('Value'),
      'help' => t('The value of the ballot. If set to 0, the ballot will not be counted.'),
      'field' => array(
        'handler' => 'views_handler_field_numeric',
      ),
    ),
  );

  return $data;
}
