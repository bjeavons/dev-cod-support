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
    // Set COD-specific settings.
    $view->cod_schedule_interactive = $this->options['schedule_interactive'];
    if (!empty($this->options['schedule_days'])) {
      $schedule_days = array_filter($this->options['schedule_days']);
      $view->cod_schedule_days = $schedule_days; // @todo get more info about this day?
    }
    else {
      $schedule_days = cod_session_days();
      $view->cod_schedule_days = array_keys($schedule_days);
    }
    $interactive_type = $this->options['interactive_type'];
    $view->cod_interactive_type = !empty($view->cod_schedule_interactive) ? $interactive_type : FALSE;

    // Make sure views does't try to limit the number of items in this view.
    $this->view->pager['items_per_page'] = 0;
  }
  
  /**
   * Set default options
   */
  function option_definition() {
    $options = parent::option_definition();
    $options['schedule_interactive'] = 0;
    $schedule_days = cod_session_days();
    $options['schedule_days'] = array_keys($schedule_days);
    $options['interactive_type'] = 0;
    return $options;
  }

  /**
   * Style options.
   */
  function options_form(&$form, &$form_state) {
    $schedule_days = cod_session_days();
    $form['schedule_days'] = array(
      '#title' => t('Schedule days'),
      '#default_value' => $this->options['schedule_days'],
      '#type' => 'checkboxes',
      '#options' => $schedule_days,
      '#description' => t('Select which days to show on this display.'),
    );
    $form['schedule_interactive'] = array(
      '#title' => t('Interactive schedule'),
      '#default_value' => $this->options['schedule_interactive'],
      '#type' => 'radios',
      '#options' => array(0 => t('Off'), 1 => t('On')),
      '#description' => t('Include schedule slot availability and scheduling links. Causes all interactive rooms to appear.'),
    );
    $types = cod_session_schedulable_types();
    $options = array(0 => 'N/A');
    foreach ($types as $type => $content_type) {
      $options[$type] = check_plain($content_type['name']);
    }
    $form['interactive_type'] = array(
      '#title' => t('Interactive session type'),
      '#default_value' => $this->options['interactive_type'],
      '#type' => 'radios',
      '#options' => $options,
      '#description' => t('Set the content type to provide interactive controls for.'),
    );
  }
  
  /*function options_submit(&$form, &$form_state) {
    // not working.
    //dpm($form_state);
  }*/
}