<?php

/**
 * _get_google_fonts function
 *
 * @return array $font_elements
 *         All Google Fonts used in the theme.
 *
 * @todo delta support
 *
 **/
function _get_google_fonts(){

  $theme_settings = variable_get('theme_bootstrap_settings');
  $font_google = array();
  $GFonts = array();
  $Group = array();
  $font_elements = array();

  if (!isset($theme_settings )) {
    return false;
  }

  foreach (array_keys($theme_settings) as $k) {
    if (preg_match('/\w*font_google$/', $k)) {

        // $setting = theme_get_setting($k);
        $set = explode("_", $k,2);
        $set_name = $set[0];

      if ( theme_get_setting($set_name."_font_type") == "google"  ) {

        $font = theme_get_setting($k);
        $style = theme_get_setting($set_name."_font_google_weight");
        $subset = theme_get_setting($set_name."_font_google_subset");

          foreach ($subset as $key => $value){
            if ($subset[$key] == '0'){
                unset($subset[$key]);
            }
          }

        $GFonts[$set_name] = array(
          'font'  => $font,
          'style' => $style,
          'subsets' => $subset,
        );

      }

    }
  }

  foreach ($GFonts as $key => $value) {

    if ( !array_key_exists($value['font'], $Group) ) {
      $Group[$value['font']] = array();
      $Group[$value['font']]['style'] = array();
      $Group[$value['font']]['subset'] = array();
    }

     array_push($Group[$value['font']]['style'], $value['style']);

     foreach ($value['subsets'] as $key) {
       array_push($Group[$value['font']]['subset'], $key);
     }

     $Group[$value['font']]['subset'] = array_unique( $Group[$value['font']]['subset'] );

  }

  foreach ($Group as $key => $value) {
    $font = $key;
    $style = implode(",", $value['style']);
    $subset = implode(",", $value['subset']);
    $element = $font.":".$style.":".$subset;

    $font_elements[] = $element;
  }

  return $font_elements;

}
