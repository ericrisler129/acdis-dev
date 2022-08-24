<?php
/**
 * @file
 * hcpro_content_type_resources.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function hcpro_content_type_resources_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_epub_cover';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100%',
  );
  $export['ebook__default__file_field_epub_cover'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_epub_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100%',
    'height' => 'auto',
  );
  $export['ebook__default__file_field_epub_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_epub_js';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'unzipped' => 1,
    'width' => '100%',
    'height' => '600px',
  );
  $export['ebook__default__file_field_epub_js'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_epub_js_reader';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'unzipped' => TRUE,
  );
  $export['ebook__default__file_field_epub_js_reader'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_epub_toc';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__default__file_field_epub_toc'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__default__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['ebook__default__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__default__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__default__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__default__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_epub_cover';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100%',
  );
  $export['ebook__preview__file_field_epub_cover'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_epub_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100%',
    'height' => 'auto',
  );
  $export['ebook__preview__file_field_epub_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_epub_js';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'unzipped' => 1,
    'width' => '100%',
    'height' => '600px',
  );
  $export['ebook__preview__file_field_epub_js'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_epub_js_reader';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'unzipped' => TRUE,
  );
  $export['ebook__preview__file_field_epub_js_reader'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_epub_toc';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__preview__file_field_epub_toc'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__preview__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['ebook__preview__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__preview__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__preview__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__preview__file_field_file_url_plain'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_epub_cover';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100%',
  );
  $export['ebook__teaser__file_field_epub_cover'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_epub_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'width' => '100%',
    'height' => 'auto',
  );
  $export['ebook__teaser__file_field_epub_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_epub_js';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = array(
    'unzipped' => 1,
    'width' => '100%',
    'height' => '600px',
  );
  $export['ebook__teaser__file_field_epub_js'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_epub_js_reader';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'unzipped' => TRUE,
  );
  $export['ebook__teaser__file_field_epub_js_reader'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_epub_toc';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__teaser__file_field_epub_toc'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_file_default';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__teaser__file_field_file_default'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_file_download_link';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = array(
    'text' => 'Download [file:name]',
  );
  $export['ebook__teaser__file_field_file_download_link'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_file_table';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__teaser__file_field_file_table'] = $file_display;

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'ebook__teaser__file_field_file_url_plain';
  $file_display->weight = 0;
  $file_display->status = FALSE;
  $file_display->settings = '';
  $export['ebook__teaser__file_field_file_url_plain'] = $file_display;

  return $export;
}
