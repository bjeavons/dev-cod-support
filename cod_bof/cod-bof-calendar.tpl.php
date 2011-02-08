<?php if(!empty($days) && !empty($rooms) && !empty($arranged_slots)): ?>
<ul>
<?php foreach ($day_links as $link): ?>
<li><?php print $link ?></li>
<?php endforeach ?>
</ul>
<?php foreach ($days as $day_key => $day_title): ?>
  <h2><?php print $day_title; ?></h2>
  <table class="session-calendar">
    <tr>
      <th><?php print t('Time'); ?></th>
    <?php foreach ($rooms as $room_nid => $room): ?>
        <th><span class="room-label"><?php print $room['title']; ?></span></th>
    <?php endforeach ?>
    </tr>
    <?php foreach ($arranged_slots[$day_key] as $slot): ?>
      <tr class="<?php print $zebra = $zebra == 'even' ? 'odd':'even'; ?>">
        <td class="time-label">
          <?php print $slot['start']; ?>&nbsp;-<br /><?php print $slot['end']; ?>
        </td>
        <?php foreach ($room_nids as $room_nid): ?>
            <?php if (!empty($schedule_grid[$day_key][$slot['nid']][$room_nid]['sessions'])): ?>
              <td class="session occupied" colspan="<?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['colspan']; ?>">
                <?php foreach($schedule_grid[$day_key][$slot['nid']][$room_nid]['sessions'] as $session): ?>
                  <div class="views-item type-<?php print check_plain($session['session']->type); ?>">
                    <?php print $results[$session['session']->nid]; ?>
                  </div>
                <?php endforeach ?>
            <?php elseif (!$schedule_grid[$day_key][$slot['nid']][$room_nid]['spanned']): ?>
              <td class="session empty">&nbsp;
            <?php endif ?>
            <?php if ($bof): ?>
              <div><?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['availability']; ?></div>
            <?php endif ?>
            <?php if($bof && isset($schedule_grid[$day_key][$slot['nid']][$room_nid]['cta'])): ?>
              <div>
                <?php print $schedule_grid[$day_key][$slot['nid']][$room_nid]['cta']; ?>
              </div>
            <?php endif ?>
            </td>
        <?php endforeach ?>
      </tr>
    <?php endforeach ?>
  </table>
<?php endforeach ?>
<?php endif ?>