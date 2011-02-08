<?php

/**
 * This file and class must exist for the calendar plugin
 * to be recognized by Views.
 *
 * @ingroup views_style_plugins
 */
class cod_bof_views_style_plugin_calendar extends views_plugin_style {
  
  function init(&$view, &$display, $options = NULL) {
    parent::init($view, $display, $options);
    $view->bof = $this->options['bof_session'];
    // Make sure views does't try to limit the number of items in this view.
    $this->view->pager['items_per_page'] = 0;
  }
  
  /**
   * Set default options
   */
  function options(&$options) {
    $options['bof_session'] = 0;
  }

  /**
   * Style options.
   */
  function options_form(&$form, &$form_state) {
    $form['bof_session'] = array(
      '#title' => t('Session type'),
      '#default_value' => $this->options['bof_session'],
      '#type' => 'radios',
      '#options' => array(0 => t('Sessions'), 1 => t('BoFs')),
      '#description' => t('Session or BoF.'),
    );
  }
}