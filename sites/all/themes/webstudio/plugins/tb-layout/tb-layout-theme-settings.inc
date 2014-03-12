<?php
include_once(dirname(__FILE__) . '/tb-layout-helper.inc');


$form['tb']['tb_layout'] = array(
  '#type'          => 'fieldset',
  '#title'         => t('Layout'),
  // '#description'   => t("Layout parameters are configured here."),
  '#weight'        => 2,
);

// <!-- Scaffolding
// ================================================== -->
$form['tb']['tb_layout']['tb_scaffolding'] = array(
  '#type'          => 'fieldset',
  '#title'         => t('Scaffolding'),
  '#weight'        => 0,
);

$scaffolding = &$form['tb']['tb_layout']['tb_scaffolding'];


// TODO:
// $scaffolding['layout_mode'] = array(
//   '#type' => 'radios',
//   '#title' => t('Layout mode'),
//   '#options' => array(
//     'static' => t('Static'),
//     'responsive' => t('Responsive')
//   ),
//   '#attributes'    => array( 'class' => array('tb-inline-radios') ),
//   '#default_value' => theme_get_setting('layout_mode'),
// );

$scaffolding['layout_style'] = array(
  '#type' => 'radios',
  '#title' => t('Layout style'),
  '#options' => array(
    0 => t('Fixed'),
    'fluid' => t('Fluid')
  ),
  '#attributes'    => array( 'class' => array('tb-inline-radios') ),
  '#default_value' => theme_get_setting('layout_style'),
);

$scaffolding['layout_type'] = array(
  '#type' => 'radios',
  '#title' => t('Layout type'),
  '#options' => array(
    'wide' => t('Wide'),
    'boxed' => t('Boxed')
  ),
  '#attributes'    => array( 'class' => array('tb-inline-radios') ),
  '#default_value' => theme_get_setting('layout_type'),
);




$Boxed = array(
  'box' => 'Boxed',
);

foreach ($Boxed as $key => $value) {


  $form['tb']['tb_layout']['tb_scaffolding'][$key] = array(
    '#type'          => 'fieldset',
    '#title'         => t('@Name Appearance',array('@Name' => $key ) ),
    // '#weight'        => 0,
    '#collapsible' => TRUE,
    '#collapsed' => (theme_get_setting($key.'_customize')) ? FALSE: TRUE ,
    '#states' => array(
    'visible' => array(
      ':input[name="layout_type"]' => array('value' =>  'boxed'),
      ),
    ),
  );

  ${$key} = &$form['tb']['tb_layout']['tb_scaffolding'][$key];

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


  ${$key}[$key.'_margin_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
      ),
    ),
    // '#attributes'    => array( 'class' => array('inline-elements six-elements') ),
  );

  $Margin = &${$key}[$key.'_margin_container'];

  $Margin['layout_top_margin'] = array(
    '#type' => 'textfield',
    '#title' => t('Box Top margin'),
    '#default_value' => (theme_get_setting('layout_top_margin')) ? theme_get_setting('layout_top_margin') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              'layout_top_margin' => array(
                'max'  => (theme_get_setting($key.'layout_top_margin') > 100) ? theme_get_setting($key.'layout_top_margin') : 100,
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
    '#field_prefix' => '<div class="biotic-slider" data-name="layout_top_margin"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Top margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
    '#states' => array(
      'visible' => array(
        ':input[name="layout_type"]' => array('value' =>  'boxed'),
      ),
    ),
  );

  $Margin['layout_bottom_margin'] = array(
    '#type' => 'textfield',
    '#title' => t('Box Bottom margin'),
    '#default_value' => (theme_get_setting('layout_bottom_margin')) ? theme_get_setting('layout_bottom_margin') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              'layout_bottom_margin' => array(
                'max'  => (theme_get_setting($key.'layout_bottom_margin') > 100) ? theme_get_setting($key.'layout_bottom_margin') : 100,
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
    '#field_prefix' => '<div class="biotic-slider" data-name="layout_bottom_margin"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Bottom margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
    '#states' => array(
      'visible' => array(
        ':input[name="layout_type"]' => array('value' =>  'boxed'),
      ),
    ),
  );

} // end foreach


$scaffolding['brand_layout'] = array(
  '#type' => 'radios',
  '#title' => t('Brand layout'),
  '#options' => array(
    "webstudio-default" => "Webstudio",
    "bootstrap-default" => "Bootstrap"
  ),
  '#default_value' => theme_get_setting('brand_layout'),
  '#attributes'    => array( 'class' => array('tb-inline-radios') ),
);

$scaffolding['header_fixed'] = array(
  '#type' => 'checkbox',
  '#title' => t('Fixed header'),
  '#default_value' => theme_get_setting('header_fixed'),
  '#attributes'    => array( 'class' => array('on_off_ui') ),
  '#states' => array(
    'visible' => array(
      ':input[name="brand_layout"]' => array('value' =>  'webstudio-default'),
    ),
  ),
);

$scaffolding["brand_scale"] = array(
  '#type' => "textfield",
  '#title' => t("Scale"),
  // '#title_display' => 'attribute',
  '#default_value' => theme_get_setting("brand_scale"),
  '#size' => 60,
  '#maxlength' => 7,
  '#states' => array(
    'visible' => array(
        ':input[name="header_fixed"]' => array('checked' =>  true),
        ':input[name="brand_layout"]' => array('value' =>  'webstudio-default'),
      ),
  ),
  '#attributes'    => array( 'class' => array('inline-label','input-medium') ),
  '#description' => t('This field represents of the width scale of the object and height will be calculated automatically. <br/><b>e.g:</b>  <code class="badge">50%</code> or  <code class="badge">1.6em</code> or  <code class="badge">50px</code> etc.'),
);



// <!-- Page Title
// ================================================== -->

$scaffolding['pagetitle_layout'] = array(
  '#type' => 'radios',
  '#title' => t('Page title layout'),
  '#options' => array(
    "top" => "Page Top",
    "node" => "Node Top"
  ),
  '#default_value' => theme_get_setting('pagetitle_layout'),
  '#attributes'    => array( 'class' => array('tb-inline-radios') ),
);


// <!-- Title Appearance
// ================================================== -->
//

$Title = array(
  'pagetitle'        => 'PageTitleWrapper',
);

foreach ($Title as $key => $value) {

  $form['tb']['tb_layout']['tb_scaffolding'][$key] = array(
    '#type'          => 'fieldset',
    '#title'         => t('@Name Appearance',array('@Name' => $key ) ),
    // '#weight'        => 0,
    '#collapsible' => TRUE,
    '#collapsed' => (theme_get_setting($key.'_customize')) ? FALSE: TRUE,
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_layout"]' => array('value' =>  "top")
      ),
    ),
  );

  ${$key} = &$form['tb']['tb_layout']['tb_scaffolding'][$key];

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

  ${$key}[$key.'_breadcrumb'] = array(
    '#type' => 'checkbox',
    '#title' => t('Breadcrumb'),
    '#attributes'    => array( 'class' => array('on_off_ui') ),
    '#default_value' => theme_get_setting($key.'_breadcrumb'),
    // '#element_validate' => array('_demo_validate'),
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
        ':input[name="'.$key.'_customize"]' => array('checked' =>  true)
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

    ${$key}[$key.'_background_container'] = array(
      '#type' => 'container',
      '#states' => array(
        'visible' => array(
          ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
        ),
      ),
      // '#attributes'    => array( 'class' => array('inline-elements six-elements') ),
    );

    $Background = &${$key}[$key.'_background_container'];

    $Background['pagetitle_bg_type'] = array(
      '#type' => 'radios',
      '#title' => t('Title Background type'),
      '#options' => array(
        'pattern' => t('Pattern'),
        'fixed' => t('Full fixed'),
        'parallax' => t('Parallax')
      ),
      '#attributes'    => array( 'class' => array('tb-inline-radios') ),
      '#default_value' => (theme_get_setting("pagetitle_bg_type")) ? theme_get_setting("pagetitle_bg_type") : "pattern",
      '#states' => array(
        'visible' => array(
          ':input[name="pagetitle_customize"]' => array('checked' =>  true),
        ),
      ),
    );


    // Parallax Settings
    // --------------------------------------------------------------

    $Background["pagetitle_parallax_xpos"] = array(
      '#type' => 'textfield',
      '#title' => t("X Position"),
      '#size' => 60,
      '#maxlength' => 7,
      '#default_value' => (theme_get_setting("pagetitle_parallax_xpos")) ? theme_get_setting("pagetitle_parallax_xpos") : "",
      '#description'   => t("X Position of the background image"),
      '#states' => array(
      'visible' => array(
        ':input[name="pagetitle_bg_type"]' => array('value' =>  'parallax'),
        ),
      ),
    );

    $Background["pagetitle_parallax_speedFactor"] = array(
      '#type' => 'textfield',
      '#title' => t("Speed factor"),
      '#size' => 60,
      '#maxlength' => 7,
      '#default_value' => (theme_get_setting("pagetitle_parallax_speedFactor")) ? theme_get_setting("pagetitle_parallax_speedFactor") : "",
      '#description'   => t("Speed factor of the background image."),
      '#states' => array(
      'visible' => array(
        ':input[name="pagetitle_bg_type"]' => array('value' =>  'parallax'),
        ),
      ),
    );


    // ------------------------------------------------------------





    $title_bg = theme_get_setting("pagetitle_background");

    $Background['pagetitle_background'] = array(
      '#tree' => TRUE,
      '#title' => t('Title Background Image'),
      '#type' => 'media',
      '#states' => array(
        'visible' => array(
          ':input[name="pagetitle_layout"]' => array('value' =>  "top"),
        ),
      ),
      '#description' => t('The uploaded image will be displayed on the page unless it is marked as "removed".'),
      '#default_value' => array('fid' => $title_bg['fid'] ),
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


  ${$key}[$key.'_padding_container'] = array(
    '#type' => 'container',
    '#states' => array(
      'visible' => array(
        ':input[name="'.$key.'_customize"]' => array('checked' =>  true),
      ),
    ),
    // '#attributes'    => array( 'class' => array('inline-elements six-elements') ),
  );

  $Padding = &${$key}[$key.'_padding_container'];

  $Padding[$key.'_top_padding'] = array(
    '#type' => 'textfield',
    '#title' => t('Title Top Padding'),
    '#default_value' => (theme_get_setting($key.'_top_padding')) ? theme_get_setting($key.'_top_padding') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_top_padding' => array(
                'max'  => (theme_get_setting($key.'_top_padding') > 100) ? theme_get_setting($key.'_top_padding') : 100,
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
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_top_padding"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Top margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
    // '#states' => array(
    //   'visible' => array(
    //     ':input[name="pagetitle_layout"]' => array('value' =>  'top'),
    //   ),
    // ),
  );

  $Padding[$key.'_bottom_padding'] = array(
    '#type' => 'textfield',
    '#title' => t('Title Bottom Padding'),
    '#default_value' => (theme_get_setting($key.'_bottom_padding')) ? theme_get_setting($key.'_bottom_padding') : 0,
    '#field_suffix' => t('px'),
    '#size' => 3,
    '#maxlength' => 4,
    '#attached' => array(
      'js' => array(
        array(
        'data' => array(
          'tbslider' => array(
            'items' => array(
              $key.'_bottom_padding' => array(
                'max'  => (theme_get_setting($key.'_bottom_padding') > 100) ? theme_get_setting($key.'_bottom_padding') : 100,
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
    '#field_prefix' => '<div class="biotic-slider" data-name="'.$key.'_bottom_padding"></div>',
    '#attributes'    => array( 'class' => array('biotic-slider-field') ),
    '#description'   => t("Bottom margin must be a positive number greater than zero and valid CSS unit is <b>px</b>"),
    // '#states' => array(
    //   'visible' => array(
    //     ':input[name="pagetitle_layout"]' => array('value' =>  'top'),
    //   ),
    // ),
  );


} // end foreach
