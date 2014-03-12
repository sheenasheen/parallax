<?php



function bootstrap_get_theme_settings($theme="bootstrap"){

  // Typo settings
  $show_font_variant = (theme_get_setting("show_font_variant")) ?  TRUE : FALSE;
  drupal_add_js(
    array(
    'theme_settings' => array(
      'show_font_variant'=>$show_font_variant),

    ), "setting"
  );
}


/**
 * _tb_module_tests function
 *
 * @return void
 * @author
 **/
function _tb_module_tests(&$form){
  global $files_path, $base_path, $base_url ,$base_theme_info;
  $contrib = array(
    'block_class',
    'colorbox',
    'exclude_node_title',
    'jquery_update',
    'libraries',
    'submitted_by',
    'media',
  );
  asort($contrib);

  $mods = array();
  $defaults = array();
  foreach ($contrib as $key => $value) {
    $mods[] = array(
      'mid' => $key+1,
      'name' => $value,
      'status' => (module_exists($value)) ? "Enable" : "Disable"
    );
    if (module_exists($value)) {
      $defaults[$key+1] = TRUE;
    }

  }

  $header = array(
    'name' => t('Module Name'),
    'status' => t('Status'),
    'info'  => t('Info')
  );

  $options = array();
  $attributes['target'] = "_blank";
  $Enable['path'] = $base_url."/misc/watchdog-ok.png";
  $Disable['path'] = $base_url."/misc/watchdog-error.png";
  $txtEnable = "Info";
  $txtDisable= "Download";
  foreach($mods as $mod){
    $options[$mod['mid']] =array(
      'name' => $mod['name'],
      'status' => theme('image', ${$mod['status']} ) ,
      'info'   => t('<a target="_blank" href="http://drupal.org/project/@name">@text</a>', array('@text'=>${"txt".$mod['status']},'@name' => $mod['name'] ))
    );
  }

  $form['tb']['general']['mymodules'] = array(
    '#type' => 'tableselect',
    '#header' => $header,
    '#options' => $options,
    '#default_value' => $defaults,
    '#disabled' => TRUE,
    '#empty' => t('No module found'),
  );
  // $form['tb']['general']['preview'] = array(
  //   '#type' =>'button',
  //   '#value' => t('Preview'),
  // );


  return $form;
}

/**
 * welcome_message function
 *
 * @return void
 * @author
 **/
function _tb_welcome_message(){


$message = <<< OTL
<h1>Welcome</h1>

<p>Thank you for choosing Themebiotic's premium theme for building your Drupal Web site.<br/>
For any questions or concerns please feel free to email via my user page contact form <a target="_blank"  href="http://themeforest.net/user/themebiotic">here</a>.</p>

<h3>Contrib modules</h3>
<p>For stand-alone installations, you will need to use some contrib modules for use as live preview. There is no obligation to use these modules, but we strongly recommend you to use a more flexible.</p>
<p>Below you will find a list of these modules. If these modules are already installed on your system, they will appear as checked.</p>
OTL;

  return $message;

}

