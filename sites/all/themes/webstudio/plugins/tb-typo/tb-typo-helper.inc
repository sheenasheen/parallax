<?php

global $google_fonts_variant, $google_fonts_subset, $google_fonts_family;

/**
 * [_custom_font_selector description]
 * @param  string $value [description]
 * @return [type]        [description]
 */
function _custom_font_selector($element, &$form_state, $form)
{

  $name = explode("_",$element['#name']);
  $name = $name[0];
  $type = $form_state['values'][$name.'_font_type'];

  if ($type) {
    if (empty($element['#value'])) {
     form_error($element, t( $element['#title'].' is required.'));
    }
  }

}

// $font_file = drupal_get_path('theme', 'bootstrap'). "/plugins/tb-typography/webfonts.json";
// $webfonts = file_get_contents($font_file);
// $google_fonts = json_decode($webfonts);
$google_fonts = _google_fonts_cache();
$google_fonts_family = array();
$google_fonts_variant = array();
$google_fonts_subset = array();

// Fonts
foreach ($google_fonts->items as $font) {
  $google_fonts_family[$font->family] = $font->family;
  // variants...
  foreach ($font->variants as $variant) {
    $variant_key = "";

    $patterns = array();
    $patterns[0] = '/regular/';
    $patterns[1] = '/(\b)italic/';
    $replacements = array();
    $replacements[0] = '400';
    $replacements[1] = '400italic';
    $variant_key = preg_replace($patterns, $replacements, $variant);


    $title = array(
      "Ultra Light",
      "Ultra Light Italic",
      "Light",
      "Light Italic",
      "Book",
      "Book Italic",
      "Regular",
      "Italic",
      "Medium",
      "Medium Italic",
      "Semi Bold",
      "Semi Bold Italic",
      "Bold",
      "Bold Italic",
      "Extra Bold",
      "Extra Bold Italic",
      "Ultra Bold",
      "Ultra Bold Italic"
    );
    $value = array(
      '/(\b)100(\b)/',
      '/(\b)100italic(\b)/',
      '/(\b)200(\b)/',
      '/(\b)200italic(\b)/',
      '/(\b)300(\b)/',
      '/(\b)300italic(\b)/',
      '/(\b)regular(\b)/',
      '/(\b)italic(\b)/',
      '/(\b)500(\b)/',
      '/(\b)500italic(\b)/',
      '/(\b)600(\b)/',
      '/(\b)600italic(\b)/',
      '/(\b)700(\b)/',
      '/(\b)700italic(\b)/',
      '/(\b)800(\b)/',
      '/(\b)800italic(\b)/',
      '/(\b)900(\b)/',
      '/(\b)900italic(\b)/'
    );

    $variant_title = "";
    $variant_title =  preg_replace($value, $title, $variant);

    $google_fonts_variant[$font->family][$variant_key] = $variant_title;
  }

  // Subsets...
  foreach ($font->subsets as $subset) {
    $google_fonts_subset[$font->family][$subset] = $subset;
  }

}
array_unshift($google_fonts_family," ");


/**
 * _font_size function
 *
 * @return array
 *
 **/
function _font_size(){
 $font_size = &drupal_static(__FUNCTION__);
  if (!isset($font_size)) {
    if ($cache = cache_get('biotic_font_size')) {
      $font_size = $cache->data;
    }
    else {
      $font_size = array();
      $size = 8;
      do {
        $font_size[$size] = $size." px";
        $size++;
      } while ( $size <= 70);
      cache_set('biotic_font_size', $font_size, 'cache');
    }
  }
  return $font_size;
}


/**
 * _font_weight function
 *
 * @return array
 *
 **/
function _font_weight(){
  $font_weight = &drupal_static(__FUNCTION__);

  if (!isset($font_weight)) {
    if ($cache = cache_get('biotic_font_weight')) {
      $font_weight = $cache->data;
    }
    else {
      $font_weight = array(
       '100'       =>  "Ultra Light",
       '100italic' =>  "Ultra Light Italic",
       '200'       =>  "Light",
       '200italic' =>  "Light Italic",
       '300'       =>  "Book",
       '300italic' =>  "Book Italic",
       '400'       =>  "Regular",
       '400italic' =>  "Italic",
       '500'       =>  "Medium",
       '500italic' =>  "Medium Italic",
       '600'       =>  "Semi Bold",
       '600italic' =>  "Semi Bold Italic",
       '700'       =>  "Bold",
       '700italic' =>  "Bold Italic",
       '800'       =>  "Extra Bold",
       '800italic' =>  "Extra Bold Italic",
       '900'       =>  "Ultra Bold",
       '900italic' =>  "Ultra Bold Italic"
      );

      cache_set('biotic_font_weight', $font_weight, 'cache');
    }
  }
  return $font_weight;
}


/**
 * _google_fonts_cache function
 *
 * @return array
 *
 **/
function _google_fonts_cache(){
  $google_fonts = &drupal_static(__FUNCTION__);
  if (!isset($google_fonts)) {
    if ($cache = cache_get('biotic_google_fonts')) {
      $google_fonts = $cache->data;
    }
    else {
      $font_file = dirname(__FILE__). "/webfonts.json";
      $webfonts = file_get_contents($font_file);
      $google_fonts = json_decode($webfonts);
      cache_set('biotic_google_fonts', $google_fonts, 'cache');
    }
  }
  return $google_fonts;
}


/**
 * _websafe_gonts_cache function
 *
 * @return array
 *
 **/
function _websafe_fonts_cache(){
 $websafe = &drupal_static(__FUNCTION__);
  if (!isset($websafe)) {
    if ($cache = cache_get('biotic_websafe')) {
      $websafe = $cache->data;
    }
    else {
      $websafe = array(
        '0' => '',
        'Sans Serif' => array(
          'arial'                  => 'Arial',
          'arial-black'            => 'Arial Black',
          'arial-narrow'           => 'Arial Narrow',
          'arial-rounded-mt-bold'  => 'Arial Rounded MT Bold',
          'avant-garde'            => 'Avant Garde',
          'calibri'                => 'Calibri',
          'candara'                => 'Candara',
          'century-gothic'         => 'Century Gothic',
          'franklin-gothic-medium' => 'Franklin Gothic Medium',
          'futura'                 => 'Futura',
          'geneva'                 => 'Geneva',
          'gill-sans'              => 'Gill Sans',
          'helvetica'              => 'Helvetica',
          'impact'                 => 'Impact',
          'lucida grande'          => 'Lucida Grande',
          'optima'                 => 'Optima',
          'segoe-ui'               => 'Segoe UI',
          'tahoma'                 => 'Tahoma',
          'trebuchet-ms'           => 'Trebuchet MS',
          'verdana'                => 'Verdana',
        ),
        'Serif' => array(
          'baskerville'         => 'Baskerville',
          'big-caslon'          => 'Big Caslon',
          'bodoni-mt'           => 'Bodoni MT',
          'book-antiqua'        => 'Book Antiqua',
          'calisto-mt'          => 'Calisto MT',
          'cambria'             => 'Cambria',
          'didot'               => 'Didot',
          'garamond'            => 'Garamond',
          'georgia'             => 'Georgia',
          'goudy-old-style'     => 'Goudy Old Style',
          'hoefler-text'        => 'Hoefler Text',
          'lucida-bright'       => 'Lucida Bright',
          'palatino'            => 'Palatino',
          'perpetua'            => 'Perpetua',
          'rockwell'            => 'Rockwell',
          'rockwell-extra-bold' => 'Rockwell Extra Bold',
          'times-new-roman'     => 'Times New Roman',
          ),
        'Monospaced' => array(
          'andale-mono' => 'Andale Mono',
          'consolas' => 'Consolas',
          'courier-new' => 'Courier New',
          'lucida-console' => 'Lucida Console',
          'lucida-sans-typewriter' => 'Lucida Sans Typewriter',
          'monaco' => 'Monaco',
        ),
      );
      cache_set('biotic_websafe', $websafe, 'cache');
    }
  }
  return $websafe;
}


/**
 * _websafe_font_style_cache function
 *
 * @param [type] [varname] [description]
 * @return void
 *
 **/
function _websafe_font_style_cache(&$font){
  $font_style = &drupal_static(__FUNCTION__);
  if (!isset($font_style)) {
    if ($cache = cache_get('biotic_font_style:'.$font)) {
      $font_style = $cache->data;
    }
    else {
      $ops = array(
        //  Sans Serif
        'arial'                  => 'Arial, "Helvetica Neue", Helvetica, sans-serif',
        'arial-black'            => '"Arial Black", "Arial Bold", Gadget, sans-serif',
        'arial-narrow'           => '"Arial Narrow", Arial, sans-serif',
        'arial-rounded-mt-bold'  => '"Arial Rounded MT Bold", "Helvetica Rounded", Arial, sans-serif',
        'avant-garde'            => '"Avant Garde", Avantgarde, "Century Gothic", CenturyGothic, "AppleGothic", sans-serif',
        'calibri'                => 'Calibri, Candara, Segoe, "Segoe UI", Optima, Arial, sans-serif',
        'candara'                => 'Candara, Calibri, Segoe, "Segoe UI", Optima, Arial, sans-serif',
        'century-gothic'         => '"Century Gothic", CenturyGothic, AppleGothic, sans-serif',
        'franklin-gothic-medium' => '"Franklin Gothic Medium", "Franklin Gothic", "ITC Franklin Gothic", Arial, sans-serif',
        'futura'                 => 'Futura, "Trebuchet MS", Arial, sans-serif',
        'geneva'                 => 'Geneva, Tahoma, Verdana, sans-serif',
        'gill-sans'              => '"Gill Sans", "Gill Sans MT", Calibri, sans-serif',
        'helvetica'              => '"Helvetica Neue", Helvetica, Arial, sans-serif',
        'impact'                 => 'Impact, Haettenschweiler, "Franklin Gothic Bold", Charcoal, "Helvetica Inserat", "Bitstream Vera Sans Bold", "Arial Black", sans serif',
        'lucida grande'          => '"Lucida Grande", "Lucida Sans Unicode", "Lucida Sans", Geneva, Verdana, sans-serif',
        'optima'                 => 'Optima, Segoe, "Segoe UI", Candara, Calibri, Arial, sans-serif',
        'segoe-ui'               => '"Segoe UI", Frutiger, "Frutiger Linotype", "Dejavu Sans", "Helvetica Neue", Arial, sans-serif',
        'tahoma'                 => 'Tahoma, Verdana, Segoe, sans-serif',
        'trebuchet-ms'           => '"Trebuchet MS", "Lucida Grande", "Lucida Sans Unicode", "Lucida Sans", Tahoma, sans-serif',
        'verdana'                => 'Verdana, Geneva, sans-serif',
        //  Serif
        'baskerville'            => 'Baskerville, "Baskerville Old Face", "Hoefler Text", Garamond, "Times New Roman", serif',
        'big-caslon'             => '"Big Caslon", "Book Antiqua", "Palatino Linotype", Georgia, serif',
        'bodoni-mt'              => '"Bodoni MT", Didot, "Didot LT STD", "Hoefler Text", Garamond, "Times New Roman", serif',
        'book-antiqua'           => '"Book Antiqua", Palatino, "Palatino Linotype", "Palatino LT STD", Georgia, serif',
        'calisto-mt'             => '"Calisto MT", "Bookman Old Style", Bookman, "Goudy Old Style", Garamond, "Hoefler Text", "Bitstream Charter", Georgia, serif',
        'cambria'                => 'Cambria, Georgia, serif',
        'didot'                  => 'Didot, "Didot LT STD", "Hoefler Text", Garamond, "Times New Roman", serif',
        'garamond'               => 'Garamond, Baskerville, "Baskerville Old Face", "Hoefler Text", "Times New Roman", serif',
        'georgia'                => 'Georgia, Times, "Times New Roman", serif',
        'goudy-old-style'        => '"Goudy Old Style", Garamond, "Big Caslon", "Times New Roman", serif',
        'hoefler-text'           => '"Hoefler Text", "Baskerville old face", Garamond, "Times New Roman", serif',
        'lucida-bright'          => '"Lucida Bright", Georgia, serif',
        'palatino'               => 'Palatino, "Palatino Linotype", "Palatino LT STD", "Book Antiqua", Georgia, serif',
        'perpetua'               => 'Perpetua, Baskerville, "Big Caslon", "Palatino Linotype", Palatino, "URW Palladio L", "Nimbus Roman No9 L", serif',
        'rockwell'               => 'Rockwell, "Courier Bold", Courier, Georgia, Times, "Times New Roman", serif',
        'rockwell-extra-bold'    => '"Rockwell Extra Bold", "Rockwell Bold", monospace',
        'times-new-roman'        => 'TimesNewRoman, "Times New Roman", Times, Baskerville, Georgia, serif',
        // 'Monospaced'
        'andale-mono'            => '"Andale Mono", AndaleMono, monospace',
        'consolas'               => 'Consolas, monaco, monospace',
        'courier-new'            => '"Courier New", Courier, "Lucida Sans Typewriter", "Lucida Typewriter", monospace',
        'lucida-console'         => '"Lucida Console", "Lucida Sans Typewriter", Monaco, "Bitstream Vera Sans Mono", monospace',
        'lucida-sans-typewriter' => '"Lucida Sans Typewriter", "Lucida Console", Monaco, "Bitstream Vera Sans Mono", monospace',
        'monaco'                 => 'Monaco, Consolas, "Lucida Console", monospace',
      );
      $font_style = $ops[$font];
      cache_set('biotic_font_style:'.$font, $font_style, 'cache');
    }
  }
  return $font_style;
}

/**
 * font_variants_callback
 *
 * @param  $form
 *     An associative array containing the structure of the form.
 * @param  $form_state
 *     The current state of the form.
 * @return $element
 *     The form array.
 *
 */
function font_variants_callback($form, $form_state) {

  $form_state['cache']= true;

  $trigger_name = $form_state['triggering_element']['#name'];
  $array_parents = $form_state['triggering_element']['#array_parents'];
  $tname = explode("_",$trigger_name);
  $element_name = (string)$tname['0'];
  array_pop($array_parents);

// Iterate over the form parents to find the element.
  $element = $form;
  foreach ($array_parents as $name) {
    $element = &$element[$name];
  }

  // $parrent = $array_parents[count($array_parents)-2];
  // $element[] = $form['tb']['tb_typography'][$parrent][$name[0].'_ajax_con'];

  return  $element[$element_name.'_ajax_con'];
}

/**
 * _font_style_options
 *
 * @param  string $key
 * @return array
 *
 */
function _font_style_options($key = '') {
  if (empty($key)) {
    return array("400"=>"Regular");
  }
  global $google_fonts_variant ;
  $options = $google_fonts_variant;
  if (isset($options[$key])) {
    return $options[$key];
  }else {
    return array();
  }
}


/**
 * _font_subset_options
 *
 * @param  string $key
 * @return array
 *
 */
function _font_subset_options($key = '') {
  global $google_fonts_subset ;
  $options = $google_fonts_subset;
  if (empty($key)) {
    return array("latin"=>"latin");
  }
  if ( !empty($key) && isset($options[$key])) {
    return $options[$key];
  }else {
    return array();
  }
}


/**
 * _get_google_font_css function
 *
 * @return void
 * @author
 **/
function _get_google_font_css($Values){

  $theme_settings = $Values;

  $FontCSS = array();

  if (!isset($theme_settings)) {
    # code...
    return false;
  }

  foreach (array_keys($theme_settings) as $k) {
    if (preg_match('/\w*font_google$/', $k)) {

      // $setting = theme_get_setting($k);
      $set = explode("_", $k,2);
      $set_name = $set[0];

if ( $Values[$set_name."_font_type"] == "google"  ) {

      $font = $Values[$k];
      if (!$font) {continue;}
      $weight = $Values[$set_name."_font_google_weight"];
      $selector = $Values[$set_name."_selector"];
      // $size = theme_get_setting($set_name."_font_size");
      $size =  $Values[$set_name."_font_google_size"];

      $italic = false;
      if (strpos($weight,'italic') !== false) {
        $italic = true;
        $weight = str_replace("italic", "", $weight);
      }

      $FontCSS[$set_name] = array(
        'font'  => $font,
        'size'  => $size,
        'weight' => $weight,
        'italic' => $italic,
        'selector' => $selector ,
      );
}
    }
  }

  // debug($FontCSS);
  return $FontCSS;
}


/**
 * _get_websafe_font_css function
 *
 * @return void
 * @author
 **/
function _get_websafe_font_css($Values){

  $theme_settings = $Values;

  $FontCSS = array();

  if (!isset($theme_settings)) {
    # code...
    return false;
  }

  foreach (array_keys($theme_settings) as $k) {
    if (preg_match('/\w*font_websafe$/', $k)) {

      // $setting = theme_get_setting($k);
      $set = explode("_", $k,2);
      $set_name = $set[0];
      if ( $Values[$set_name."_font_type"] == "websafe"  ) {
          $font = $Values[$k];
          if (!$font) {continue;}

          $selector = $Values[$set_name."_selector"];
          $size = $Values[$set_name."_font_websafe_size"];
          $style = _websafe_font_style_cache($font);
          $weight =  $Values[$set_name."_font_websafe_weight"];

          $italic = false;
          if (strpos($weight,'italic') !== false) {
            $italic = true;
            $weight = str_replace("italic", "", $weight);
            if ($weight=="italic") {
              $weight = "normal";
            }
          }
          if ($weight=="regular") {$weight = "normal";}

          $FontCSS[$set_name] = array(
            'font'  => $style,
            'italic' => $italic,
            'selector' => $selector,
            'size' => $size,
            'weight' => $weight,
          );
      }
    }
  }

  return $FontCSS;
}
