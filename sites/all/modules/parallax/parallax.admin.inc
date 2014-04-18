<?php

/**
 * @file
 * Admin page callbacks for the Twitter Block module.
 */

/**
 * Form constructor for the add block form.
 *
 * @see parallax_add_block_form_validate()
 * @see parallax_add_block_form_submit()
 * @ingroup forms
 */
function parallax_add_block_form($form, &$form_state) {
  module_load_include('inc', 'block', 'block.admin');
  $form = block_admin_configure($form, $form_state, 'parallax', NULL);

  // Other modules should be able to use hook_form_block_add_block_form_alter()
  // to modify this form, so add a base form ID
  $form_state['build_info']['base_form_id'] = 'block_add_block_form';

  // Prevent block_add_block_form_validate/submit() from being automatically
  // added because of the base form ID by providing these handlers manually
  $form['#validate'] = array('parallax_add_block_form_validate');
  $form['#submit'] = array('parallax_add_block_form_submit');

  return $form;
}

/**
 * Form validation handler for parallax_add_block_form().
 *
 * @see parallax_add_block_form()
 * @see parallax_add_block_form_submit()
 */
function parallax_add_block_form_validate($form, &$form_state) {
  $unique_description = (bool) db_query_range('SELECT 1 FROM {parallax} WHERE info = :info', 0, 1, array(':info' => $form_state['values']['info']))->fetchField();

  if (empty($form_state['values']['info']) || $unique_description) {
    form_set_error('info', t('Ensure that each block description is unique.'));
  }

  
  if (empty($form_state['values']['image'])) {
    form_set_error('image', t('Content will appears over parallax on front end.'));
  }
}

/**
 * Form submission handler for parallax_add_block_form().
 *
 * Saves the new parallax block.
 *
 * @see parallax_add_block_form()
 * @see parallax_add_block_form_validate()
 */
function parallax_add_block_form_submit($form, &$form_state) {
  // The serialized 'data' column contains the timeline settings.
  $data = array(
    //'theme' => $form_state['values']['theme'],
    'width' => $form_state['values']['width'],
    'height' => $form_state['values']['height'],
    );

  // Save the block configuration
  $delta = db_insert('parallax')
    ->fields(array(
      'info' => $form_state['values']['info'],
   
      'data' => serialize($data),
    ))
    ->execute();

  // Store block delta to allow other modules to work with new block
  $form_state['values']['delta'] = $delta;

  // Run the normal new block submission (borrowed from block_add_block_form_submit)
  $query = db_insert('block')->fields(array('visibility', 'pages', 'custom', 'title', 'module', 'theme', 'status', 'weight', 'delta', 'cache'));
  foreach (list_themes() as $key => $theme) {
    if ($theme->status) {
      $query->values(array(
        'visibility' => (int) $form_state['values']['visibility'],
        'pages' => trim($form_state['values']['pages']),
        'custom' => (int) $form_state['values']['custom'],
        'title' => $form_state['values']['title'],
        'module' => $form_state['values']['module'],
        'theme' => $theme->name,
        'status' => 0,
        'weight' => 0,
        'delta' => $delta,
        'cache' => DRUPAL_NO_CACHE,
      ));
    }
  }
  $query->execute();

  $query = db_insert('block_role')->fields(array('rid', 'module', 'delta'));
  foreach (array_filter($form_state['values']['roles']) as $rid) {
    $query->values(array(
      'rid' => $rid,
      'module' => $form_state['values']['module'],
      'delta' => $delta,
    ));
  }
  $query->execute();

  // Store regions per theme for this block
  foreach ($form_state['values']['regions'] as $theme => $region) {
    db_merge('block')
      ->key(array('theme' => $theme, 'delta' => $delta, 'module' => $form_state['values']['module']))
      ->fields(array(
        'region' => ($region == BLOCK_REGION_NONE ? '' : $region),
        'pages' => trim($form_state['values']['pages']),
        'status' => (int) ($region != BLOCK_REGION_NONE),
      ))
      ->execute();
  }

  drupal_set_message(t('The parallax block has been created.'));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
}

/**
 * Form constructor for the custom Twitter block deletion form.
 *
 * @param $delta
 *   The unique ID of the block within the context of $module.
 *
 * @see parallax_delete_submit()
 */
function parallax_delete($form, &$form_state, $delta) {
  $block = block_load('parallax', $delta);
  $parallax = parallax_block_get($block->delta);
  $form['info'] = array('#type' => 'hidden', '#value' => $parallax['info'] ? $parallax['info'] : $parallax['title']);
  $form['bid'] = array('#type' => 'hidden', '#value' => $block->delta);

  return confirm_form($form, t('Are you sure you want to delete the block %name?', array('%name' => $parallax['info'])), 'admin/structure/block', '', t('Delete'), t('Cancel'));
}

/**
 * Form submission handler for parallax_delete().
 *
 * @see parallax_delete()
 */
function parallax_delete_submit($form, &$form_state) {
  db_delete('parallax')
    ->condition('bid', $form_state['values']['bid'])
    ->execute();
  db_delete('block')
    ->condition('module', 'parallax')
    ->condition('delta', $form_state['values']['bid'])
    ->execute();
  db_delete('block_role')
    ->condition('module', 'parallax')
    ->condition('delta', $form_state['values']['bid'])
    ->execute();
  drupal_set_message(t('The block %name has been removed.', array('%name' => $form_state['values']['info'])));
  cache_clear_all();
  $form_state['redirect'] = 'admin/structure/block';
  return;
}
