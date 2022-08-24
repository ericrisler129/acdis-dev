<?php

/**
 * @file
 * Display Suite 1 column template.
 */
?>
<<?php print $ds_content_wrapper; print $layout_attributes; ?> class="ds-1col <?php print $classes;?> clearfix">
  <?php if (isset($view_mode) && ($view_mode == 'teaser' || $view_mode == 'teaser_with_meta' || $view_mode == 'teaser_small') && !empty($node->locked)): ?>
    <span class="lock-icon"><i class="fa fa-lock"></i></span>
  <?php endif; ?>
  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php print $ds_content; ?>
</<?php print $ds_content_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
