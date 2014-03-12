<?php

  $form['tb']['tb_development'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Theme development settings'),
    '#weight'        => 99,
  );

  $form['tb']['tb_development']['welcome_tab'] = array(
    '#type' => 'checkbox',
    '#title' => t('Welcome tab'),
    '#description' => t('You can hide here, if you don\'t want to see "Welcome" tab anymore.'),
    '#default_value' => theme_get_setting('welcome_tab'),
  );

  $form['tb']['tb_development']['debug'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Debug'),
    '#default_value' => theme_get_setting('debug')
  );

  $form['tb']['tb_development']['bootstrap_rebuild_registry'] = array(
    '#type'          => 'checkbox',
    '#title'         => t('Rebuild theme registry on every page.'),
    '#default_value' => theme_get_setting('bootstrap_rebuild_registry'),
    '#description'   => t('During theme development, it can be very useful to continuously <a href="!link">rebuild the theme registry</a>.') . '<div class="alert alert-error">' . t('WARNING: this is a huge performance penalty and must be turned off on production websites. ') . l('Drupal.org documentation on theme-registry.', 'http://drupal.org/node/173880#theme-registry'). '</div>',
  );


$form['tb']['tb_development']['personal_style'] = array(
  '#type' => 'textarea',
  '#title' => t('Your css codes'),
  '#default_value' => theme_get_setting('personal_style'),
  '#description' => t("You can write your own css codes here. Please be careful. There is no  any malicious code control and malicious code can cause unexpected results."),
);

if ( theme_get_setting('debug') ) {

  $form['tb']['tb_development']['custom_css_info'] = array(
    '#markup' => t("<b>Custom css file: </b>").theme_get_setting("custom_css"),
  );

}
