<?php

/**
 * @file
 * Class ElectionCandidateTypeController.
 */

/**
 * The controller for election candidate type entities.
 */
class ElectionCandidateTypeController extends EntityAPIControllerExportable {

  /**
   * Set defaults for candidate types.
   *
   * @param array $values
   *   Array of candidate field values.
   *
   * @return object
   *   A candidate type object with all default fields initialized.
   */
  public function create(array $values = array()) {
    $values += array(
      'id' => '',
      'is_new' => TRUE,
      'data' => '',
    );
    return parent::create($values);
  }

}
