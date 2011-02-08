<?php

/**
 * Implementation of hook_content_default_fields().
 */
function cod_bof_content_default_fields() {
  $fields = array();

  // Exported field: field_session_room
  $fields['bof_session-field_session_room'] = array(
    'field_name' => 'field_session_room',
    'type_name' => 'bof_session',
    'display_settings' => array(
      'weight' => 0,
      'parent' => 'group_schedule',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '1',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'room' => 'room',
      'bof_session' => 0,
      'event' => 0,
      'news' => 0,
      'page' => 0,
      'product' => 0,
      'schedule_item' => 0,
      'session' => 0,
      'sponsor' => 0,
      'time_slot' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'field_permissions' => array(
      'edit' => 'edit',
      'view' => 'view',
      'edit for bof_session' => 'edit for bof_session',
      'create' => 0,
      'edit own' => 0,
      'view own' => 0,
      'edit for news' => 0,
      'edit for page' => 0,
      'edit for room' => 0,
      'edit for schedule_item' => 0,
      'edit for session' => 0,
      'edit for time_slot' => 0,
      'edit for sponsor' => 0,
      'edit for product' => 0,
      'edit for event' => 0,
    ),
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => NULL,
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Room',
      'weight' => '32',
      'description' => 'Select room(s) in which the session occurs.',
      'type' => 'nodereference_buttons',
      'module' => 'nodereference',
    ),
  );

  // Exported field: field_session_slot
  $fields['bof_session-field_session_slot'] = array(
    'field_name' => 'field_session_slot',
    'type_name' => 'bof_session',
    'display_settings' => array(
      'weight' => '-1',
      'parent' => 'group_schedule',
      'label' => array(
        'format' => 'inline',
      ),
      'teaser' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'full' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '4' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '2' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      '3' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
      'token' => array(
        'format' => 'default',
        'exclude' => 0,
      ),
    ),
    'widget_active' => '1',
    'type' => 'nodereference',
    'required' => '0',
    'multiple' => '0',
    'module' => 'nodereference',
    'active' => '1',
    'referenceable_types' => array(
      'time_slot' => 'time_slot',
      'event' => 0,
      'bof_session' => 0,
      'news' => 0,
      'page' => 0,
      'product' => 0,
      'room' => 0,
      'schedule_item' => 0,
      'session' => 0,
      'sponsor' => 0,
    ),
    'advanced_view' => '--',
    'advanced_view_args' => '',
    'field_permissions' => array(
      'view' => 'view',
      'edit' => 'edit',
    ),
    'widget' => array(
      'autocomplete_match' => 'contains',
      'size' => 60,
      'default_value' => array(
        '0' => array(
          'nid' => '',
        ),
      ),
      'default_value_php' => NULL,
      'label' => 'Time slot',
      'weight' => '34',
      'description' => '',
      'type' => 'nodereference_select',
      'module' => 'nodereference',
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Room');
  t('Time slot');

  return $fields;
}
