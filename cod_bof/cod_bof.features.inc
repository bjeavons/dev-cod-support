<?php

/**
 * Implementation of hook_ctools_plugin_api().
 */
function cod_bof_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => 1);
  }
}

/**
 * Implementation of hook_node_info().
 */
function cod_bof_node_info() {
  $items = array(
    'bof_session' => array(
      'name' => t('BoF session'),
      'module' => 'features',
      'description' => t('Sessions that visitors can self-schedule at any time. Examples: birds of a feather sessions (BoFs).'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'has_body' => '1',
      'body_label' => t('Description'),
      'min_word_count' => '0',
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implementation of hook_views_api().
 */
function cod_bof_views_api() {
  return array(
    'api' => '2',
  );
}
