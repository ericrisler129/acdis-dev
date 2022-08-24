<?php
/**
 * @file
 * hcpro_view_articles.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function hcpro_view_articles_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|slider';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'slider';
  $ds_fieldsetting->settings = array(
    'sponsor_heading' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
  );
  $export['node|article|slider'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'sponsor_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'ds_post_date_standard',
    ),
  );
  $export['node|article|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser_small';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser_small';
  $ds_fieldsetting->settings = array(
    'sponsor_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'ds_post_date_standard',
    ),
  );
  $export['node|article|teaser_small'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|article|teaser_with_meta';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'article';
  $ds_fieldsetting->view_mode = 'teaser_with_meta';
  $ds_fieldsetting->settings = array(
    'publication_teaser_meta' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'sponsor_heading' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
        'ft' => array(),
      ),
    ),
    'post_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_post_date_standard',
    ),
  );
  $export['node|article|teaser_with_meta'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function hcpro_view_articles_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'publication_teaser_meta';
  $ds_field->label = 'Publication Teaser Meta';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'article|teaser
article|teaser_with_meta';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$publication_field = field_get_items(\'node\', $entity, \'field_publication\');
$publication_id = $publication_field[0][\'publication\'];
$volume = $publication_field[0][\'volume\'];
$issue = $publication_field[0][\'issue\'];
$publication = get_publication_name($publication_id);
$download_link = get_pdf_download_link($entity);
?>

<span class="listing-icon"><span class="listing-icon-inner"></span></span>
<span class="publication-name">
<?php 
    print "{$publication} - Volume {$volume}, Issue {$issue}";
    empty($download_link) ?: print " - <a href=\'{$download_link}\'>DOWNLOAD FULL ISSUE</a>";
?>
</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 0,
  );
  $export['publication_teaser_meta'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function hcpro_view_articles_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|slider';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'slider';
  $ds_layout->layout = 'ds_2col_fluid';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'sponsor_heading',
        2 => 'title',
        3 => 'body',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'sponsor_heading' => 'right',
      'title' => 'right',
      'body' => 'right',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'left' => 'div',
      'right' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => 0,
  );
  $export['node|article|slider'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sponsor_heading',
        1 => 'title',
        2 => 'group_details',
        3 => 'body',
        4 => 'post_date',
        5 => 'field_publication',
        6 => 'field_category',
      ),
    ),
    'fields' => array(
      'sponsor_heading' => 'ds_content',
      'title' => 'ds_content',
      'group_details' => 'ds_content',
      'body' => 'ds_content',
      'post_date' => 'ds_content',
      'field_publication' => 'ds_content',
      'field_category' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'teaser' => 'teaser',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser_small';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser_small';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sponsor_heading',
        1 => 'title',
        2 => 'post_date',
        3 => 'group_details',
        4 => 'field_publication',
        5 => 'field_category',
      ),
    ),
    'fields' => array(
      'sponsor_heading' => 'ds_content',
      'title' => 'ds_content',
      'post_date' => 'ds_content',
      'group_details' => 'ds_content',
      'field_publication' => 'ds_content',
      'field_category' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'teaser' => 'teaser',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|teaser_small'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|article|teaser_with_meta';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'article';
  $ds_layout->view_mode = 'teaser_with_meta';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'sponsor_heading',
        1 => 'post_date',
        2 => 'publication_teaser_meta',
        3 => 'field_category',
        4 => 'title',
        5 => 'group_details',
        6 => 'body',
      ),
    ),
    'fields' => array(
      'sponsor_heading' => 'ds_content',
      'post_date' => 'ds_content',
      'publication_teaser_meta' => 'ds_content',
      'field_category' => 'ds_content',
      'title' => 'ds_content',
      'group_details' => 'ds_content',
      'body' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'teaser' => 'teaser',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'layout_disable_css' => FALSE,
  );
  $export['node|article|teaser_with_meta'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function hcpro_view_articles_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'slider';
  $ds_view_mode->label = 'Slider';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['slider'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_with_meta';
  $ds_view_mode->label = 'Teaser with Meta';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_with_meta'] = $ds_view_mode;

  return $export;
}
