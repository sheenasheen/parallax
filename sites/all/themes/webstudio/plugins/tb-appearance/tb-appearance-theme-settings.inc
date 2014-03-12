<?php

// <!-- GLOBAL APPEARANCE
// ================================================== -->

$form['tb']['tb_appearance'] = array(
  '#type'          => 'fieldset',
  '#title'         => t('Global Appearance'),
  '#description'   => t("Global appearance parameters are configured here."),
  // '#weight'        => 0,
);

$Globals = array(
  'brand'        => 'GlobalBrand',
);

$Body = array(
  'body'        => 'body',
);



// <!-- Body Appearance
// ================================================== -->

foreach ($Body as $key => $value) {

  $form['tb']['tb_appearance'][$key] = array(
    '#type'          => 'fieldset',
    '#title'         => t('@Name Appearance',array('@Name' => $key ) ),
    // '#weight'        => 0,
    '#collapsible' => TRUE,
    '#collapsed' => (theme_get_setting($key.'_customize')) ? FALSE: TRUE   ,
  );

  ${$key} = &$form['tb']['tb_appearance'][$key];

  ${$key}[$key.'_wrapper'] = array(
    '#type' => 'value',
    '#value' => $value,
  );

  // ${$key}[$key.'_raw'] = array(
  //   '#type' => 'checkbox',
  //   '#title' => t('Raw mode'),
  //   '#attributes'    => array( 'class' => array('on_off_ui') ),
  //   '#default_value' => theme_get_setting($key.'_raw'),
  // );


  ${$key}[$key.'_customize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Customization'),
    '#attributes'    => array( 'class' => array('on_off_ui') ),
    '#default_value' => theme_get_setting($key.'_customize'),
    // '#element_validate' => array('_demo_validate'),
  );

  ${$key}[$key.'_custom_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
      ),
    ),
    '#attributes'    => array( 'class' => array('inline-elements six-elements') ),
  );

  ${$key."Customize"} = &${$key}[$key.'_custom_container'];

  ${$key."Customize"}[$key.'_preview'] = array(
    '#markup' => '<div class="'.$key.'_preview live-preview" data-region="'.$key.'">
    <h2>'.strtoupper($key).' TITLE</h2>
    <hr/>
    <p>Lorem <b>ipsum</b> <em>dolor</em> sit <i>amet</i>, consectetur adipiscing <a href="#">elit.</a></p>
    </div>' ,
  );

  // BACKGROUND
  ${$key."Customize"}[$key."_bgc"] = array(
    '#type' => "textfield",
    '#title' => t("Background"),
    '#default_value' => theme_get_setting($key."_bgc"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array("minicolors"),
      'data-opacity' => theme_get_setting($key."_bgc_op")
    ),
  );

  ${$key."Customize"}[$key."_bgc_op"] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_bgc_op")
  );


  // TEXT COLOR
  ${$key."Customize"}[$key.'_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text color'),
    '#default_value' => theme_get_setting($key.'_color'),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_color_op")
    ),
  );

  ${$key."Customize"}[$key.'_color_op'] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_color_op")
  );

  // TEXT SHADOW
  ${$key."Customize"}[$key.'_shadow'] = array(
    '#type' => 'textfield',
    '#title' => t('Text shadow'),
    '#default_value' => theme_get_setting($key.'_shadow'),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_shadow_op")
    ),
  );

  ${$key."Customize"}[$key."_shadow_op"] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_shadow_op")
  );


  // LINK AND HOVER
  ${$key."Customize"}[$key.'_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link color'),
    '#default_value' => theme_get_setting($key."_link"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_link_op")
    ),
  );


  ${$key."Customize"}[$key.'_link_op'] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_link_op")
  );

  ${$key."Customize"}[$key.'_hover'] = array(
    '#type' => 'textfield',
    '#title' => t('Hover color'),
    '#default_value' => theme_get_setting($key."_hover"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_hover_op")
    ),
  );

  ${$key."Customize"}[$key.'_hover_op'] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_hover_op")
  );



  ${$key."Customize"}[$key."_border"] = array(
    '#type' => "textfield",
    '#title' => t("Border color"),
    '#default_value' => theme_get_setting($key."_border"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_border_op")
    ),
  );

  ${$key."Customize"}[$key."_border_op"] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_border_op")
  );

  ${$key."Customize"}[$key."_preview_btn"] = array(
    '#markup' => '<a id="'.$key.'_btn" class="btn btn-small" data-preview="'.$key.'" href="#preview"><i class="icon-refresh"></i> Preview</a>',
  );




  if (module_exists("media")) {

    ${$key}[$key."_bg_type"] = array(
      '#type' => 'radios',
      '#title' => t('Background type'),
      '#options' => array(
        'pattern' => t('Pattern'),
        'fixed' => t('Full fixed')
      ),
      '#attributes'    => array( 'class' => array('tb-inline-radios') ),
      '#default_value' => (theme_get_setting($key."_bg_type")) ? theme_get_setting($key."_bg_type") : "pattern",
      '#states' => array(
        'visible' => array(
          ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
        ),
      ),
    );



    ${$key."_image"} = theme_get_setting($key."_bg_img");
    ${$key}[$key."_bg_img"] = array(
      '#tree' => TRUE,
      '#title' => t('Background image'),
      '#type' => 'media',
      '#states' => array(
        'visible' => array(
          ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
        ),
      ),
      '#description' => t('The uploaded image will be displayed on the page unless it is marked as "removed".'),
      '#default_value' => array('fid' => ${$key."_image"}['fid'] ),
      '#media_options' => array(
        'global' => array(
          'types' => array(
            'image' => 'image',
          ),
          // 'enabledPlugins' => array(
          //   'upload' => 'upload',
          //   'media_default--media_browser_1' => 'media_default--media_browser_1',
          // ),
          'schemes' => array(
            'public' => 'public',
          ),
          // 'file_directory' => 'subpage_banner',
          'file_extensions' => 'png gif jpg jpeg',
          'max_filesize' => '1 MB',
          'uri_scheme' => 'public',
        ),
      ),
    );
  } // end if



} // end foreach



// <!-- Brand Appearance
// ================================================== -->

foreach ($Globals as $key => $value) {

  $form['tb']['tb_appearance'][$key] = array(
    '#type'          => 'fieldset',
    '#title'         => t('@Name Appearance',array('@Name' => $key ) ),
    // '#weight'        => 0,
    '#collapsible' => TRUE,
    '#collapsed' => (theme_get_setting($key.'_customize')) ? FALSE: TRUE   ,
  );

  ${$key} = &$form['tb']['tb_appearance'][$key];

  ${$key}[$key.'_wrapper'] = array(
    '#type' => 'value',
    '#value' => $value,
  );

  ${$key}[$key.'_raw'] = array(
    '#type' => 'checkbox',
    '#title' => t('Fluid mode'),
    '#attributes'    => array( 'class' => array('on_off_ui') ),
    '#default_value' => theme_get_setting($key.'_raw'),
  );


  ${$key}[$key.'_customize'] = array(
    '#type' => 'checkbox',
    '#title' => t('Customization'),
    '#attributes'    => array( 'class' => array('on_off_ui') ),
    '#default_value' => theme_get_setting($key.'_customize'),
    // '#element_validate' => array('_demo_validate'),
  );

  ${$key}[$key.'_custom_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
      ),
    ),
    '#attributes'    => array( 'class' => array('inline-elements', 'form-item' , 'six-elements') ),
  );

  ${$key."Customize"} = &${$key}[$key.'_custom_container'];

  ${$key."Customize"}[$key.'_preview'] = array(
    '#markup' => '<div class="'.$key.'_preview live-preview" data-region="'.$key.'">
    <h2>'.strtoupper($key).' TITLE</h2>
    <hr/>
    <p>Lorem <b>ipsum</b> <em>dolor</em> sit <i>amet</i>, consectetur adipiscing <a href="#">elit.</a></p>
    </div>' ,
  );

  // BACKGROUND
  ${$key."Customize"}[$key."_bgc"] = array(
    '#type' => "textfield",
    '#title' => t("Background"),
    '#default_value' => theme_get_setting($key."_bgc"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array("minicolors"),
      'data-opacity' => theme_get_setting($key."_bgc_op")
    ),
  );

  ${$key."Customize"}[$key."_bgc_op"] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_bgc_op")
  );


  // TEXT COLOR
  ${$key."Customize"}[$key.'_color'] = array(
    '#type' => 'textfield',
    '#title' => t('Text color'),
    '#default_value' => theme_get_setting($key.'_color'),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_color_op")
    ),
  );

  ${$key."Customize"}[$key.'_color_op'] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_color_op")
  );

  // TEXT SHADOW
  ${$key."Customize"}[$key.'_shadow'] = array(
    '#type' => 'textfield',
    '#title' => t('Text shadow'),
    '#default_value' => theme_get_setting($key.'_shadow'),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_shadow_op")
    ),
  );

  ${$key."Customize"}[$key."_shadow_op"] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_shadow_op")
  );


  // LINK AND HOVER
  ${$key."Customize"}[$key.'_link'] = array(
    '#type' => 'textfield',
    '#title' => t('Link color'),
    '#default_value' => theme_get_setting($key."_link"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_link_op")
    ),
  );


  ${$key."Customize"}[$key.'_link_op'] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_link_op")
  );

  ${$key."Customize"}[$key.'_hover'] = array(
    '#type' => 'textfield',
    '#title' => t('Hover color'),
    '#default_value' => theme_get_setting($key."_hover"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_hover_op")
    ),
  );

  ${$key."Customize"}[$key.'_hover_op'] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_hover_op")
  );



  ${$key."Customize"}[$key."_border"] = array(
    '#type' => "textfield",
    '#title' => t("Border color"),
    '#default_value' => theme_get_setting($key."_border"),
    '#size' => 60,
    '#maxlength' => 7,
    '#attributes'    => array(
      'class' => array('minicolors'),
      'data-opacity' => theme_get_setting($key."_border_op")
    ),
  );

  ${$key."Customize"}[$key."_border_op"] = array(
    '#type' => 'hidden',
    // '#value' => (theme_get_setting("main_bgc_opacity")) ? theme_get_setting("main_bgc_opacity") : 1,
    '#default_value' => theme_get_setting($key."_border_op")
  );

  ${$key."Customize"}[$key."_preview_btn"] = array(
    '#markup' => '<a id="'.$key.'_btn" class="btn btn-small" data-preview="'.$key.'" href="#preview"><i class="icon-refresh"></i> Preview</a>',
  );



  // <!-- Metrics
  // ================================================== -->


  ${$key}[$key.'_metrics'] = array(
    '#type' => 'checkbox',
    '#title' => t('Customize metrics'),
    '#attributes'    => array( 'class' => array('on_off_ui') ),
    '#default_value' => theme_get_setting($key.'_metrics'),
  );



 ${$key}[$key.'_metrics_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_metrics"]' => array('checked' =>  true),
      ),
    ),
    '#attributes'    => array( 'class' => array('inline-elements', 'form-item' ,'four-elements') ),
  );

  ${$key."Metrics"} = &${$key}[$key.'_metrics_container'];

  ${$key."Metrics"}[$key.'_padding_top'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding top'),
    '#default_value' => (theme_get_setting($key.'_padding_top')) ? theme_get_setting($key.'_padding_top') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_padding_top' => array(
                'max'  => (theme_get_setting($key.'_padding_top') > 100) ? theme_get_setting($key.'_padding_top') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_padding_top"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Top padding must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );

  ${$key."Metrics"}[$key.'_padding_bottom'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding bottom'),
    '#default_value' => (theme_get_setting($key.'_padding_bottom')) ? theme_get_setting($key.'_padding_bottom') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_padding_bottom' => array(
                'max'  => (theme_get_setting($key.'_padding_bottom') > 100) ? theme_get_setting($key.'_padding_bottom') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_padding_bottom"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Bottom padding must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );


  ${$key."Metrics"}[$key.'_padding_left'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding left'),
    '#default_value' => (theme_get_setting($key.'_padding_left')) ? theme_get_setting($key.'_padding_left') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_padding_left' => array(
                'max'  => (theme_get_setting($key.'_padding_left') > 100) ? theme_get_setting($key.'_padding_left') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_padding_left"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Left padding must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );

  ${$key."Metrics"}[$key.'_padding_right'] = array(
    '#type' => 'textfield',
    '#title' => t('Padding right'),
    '#default_value' => (theme_get_setting($key.'_padding_right')) ? theme_get_setting($key.'_padding_right') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_padding_right' => array(
                'max'  => (theme_get_setting($key.'_padding_right') > 100) ? theme_get_setting($key.'_padding_right') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_padding_right"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Right padding must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );


  ${$key."Metrics"}[$key.'_spliter']['#markup'] = "<hr class='split'>";


  // Margin

  ${$key."Metrics"}[$key.'_margin_top'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin top'),
    '#default_value' => (theme_get_setting($key.'_margin_top')) ? theme_get_setting($key.'_margin_top') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_margin_top' => array(
                'max'  => (theme_get_setting($key.'_margin_top') > 100) ? theme_get_setting($key.'_margin_top') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_margin_top"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Top margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );

  ${$key."Metrics"}[$key.'_margin_bottom'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin bottom'),
    '#default_value' => (theme_get_setting($key.'_margin_bottom')) ? theme_get_setting($key.'_margin_bottom') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_margin_bottom' => array(
                'max'  => (theme_get_setting($key.'_margin_bottom') > 100) ? theme_get_setting($key.'_margin_bottom') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_margin_bottom"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Bottom margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );

  ${$key."Metrics"}[$key.'_margin_left'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin left'),
    '#default_value' => (theme_get_setting($key.'_margin_left')) ? theme_get_setting($key.'_margin_left') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_margin_left' => array(
                'max'  => (theme_get_setting($key.'_margin_left') > 100) ? theme_get_setting($key.'_margin_left') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_margin_left"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Left margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );

  ${$key."Metrics"}[$key.'_margin_right'] = array(
    '#type' => 'textfield',
    '#title' => t('Margin right'),
    '#default_value' => (theme_get_setting($key.'_margin_right')) ? theme_get_setting($key.'_margin_right') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_margin_right' => array(
                'max'  => (theme_get_setting($key.'_margin_right') > 100) ? theme_get_setting($key.'_margin_right') : 100,
                'min'  => 0,
                'step' => 5
              ),
            ),
          ),
        ),
        'type' => 'setting',
        ),
      ),
    ),
    // '#disabled' => TRUE,
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_margin_right"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Right margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
  );







} // end foreach
