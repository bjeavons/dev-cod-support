<?php
/**
 * @file
 * Views hooks for cod_bof feature
 */

/**
 * Implementation of hook_views_plugins().
 */
function cod_bof_views_plugins() {
  return array(
    'style' => array(
      'cod_bof_calendar' => array(
        'title' => t('BoF Session calendar'),
        'help' => t('Display view as a table with room columns and time slot rows'),
        'handler' => 'cod_bof_views_style_plugin_calendar',
        'theme' => 'cod_bof_calendar',
        'uses row plugin' => TRUE,
        'uses fields' => TRUE,
        'uses grouping' => TRUE,
        'uses options' => TRUE,
        'use sort' => FALSE,
        'use pager' => FALSE,
        'use ajax' => FALSE,
        'use more' => FALSE,
        'type' => 'normal',
        'help topic' => 'style-unformatted',
        'even empty' => TRUE, // Make the View render when there are no results.
      ),
    ),
  );
}