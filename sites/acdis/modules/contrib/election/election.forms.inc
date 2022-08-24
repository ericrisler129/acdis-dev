<?php

/**
 * @file
 * Form functions for the Election module.
 */

/**
 * Form builder function for adding or editing an election.
 */
function election_form($form, &$form_state, stdClass $election) {

  $form['#id'] = 'election-form';
  $form['#election'] = $election;

  $form_state['election'] = $election;

  $form['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#maxlength' => 255,
    '#default_value' => isset($election->title) ? $election->title : '',
    '#required' => TRUE,
  );

  $date_format = variable_get('date_format_short', 'Y-m-d H:i');
  if (module_exists('date_popup')) {
    $date_widget = 'date_popup';
  }
  else {
    $date_widget = 'date_text';
  }

  if (!isset($election->type_info)) {
    $election->type_info = _election_type_get_info($election->type);
  }
  if (!empty($election->type_info['has candidates'])) {
    $form['nominations'] = array(
      '#type' => 'fieldset',
      '#title' => t('Nominations'),
      '#collapsible' => TRUE,
    );
    $nopen_default = isset($election->nopen_time) ? $election->nopen_time : NULL;
    $nclose_default = isset($election->nclose_time) ? $election->nclose_time : NULL;
    $form['nominations']['nstatus'] = array(
      '#type' => 'select',
      '#title' => t('Nominations status'),
      '#default_value' => isset($election->nstatus) ? $election->nstatus : ELECTION_STATUS_CLOSED,
      '#options' => election_status_options(),
    );
    $form['nominations']['nschedule'] = array(
      '#title' => t('Nominations schedule'),
      '#type' => 'fieldset',
      '#description' => t('Set the opening and closing times for nominations.'),
      '#states' => array(
        'visible' => array(
          ':input[name=nstatus]' => array('value' => (string) ELECTION_STATUS_SCHEDULED),
        ),
      ),
    );
    $form['nominations']['nschedule']['nopen_time'] = array(
      '#title' => t('Opening time'),
      '#type' => $date_widget,
      '#default_value' => $nopen_default ? date('Y-m-d H:i:s', $nopen_default) : NULL,
      '#date_format' => $date_format,
      '#date_year_range' => '-2:+5',
    );
    $form['nominations']['nschedule']['nclose_time'] = array(
      '#title' => t('Closing time'),
      '#type' => $date_widget,
      '#default_value' => $nclose_default ? date('Y-m-d H:i:s', $nclose_default) : NULL,
      '#date_format' => $date_format,
      '#date_year_range' => '-2:+5',
    );
  }

  $vopen_default = isset($election->vopen_time) ? $election->vopen_time : NULL;
  $vclose_default = isset($election->vclose_time) ? $election->vclose_time : NULL;

  $form['voting'] = array(
    '#type' => 'fieldset',
    '#title' => t('Voting'),
    '#collapsible' => TRUE,
  );
  $form['voting']['vstatus'] = array(
    '#type' => 'select',
    '#title' => t('Voting status'),
    '#default_value' => isset($election->vstatus) ? $election->vstatus : ELECTION_STATUS_CLOSED,
    '#options' => election_status_options(),
  );

  $messages = _election_check_election_readiness($election);
  if ($messages) {
    $form['voting']['vstatus']['#description'] = '<div class="messages warning">' . theme('item_list', array('items' => $messages)) . '</div>';
  }

  $form['voting']['vschedule'] = array(
    '#title' => t('Voting schedule'),
    '#type' => 'fieldset',
    '#description' => t('Set the opening and closing times for voting.'),
    '#states' => array(
      'visible' => array(
        ':input[name=vstatus]' => array('value' => (string) ELECTION_STATUS_SCHEDULED),
      ),
    ),
  );
  if (!empty($election->type_info['may anonymize'])) {
    $form['voting']['settings_anonymize'] = array(
      '#type' => 'checkbox',
      '#title' => t('Anonymize voting (extra secret mode)'),
      '#description' => t('If enabled, votes will be completely anonymized in the database. The undo and export features will not be available.'),
      '#default_value' => !empty($election->settings['anonymize']),
    );
  }
  $form['voting']['vschedule']['vopen_time'] = array(
    '#title' => t('Opening time'),
    '#type' => $date_widget,
    '#default_value' => $vopen_default ? date('Y-m-d H:i:s', $vopen_default) : NULL,
    '#date_format' => $date_format,
    '#date_year_range' => '-2:+5',
  );
  $form['voting']['vschedule']['vclose_time'] = array(
    '#title' => t('Closing time'),
    '#type' => $date_widget,
    '#default_value' => $vclose_default ? date('Y-m-d H:i:s', $vclose_default) : NULL,
    '#date_format' => $date_format,
    '#date_year_range' => '-2:+5',
  );

  $form['published'] = array(
    '#type' => 'checkbox',
    '#title' => t('Published'),
    '#default_value' => isset($election->published) ? $election->published : 0,
    '#weight' => 99,
    '#description' => t("This allows those with the '!perm' permission to view the election.", array(
      '!perm' => t('View published elections'),
    )),
  );

  $form['buttons'] = array(
    '#type' => 'actions',
    '#weight' => 100,
  );
  $form['buttons']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save'),
    '#submit' => array('election_form_submit'),
  );

  if (!empty($election->election_id)) {
    $form['buttons']['delete'] = array(
      '#type' => 'submit',
      '#value' => t('Delete'),
      '#submit' => array('election_form_delete_submit'),
      '#access' => entity_access('delete', 'election', $election),
    );
  }

  $cancel_path = empty($election->election_id) ? 'elections' : election_uri_path($election);
  if (!empty($_GET['destination'])) {
    $options = drupal_parse_url($_GET['destination']);
    $cancel_path = $options['path'];
  }
  $form['buttons']['cancel'] = array(
    '#type' => 'link',
    '#title' => t('Cancel'),
    '#href' => $cancel_path,
  );

  form_load_include($form_state, 'inc', 'election', 'election.forms');
  $form['#validate'][] = 'election_form_validate';

  // Add custom fields from the Field system.
  field_attach_form('election', $election, $form, $form_state);

  return $form;

}

/**
 * Checks if a vote is ready to be published.
 *
 * @param object $election
 *   The election object.
 *
 * @return array
 *   An array of error messages. Empty array means the vote is ready.
 */
function _election_check_election_readiness(stdClass $election) {
  $messages = array();

  // Election is published.
  if (empty($election->published)) {
    $args = array(
      '@type' => $election->type_info['name'],
    );
    $messages[] = t('This @type is not published.', $args);
  }

  // Other checks are not possible before the election has an election_id.
  if (!$election->election_id) {
    return $messages;
  }

  // Election posts are published.
  $query = 'SELECT TRUE
    FROM {election_post}
    WHERE election_id = :election_id
      AND published = 0';
  $args = array('election_id' => $election->election_id);
  $results = db_query($query, $args);
  if ($results->fetchField()) {
    $args = array(
      '@type' => $election->type_info['name'],
      '@url' => url('election/' . $election->election_id . '/posts-admin', array('query' => array('published' => 0))),
      '@post_type' => $election->type_info['post name'],
    );
    $messages[] = t('This @type contains <a href="@url">at least one @post_type</a> that is not published.', $args);
  }

  if (!empty($election->type_info['has candidates'])) {
    // Candidates are published.
    $query = 'SELECT TRUE
      FROM {election_post} ep
        JOIN {election_candidate} ec USING (post_id)
      WHERE ep.election_id = :election_id
        AND ec.published = 0';
    $args = array('election_id' => $election->election_id);
    $results = db_query($query, $args);
    if ($results->fetchField()) {
      $args = array(
        '@type' => $election->type_info['name'],
        '@url' => url('election/' . $election->election_id . '/candidates-admin', array('query' => array('published' => 0))),
      );
      $messages[] = t('This @type contains <a href="@url">at least one candidate</a> that is not published.', $args);
    }

    // Posts have enough candidates.
    $query = 'SELECT * FROM (
        SELECT post_id, title, vacancy_count, count(candidate_id) AS count
        FROM {election_post} ep
          LEFT JOIN {election_candidate} ec USING (post_id)
        WHERE ep.election_id = :election_id
        GROUP BY post_id, title, vacancy_count
      ) sub
      WHERE count <= vacancy_count';
    $args = array('election_id' => $election->election_id);
    $results = db_query($query, $args)->fetchAll();
    if ($results) {
      // Link to all posts without enough candidates.
      $posts = array();
      foreach ($results as $post) {
        $posts[] = l($post->title, 'election-post/' . $post->post_id);
      }

      $args = array(
        '@type' => $election->type_info['name'],
        '@post_type' => $election->type_info['post name'],
      );
      $messages[] = array(
        'data' => format_plural(count($posts), 'This @type contains a @post_type without enough candidates:', 'This @type contains more than one @post_type without enough candidates:', $args),
        'children' => $posts,
      );
    }
  }

  return $messages;
}

/**
 * Form validate function for the form election_form.
 */
function election_form_validate($form, &$form_state) {

  // VALIDATE VOTING SCHEDULE...
  $vstatus = $form_state['values']['vstatus'];
  $vopen_time = _election_normalize_datetime($form_state['values']['vopen_time']);
  $vclose_time = _election_normalize_datetime($form_state['values']['vclose_time']);

  // Check that the opening and closing times are set if voting is scheduled.
  if ($vstatus == ELECTION_STATUS_SCHEDULED
      && (empty($vopen_time) || empty($vclose_time))) {
    form_set_error('vschedule', t('You must set the opening and closing times when the voting status is Scheduled.'));
  }
  // Check that the closing time is after the opening time.
  elseif ($vstatus == ELECTION_STATUS_SCHEDULED
        && $vclose_time <= $vopen_time) {
    form_set_error('vschedule', t('The closing time of voting must be after the opening time.'));
  }

  // VALIDATE NOMINATIONS SCHEDULE...
  if (isset($form_state['values']['nstatus'])) {
    $nstatus = $form_state['values']['nstatus'];
    $nopen_time = _election_normalize_datetime($form_state['values']['nopen_time']);
    $nclose_time = _election_normalize_datetime($form_state['values']['nclose_time']);
    // Check that nominations and voting are not open at the same time.
    if ($nstatus == ELECTION_STATUS_OPEN && $vstatus == ELECTION_STATUS_OPEN) {
      form_set_error('vstatus', t('Voting should not be open at the same time as nominations.'));
    }
    // Check that the opening and closing times are set, if relevant.
    elseif ($nstatus == ELECTION_STATUS_SCHEDULED
        && (empty($nopen_time) || empty($nclose_time))) {
      form_set_error('nschedule', t('You must set the opening and closing times when the nominations status is Scheduled.'));
    }
    // Check that the closing time is after the opening time.
    elseif ($nstatus == ELECTION_STATUS_SCHEDULED
          && $nclose_time <= $nopen_time) {
      form_set_error('nschedule', t('The closing time of nominations must be after the opening time.'));
    }
    // Check that the voting time is after the nominations close.
    elseif ($vstatus == ELECTION_STATUS_SCHEDULED
          && $vopen_time < $nclose_time) {
      form_set_error('nschedule', t('Nominations can only be scheduled so that they close before the start of voting.'));
    }
  }

  // For dates that have changed, display a warning for dates in the past.
  foreach (array('n' => 'nominations', 'v' => 'voting') as $key => $value) {
    foreach (array('open', 'close') as $open_close) {
      if (isset($form_state['values'][$key . $open_close . '_time'])) {
        $time_old = _election_normalize_datetime($form[$value][$key . 'schedule'][$key . $open_close . '_time']['#default_value']);
        $time_new = _election_normalize_datetime($form_state['values'][$key . $open_close . '_time']);
        if (is_int($time_new) && $time_old !== $time_new && $time_new < REQUEST_TIME) {
          $message = t('@what @which is in the past.', array(
            '@what' => $form[$value][$key . 'schedule']['#title'],
            '@which' => $form[$value][$key . 'schedule'][$key . $open_close . '_time']['#title'],
          ));
          drupal_set_message($message, 'warning');
        }
      }
    }
  }

  // Check other Fields.
  field_attach_form_validate('election', $form_state['election'], $form, $form_state);

}

/**
 * Form submit function for the Save button in the form election_form.
 */
function election_form_submit($form, &$form_state) {

  global $user;

  $election = &$form_state['election'];

  if (empty($election->uid)) {
    $election->uid = $user->uid;
  }

  foreach ($form_state['values'] as $property => $value) {
    if (substr($property, 0, 9) == 'settings_') {
      $key = substr($property, 9);
      $election->settings[$key] = $value;
    }
  }

  foreach ($election as $property => $value) {
    if (isset($form_state['values'][$property])) {
      $election->$property = $form_state['values'][$property];
    }
  }

  field_attach_submit('election', $election, $form, $form_state);

  // Save the election.
  election_save($election);

  // Notify the user that the election was saved.
  $type = _election_type_get_info($election->type);
  drupal_set_message(
    t('The @type %title was saved.', array('@type' => $type['name'], '%title' => $election->title))
  );

  if (empty($_GET['destination'])) {
    $form_state['redirect'] = election_uri_path($election);
  }

}

/**
 * Form submit function for the Delete button in the form election_form.
 */
function election_form_delete_submit($form, &$form_state) {
  $destination = array();
  if (isset($_GET['destination'])) {
    $destination = drupal_get_destination();
    unset($_GET['destination']);
  }
  $election = $form['#election'];
  $form_state['redirect'] = array(
    election_uri_path($election) . '/delete',
    array('query' => $destination),
  );
}

/**
 * Form builder function to confirm the delete action for an election.
 *
 * @see confirm_form()
 */
function election_form_delete_confirm($form, &$form_state, stdClass $election) {

  election_set_breadcrumb($election);

  $form['#election'] = $election;
  $form['election_id'] = array(
    '#type' => 'value',
    '#value' => $election->election_id,
  );

  return confirm_form(
    $form,
    t('Are you sure you want to delete %title?', array('%title' => $election->title)),
    election_uri_path($election),
    t('Deleting an election also deletes ALL associated data, for example votes. This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Submit callback, called after confirming delete for an election.
 */
function election_form_delete_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    $election = election_load($form_state['values']['election_id']);

    election_delete($form_state['values']['election_id']);
    watchdog('election', 'Deleted election "%title" (type: @type)', array('@type' => $election->type, '%title' => $election->title));

    $type = _election_type_get_info($election->type);

    drupal_set_message(
      t('The @type %title has been deleted.', array('@type' => $type['name'], '%title' => $election->title))
    );
  }
  if (empty($_GET['destination'])) {
    $form_state['redirect'] = 'elections';
  }
}
