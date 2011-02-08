<?php

/**
 * Implementation of hook_user_default_permissions().
 */
function cod_bof_user_default_permissions() {
  $permissions = array();

  // Exported permission: edit field_room_session_capacity
  $permissions['edit field_room_session_capacity'] = array(
    'name' => 'edit field_room_session_capacity',
    'roles' => array(
      '0' => 'session organizer',
      '1' => 'site administrator',
    ),
  );

  return $permissions;
}
