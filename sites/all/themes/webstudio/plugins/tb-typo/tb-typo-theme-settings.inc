<?php

include_once(dirname(__FILE__) . '/tb-typo-helper.inc');


$form['tb']['tb_typo'] = array(
  '#type'          => 'fieldset',
  '#title'         => t('Typography'),
  // '#description'   => t("... parameters are configured here."),
  // '#weight'        => 0,
  // '#tree' => TRUE,
);

$Typosets = array(
  'base'         => 'body',
  'sitename'     => 'brand',
  'mainmenu'     => 'mainmenu',
  'siteslogan'   => 'site-slogan',
  'pagetitle'    => 'page-title',
  'nodetitle'    => 'node-title',
  'commenttitle' => 'comment-title',
  'blocktitle'   => 'block-title',
  'h1'           => 'h1',
  'h2'           => 'h2',
  'h3'           => 'h3',
  'custom'       => 'custom-font'
);

if (theme_get_setting("show_font_variant")) {
  drupal_add_js( array(  "fonts_variant" => $google_fonts_variant  ), 'setting');
}

foreach ($Typosets as $key => $value) {

  $form['tb']['tb_typo'][$key] = array(
    '#type'          => 'fieldset',
    '#title'         => t($key.' Typography'),
    // '#description'   => t("Content Typography parameters are configured here."),
    // '#weight'        => -2,
    '#collapsible' => TRUE,
    '#collapsed' => (theme_get_setting($key.'_font_type')) ? false : true,
  );

  if ($key=="custom") {
    $form['tb']['tb_typo'][$key]['#title'] = t($key.' Font Typography');
    $form['tb']['tb_typo'][$key]['#description'] = t("You can use your custom font type with your custom selector class in any context e.g: <code>.custom-font</code>");
  }


  ${$key} = &$form['tb']['tb_typo'][$key];

  if ($key=="custom") {
    ${$key}[$key.'_selector'] = array(
      '#type' => 'textfield',
      '#title' => t("Your custom css selector"),
      '#default_value' => (theme_get_setting($key.'_selector')) ? theme_get_setting($key.'_selector') : $value,
      // '#value' => $value,
      '#size' => 60,
      '#maxlength' => 128,
      '#description' => t("This field shall be defined as a CSS class. Do not use <strong>punctuation marks</strong> in this area."),
      '#element_validate' => array('_custom_font_selector'),
    );

  }else{
    ${$key}[$key.'_selector'] = array(
      '#type' => 'hidden',
      '#value' => $value,
    );
  }

  ${$key}[$key.'_font_type'] = array(
    '#type' => 'radios',
    '#title' => t('Font type'),
    '#options' => array('Default','websafe' => 'Websafe','google' =>'Google'),
    '#default_value' => (theme_get_setting($key.'_font_type')) ? theme_get_setting($key.'_font_type') : "0",
    '#attributes' => array('class' =>array('tb-inline-radios'))
  );

  ${$key}[$key.'_font_websafe'] = array(
    '#type' => 'select',
    '#title' => t('Websafe Fonts'),
    '#default_value' => theme_get_setting($key.'_font_websafe') ,
    '#options' => _websafe_fonts_cache(),
    '#states' => array(
    'visible' => array(
      ':input[name="'.$key.'_font_type"]' => array('value' =>'websafe')
    )
    )
  );

  ${$key}[$key.'_font_websafe_weight'] = array(
    '#type' => 'radios',
    '#title' => t('Font weight'),
    '#default_value' => (theme_get_setting($key.'_font_websafe_weight')) ? theme_get_setting($key.'_font_websafe_weight') : "400" ,
    '#options' => array(
      '400'=>"Regular",
      '400italic'=>"Italic",
      '700'=>"Bold",
      '700italic' => "Bold italic"
      ),
    '#attributes'    => array('class' => array('typo-font-weight')),
    '#states' => array(
    'visible' => array(
      ':input[name="'.$key.'_font_type"]' => array('value' =>'websafe')
    )
    )
  );

  ${$key}[$key.'_font_websafe_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Font size'),
    '#default_value' => (theme_get_setting($key.'_font_websafe_size')) ? theme_get_setting($key.'_font_websafe_size') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_font_websafe_size' => array(
                'max'  => (theme_get_setting($key.'_font_websafe_size') > 100) ? theme_get_setting($key.'_font_websafe_size') : 100,
                'min'  => 0,
                'step' => 1
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_font_websafe_size"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Font size must be a positive number greater than 1 and valid CSS unit is <b>px</b>. Leave zero to disable."),
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_font_type"]' => array('value' =>  "websafe"),
      ),
    ),
  );



  ${$key}[$key.'_font_google'] = array(
    '#type' => 'select',
    '#title' => t('Google WebFonts'),
    '#options' => $google_fonts_family,
    '#default_value' => theme_get_setting($key.'_font_google') ,
    '#attributes' => array('class' => array('gwf-selector') ),
    '#states' => array(
      'visible' => array(
        'input[name="'.$key.'_font_type"]' => array('value' =>'google')
      )
    )
  );

  ${$key}[$key.'_font_google_weight'] = array(
    '#type' => 'radios',
    '#title' => t('Font weight'),
    '#options' => _font_weight(),
    '#default_value' => (theme_get_setting($key.'_font_google_weight')) ? theme_get_setting($key.'_font_google_weight') : "400" ,
    '#attributes'    => array('class' => array('typo-font-weight','typo-gwf')),
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_font_type"]' => array('value' =>'google')
      ),
    ),
    '#description' => t("Font weight may vary depending on the selected font."),
  );

  ${$key}[$key.'_font_google_subset'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Font subset'),
    '#options' => array(
      'latin' => 'Latin',
      'latin-ext' => 'Latin-ext'
      ),
    '#default_value' => (theme_get_setting($key.'_font_google_subset')) ? theme_get_setting($key.'_font_google_subset') : array('latin' => 'latin','latin-ext' => 0) ,
    '#attributes'    => array( 'class' => array('tb-inline-checkboxes') ),
    '#states' => array(
      'visible' => array(
        'input[name="'.$key.'_font_type"]' => array('value' =>'google')
      )
    ),
  );


   ${$key}[$key.'_font_google_size'] = array(
    '#type' => 'textfield',
    '#title' => t('Google Font size'),
    '#default_value' => (theme_get_setting($key.'_font_google_size')) ? theme_get_setting($key.'_font_google_size') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_font_google_size' => array(
                'max'  => (theme_get_setting($key.'_font_google_size') > 100) ? theme_get_setting($key.'_font_google_size') : 100,
                'min'  => 0,
                'step' => 1
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_font_google_size"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Font size must be a positive number greater than 1 and valid CSS unit is <b>px</b>. Leave zero to disable."),
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_font_type"]' => array('value' =>  "google"),
      ),
    ),
  );


} // end foreach
