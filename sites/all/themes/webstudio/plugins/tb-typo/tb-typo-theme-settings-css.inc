<?php

include_once(dirname(__FILE__) . '/tb-typo-helper.inc');

$scss = new scssc();
// $scss->setImportPaths(dirname(__FILE__));
$scss->setImportPaths(SCSS_PATH);
$scss->setFormatter(SCSS_FORMATTER);

/**
 * Google Fonts
 */
$Googlefontstyles = _get_google_font_css($Values);

if ($Googlefontstyles) {

  foreach ($Googlefontstyles as $key => $value) {

    $Wrapper = $value['selector'];
    $atrs    = ($value['selector'] == "body" || $value['selector'] == "h1" || $value['selector'] == "h2" || $value['selector'] == "h3"  ) ? "false" : "true";
    $font    = $value['font'];
    $weight  = $value['weight'];
    $italic  = ($value['italic']) ? "true": "false";
    $size    = ($value['size']) ? $value['size'] : "false";

$Scheme = <<<GWF
  \$Wrapper: {$Wrapper};
  \$atrs: {$atrs};
  \$font: {$font};
  \$weight: {$weight};
  \$italic: {$italic};
  \$size: {$size};
  @import "Google_fonts";
GWF;

    $CSS .= $scss->compile($Scheme);

  } // end foreach
}// end if


/**
 * Websafe Fonts
 */
$Websafefontstyles = _get_websafe_font_css($Values);
if ($Websafefontstyles) {

  variable_set("Websafefont", true);

  foreach ($Websafefontstyles as $key => $value) {

    $Wrapper = $value['selector'];
    $atrs    = ($value['selector'] == "body" || $value['selector'] == "h1" || $value['selector'] == "h2" || $value['selector'] == "h3"  ) ? "false" : "true";
    $font    = $value['font'];
    $weight  = $value['weight'];
    $italic  = ($value['italic']) ? "true": "false";
    $size    = $value['size'];

$Scheme = <<<WSF
  \$Wrapper: {$Wrapper};
  \$atrs: {$atrs};
  \$font: {$font};
  \$weight: {$weight};
  \$italic: {$italic};
  \$size: {$size};
  @import "Websafe_fonts";
WSF;

    $CSS .= $scss->compile($Scheme);

  }
}else{
  variable_set("Websafefont", false);
}
