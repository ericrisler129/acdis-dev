<?php

/**
 * @file
 * API documentation file.
 *
 * This file contains no working PHP code; it exists to provide additional
 * documentation for doxygen as well as to document hooks in the standard
 * Drupal manner.
 */

/**
 * Defines election types.
 *
 * Default election types are provided by the election_stv and
 * election_referendum sub-modules. Other types can be provided using this hook.
 * Information about existing election types is loaded via the election_types()
 * function.
 *
 * For working examples, see:
 *   election_types/referendum/election_referendum.election.inc
 *   election_types/stv/election_stv.election.inc
 *
 * @return array
 *   An array of election type arrays, keyed by a unique machine name. Election
 *   type arrays can include:
 *   - name: (Required) The human-readable name of the election type, sanitized.
 *   - description: A description of the election type, sanitized.
 *   - post name: The name of the election's posts, as a singular noun. See
 *     README.txt. The name for a referendum's posts may be 'question', while
 *     another election's posts may be referred to as 'role', 'position', or
 *     'title', perhaps.
 *   - post name plural: The plural version of the post name (default: post name
 *     + s).
 *   - has candidates: Whether the election type has candidates. Modules
 *     providing elections that have candidates should depend on the
 *     election_candidate submodule.
 *   - vote form: The name of a callback altering the voting form. This option
 *     is provided as a more convenient alternative to hook_form_FORM_ID_alter()
 *     to avoid complications with confirm form logic.
 *     The function takes the parameters:
 *         array $form        - The form array from election_vote_form().
 *         array $form_state  - The form_state array from election_vote_form().
 *   - export: Whether the election results can be exported as an archive of
 *     ballot (.blt) files. This needs the election_export submodule.
 *
 * @see election_types()
 */
function hook_election_type_info() {
  return array(
    'fptp' => array(
      'name' => t('FPTP election'),
      'description' => t('A first-past-the-post election type, where voters can select a single candidate who wins based on a simple majority with a quorum.'),
      'post name' => t('position'),
      'has candidates' => TRUE,
      'export' => TRUE,
      'vote form' => 'election_fptp_vote_form',
    ),
  );
}

/**
 * Alter existing election types.
 *
 * @param array $types
 *   An array of election types.
 *
 * @see hook_election_type_info()
 */
function hook_election_type_info_alter(array &$types) {
  // Example: alter the referendum election type to enable exporting.
  if (isset($types['referendum'])) {
    $types['referendum']['export'] = TRUE;
  }
}

/**
 * Runs when nominations opens.
 *
 * For scheduled changes, this hook will run only if election_cron module is
 * enabled. It will run the next time cron runs after the scheduled time.
 *
 * @param int $election_id
 *   The election ID.
 * @param bool $scheduled
 *   TRUE if a scheduled change, FALSE if manual.
 */
function hook_election_nominations_open($election_id, $scheduled) {
  watchdog('election', 'Nominations opened @how for @type %title (@id).', array(
    '@how' => $scheduled ? 'by schedule' : 'manually',
    '@type' => $election->type_info['name'],
    '%title' => $election->title,
    '@id' => $election->election_id,
  ));
}

/**
 * Runs when nominations closes.
 *
 * For scheduled changes, this hook will run only if election_cron module is
 * enabled. It will run the next time cron runs after the scheduled time.
 *
 * @param int $election_id
 *   The election ID.
 * @param bool $scheduled
 *   TRUE if a scheduled change, FALSE if manual.
 */
function hook_election_nominations_close($election_id, $scheduled) {
  watchdog('election', 'Nominations closed @how for @type %title (@id).', array(
    '@how' => $scheduled ? 'by schedule' : 'manually',
    '@type' => $election->type_info['name'],
    '%title' => $election->title,
    '@id' => $election->election_id,
  ));
}

/**
 * Runs when voting opens.
 *
 * For scheduled changes, this hook will run only if election_cron module is
 * enabled. It will run the next time cron runs after the scheduled time.
 *
 * @param int $election_id
 *   The election ID.
 * @param bool $scheduled
 *   TRUE if a scheduled change, FALSE if manual.
 */
function hook_election_voting_open($election_id, $scheduled) {
  watchdog('election', 'Voting opened @how for @type %title (@id).', array(
    '@how' => $scheduled ? 'by schedule' : 'manually',
    '@type' => $election->type_info['name'],
    '%title' => $election->title,
    '@id' => $election->election_id,
  ));
}

/**
 * Runs when voting closes.
 *
 * For scheduled changes, this hook will run only if election_cron module is
 * enabled. It will run the next time cron runs after the scheduled time.
 *
 * @param int $election_id
 *   The election ID.
 * @param bool $scheduled
 *   TRUE if a scheduled change, FALSE if manual.
 */
function hook_election_voting_close($election_id, $scheduled) {
  watchdog('election', 'Voting closed @how for @type %title (@id).', array(
    '@how' => $scheduled ? 'by schedule' : 'manually',
    '@type' => $election->type_info['name'],
    '%title' => $election->title,
    '@id' => $election->election_id,
  ));
}
