<?php
/**
 * Implements hook_preprocess_block().
 */
function hcprobt_preprocess_block(&$variables) {
  switch ($variables['block']->module) {
    case 'system':
      switch ($variables['block']->delta) {
        case 'main-menu':
          $variables['theme_hook_suggestions'][] = 'block__nav__main';
          break;
      }
      break;
  }
}
