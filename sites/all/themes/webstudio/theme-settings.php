<?php

// scss_formatter
// scss_formatter_nested (default)
// scss_formatter_compressed
define('SCSS_FORMATTER',"scss_formatter");
define('SCSS_PATH', dirname(__FILE__) . '/includes/scss');

include_once(dirname(__FILE__) . '/includes/bootstrap.inc');
require_once dirname(__FILE__) . '/includes/theme-functions.inc';
require_once dirname(__FILE__) . '/includes/scss.inc.php';

// Delta module Support
global $arguments;
$arguments = arg();

/**
 * Implements hook_form_system_theme_settings_alter() function.
 *
 * @param $form
 *   Nested array of form elements that comprise the form.
 * @param $form_state
 *   A keyed array containing the current state of the form.
 */
function bootstrap_form_system_theme_settings_alter(&$form, $form_state, $form_id = NULL) {

  global $base_path, $webstudio_theme_path,$arguments;
  $webstudio_theme_path = drupal_get_path('theme', 'bootstrap');


  $variables = array(
    'path' => $webstudio_theme_path.'/assets/images/admin-logo-white.png',
    'alt' => 'WebStudio',
    'title' => 'Webstudio ',
    'width' => '135px',
    'height' => 'auto',
    'attributes' => array('class' => 'logo-white'),
  );


  $logoW = theme_image($variables);

  // Work-around for a core bug affecting admin themes. See issue #943212.
  if (isset($form_id)) {
    return;
  }

  /**
   * Get Theme Behaviours
   */
  bootstrap_get_theme_settings();


  // System Libraries
  drupal_add_library('system', 'ui');
  drupal_add_library('system', 'ui.slider');

  drupal_add_css( drupal_get_path('theme','bootstrap'). "/assets/css/admin.css"  );
  drupal_add_js( drupal_get_path('theme','bootstrap'). "/assets/js/theme-settings.js", 'file' );

  drupal_add_js( drupal_get_path('theme','bootstrap'). "/assets/js/vendor/underscore/underscore-min.js", 'file' );

  /* MiniColor */
  drupal_add_css( drupal_get_path('theme','bootstrap'). "/assets/js/vendor/miniColors/jquery.minicolors.css"  );
  drupal_add_js( drupal_get_path('theme','bootstrap'). "/assets/js/vendor/miniColors/jquery.minicolors.js", 'file' );

  /* Bootstrap Switch */
  drupal_add_css( drupal_get_path('theme','bootstrap'). "/assets/js/vendor/bootstrapSwitch/bootstrap-switch.css"  );
  drupal_add_js( drupal_get_path('theme','bootstrap'). "/assets/js/vendor/bootstrapSwitch/bootstrap-switch.js", 'file' );


  $form['tb'] = array(
    '#type' => 'vertical_tabs',
    '#weight' => -10,
    '#prefix' => t('<div id="tb-header">!logo <span> v1.0.0 </span> </div> ',
      array('!logo' => $logoW) )
  );

  if (theme_get_setting('welcome_tab')) {

    $form['tb']['general'] = array(
      '#type'          => 'fieldset',
      '#title'         => t('Welcome'),
      // '#description'   => t("General theme parameters are configured here."),
      '#weight'        => -1,
    );

    $form['tb']['general']['welcome_message'] = array(
      '#markup' => _tb_welcome_message()
    );

    /* Module test table */
    _tb_module_tests($form);

    $form['tb']['general']['welcome_message_note'] = array(
      '#markup' => t("<p><b>Note:</b> You can hide welcome tab under <em>theme development settings</em>, if you don't want to see anymore.</p>")
    );

  }


if (module_exists('devel_themer')) {
  drupal_set_message(t("Theme developer module is active.
    Theme settings <strong>turned off</strong> in order to prevent an unexpected problem.
    Please deactivate the Theme Developer module and try again.
    "), 'warning', FALSE);
}
else {

  /* <!-- Load Plugins
  ================================================== --> */
  foreach (file_scan_directory($webstudio_theme_path . '/plugins', '/theme-settings.inc/i') as $file) {
    require_once($file->uri);
  }

}

$form['tb']['tb_drupal'] = array(
  '#type'          => 'fieldset',
  '#title'         => t('Drupal Core'),
  '#description'   => t("Drupal Core parameters are configured here."),
  '#weight'        => 10,
);

$form['tb']['tb_drupal']['theme_settings'] = $form['theme_settings'];
$form['tb']['tb_drupal']['logo'] = $form['logo'];
$form['tb']['tb_drupal']['favicon'] = $form['favicon'];

$form['tb']['tb_drupal']['theme_settings']['breadcrumb'] = array(
  '#type' => 'checkbox',
  '#title' => t("Breadcrumb"),
  '#default_value' => theme_get_setting('breadcrumb')
);

$form['tb']['tb_drupal']['theme_settings']['mobilemenu'] = array(
  '#type' => 'checkbox',
  '#title' => t("Mobile Menu"),
  '#default_value' => theme_get_setting('mobilemenu')
);

unset($form['theme_settings']);
unset($form['logo']);
unset($form['favicon']);

$form['custom_css'] = array(
  '#type' => 'hidden',
  '#default_value' => theme_get_setting('custom_css'),
  // '#value' => NULL
);

$form['args'] = array('#type' => 'value', '#value' => $arguments );

$form['#submit'][] = 'bootstrap_form_system_theme_settings_alter_submit';

}

/**
 * undocumented function
 *
 * @return void
 * @author
 **/
function bootstrap_form_system_theme_settings_alter_submit($form, &$form_state){

  // $Lock = FALSE;
  $Lock = theme_get_setting('lock', 'bootstrap');

  $CSS = _custom_css_creator($form_state);
  // $CSS = check_plain($CustomCSS);
  $args = $form_state['values']['args'];

  $isDelta = array_search('delta', $args);

  if ($isDelta) {
    $prefix = $args[$isDelta+2]; // return Delta Name
  } else {
    $prefix = "css";
  }


  $exFile = $form_state['values']['custom_css'];


  if ($exFile) {

    $name = str_replace("public://", "", $exFile);
    $name = explode("-", $name);

    if ( $name[0] == $prefix && !$Lock ) {
      file_unmanaged_delete($exFile);
    } elseif ( $name[0] != $prefix && $Lock ) {
      $exFile = FALSE;
    }

  }

  if ($CSS) {

    $hash = user_password(8);

    if ($Lock) {

      $hash = 'locked';

      if ($exFile) {
        $file = $exFile;
      } else {
        $file = "public://".$prefix."-".$hash.".css";
      }



      file_unmanaged_save_data($CSS,$file,FILE_EXISTS_REPLACE);
      drupal_set_message(t("CSS updated on Lock mode ( %file ) ",array('%file'=>$file)), 'status', FALSE);

    } else {

      $file = "public://".$prefix."-".$hash.".css";
      // file_save_data($CSS,$file);
      file_unmanaged_save_data($CSS,$file,FILE_EXISTS_ERROR);

    }

      $form_state['values']['custom_css'] = $file;

  } else {
    $form_state['values']['custom_css'] = NULL;
  }

}

/**
 * undocumented function
 *
 * @return void
 * @author
 **/
function _demo_validate($element, &$form_state){

  if ($element['#value']) {
    $name = str_replace('_customize',"",$element['#name']);
    $c= $form_state['values'][$name."_color"];
    $b = $form_state['values'][$name."_bgc"];
    $h = $form_state['values'][$name."_hover"];
    $l = $form_state['values'][$name."_link"];
    $s = $form_state['values'][$name."_shadow"];
    $br = $form_state['values'][$name."_border"];

    if (!$c && !$b && !$h && !$l && !$s && !$br  ) {
      form_error($element, t('Customization is active for Region @name, but all values ​​are empty.', array('@name' => strtoupper($name) ) ) );
    }
  }
}


/**
 * [_custom_css_creator description]
 * @param  [type] $form_state [description]
 * @return [type]             [description]
 */
function _custom_css_creator(&$form_state){

  global $CSS, $Values;
  $Values = $form_state['values'];

  // Load Features CSS
  foreach (file_scan_directory(drupal_get_path('theme', 'bootstrap') . '/plugins', '/css.inc/i') as $file) {
    include($file->uri);
  }

  return $CSS;

}

/**
 * [_lum description]
 * @param  [type] $hexcolor [description]
 * @return [type]           [description]
 */
function _luminance($hexcolor){
  $r = hexdec(substr($hexcolor,0,2));
  $g = hexdec(substr($hexcolor,2,2));
  $b = hexdec(substr($hexcolor,4,2));
  $yiq = (($r*299)+($g*587)+($b*114))/1000;
  debug("color: ".$hexcolor." yiq: ". $yiq, "YIQ value");
  return ($yiq >= 89) ? 'dark' : 'light';
}
