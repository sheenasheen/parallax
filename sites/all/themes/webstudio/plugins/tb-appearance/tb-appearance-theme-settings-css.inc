<?php

$scss = new scssc();
// $scss->setImportPaths(dirname(__FILE__));
$scss->setImportPaths(SCSS_PATH);
$scss->setFormatter(SCSS_FORMATTER);



$Globals = array(
  'brand'        => 'GlobalBrand',
);

foreach ($Globals as $key => $value) {

  if ( $Values[$key."_customize"] ) {
    // $src = NULL;
    $Wrapper = $value;
    $atrs    = "true";
    $region  = $key;

    //Background
    $bgc     = ($Values[$region."_bgc"]) ? $Values[$region."_bgc"] : "false";
    $bop     = ($Values[$region."_bgc_op"]) ? $Values[$region."_bgc_op"] : "false";

    //Color
    $color   = ($Values[$region."_color"]) ? $Values[$region."_color"]: "false";
    $cop     = ($Values[$region."_color_op"]) ? $Values[$region."_color_op"] : "false";

    //Link & Hover
    $hover   = ($Values[$region."_hover"]) ? $Values[$region."_hover"] : "false";
    $hop     = ($Values[$region."_hover_op"]) ? $Values[$region."_hover_op"] : "false";

    $link    = ($Values[$region."_link"]) ? $Values[$region."_link"]: "false";
    $lop     = ($Values[$region."_link_op"]) ? $Values[$region."_link_op"]: "false";

    // Text Shadow
    $shadow  = ($Values[$region."_shadow"]) ? $Values[$region."_shadow"] : "false";
    $sop     = ($Values[$region."_shadow_op"]) ? $Values[$region."_shadow_op"] : "false";

    // Border
    $border  = ($Values[$region."_border"]) ? $Values[$region."_border"] : "false";
    $bro     = ($Values[$region."_border_op"]) ? $Values[$region."_border_op"] : "false";

    // Scale
    $scale = ($Values[$region."_scale"]) ? $Values[$region."_scale"] : "false";


$Scheme = <<<CS
  \$Wrapper: {$Wrapper};
  \$atrs: {$atrs};
  \$c  : {$color};
  \$cop: {$cop};

  \$b  : {$bgc} ;
  \$bop: {$bop};

  \$h  : {$hover};
  \$hop: {$hop};

  \$l  : {$link};
  \$lop: {$lop};

  \$s  : {$shadow};
  \$sop: {$sop};

  \$br : {$border} !default;
  \$bro: {$bro};

  \$scale: {$scale};

  @import "Brand";
CS;

    if ( $bgc || $color || $hover || $link || $shadow || $border ) {
      $CSS .= $scss->compile($Scheme);
    }

  }


 // <!-- Metrics
  // ================================================== -->
  //
  if ( $Values[$key."_metrics"] ) {

    $Wrapper = $value;
    $atrs    = "true";
    $region  = $key;

    // Paddings
    $PT = ($Values[$region."_padding_top"]) ? $Values[$region."_padding_top"] : "false";
    $PB = ($Values[$region."_padding_bottom"]) ? $Values[$region."_padding_bottom"] : "false";
    $PL = ($Values[$region."_padding_left"]) ? $Values[$region."_padding_left"] : "false";
    $PR = ($Values[$region."_padding_right"]) ? $Values[$region."_padding_right"] : "false";
    // Margins
    $MT = ($Values[$region."_margin_top"]) ? $Values[$region."_margin_top"] : "false";
    $MB = ($Values[$region."_margin_bottom"]) ? $Values[$region."_margin_bottom"] : "false";
    $ML = ($Values[$region."_margin_left"]) ? $Values[$region."_margin_left"] : "false";
    $MR = ($Values[$region."_margin_right"]) ? $Values[$region."_margin_right"] : "false";

    $Scheme = <<<MTRS
  \$Wrapper: {$Wrapper};
  \$atrs: {$atrs};

  \$pt: {$PT};
  \$pb: {$PB};
  \$pl: {$PL};
  \$pr: {$PR};

  \$mt: {$MT};
  \$mb: {$MB};
  \$ml: {$ML};
  \$mr: {$MR};

  @import "Metrics";
MTRS;

    $CSS .= $scss->compile($Scheme);


  }


}


// <!-- Body CSS
// ================================================== -->


// $background = $Values['background_image'];

//   if ( $background['fid'] ) {
//     # code...
//   $image_file = file_load( $background['fid'] );
//   $image      = image_load( $image_file->uri );
//   $image_url  = file_create_url( $image->source  );

//   $CSS .= <<<BGC
//     body {
//       background: url({$image_url}) repeat left top transparent;
//     }
// BGC;

//   }


$Body = array(
  'body' => 'body',
);

foreach ($Body as $key => $value) {

  if ( $Values[$key."_customize"] ) {
    // $src = NULL;
    $Wrapper = "html ".$value;
    $atrs    = "false";
    $region  = $key;
    $image_url = FALSE;

    $background = $Values[$key."_bg_img"];

    if ( $background['fid']  ) {
      $image_file = file_load( $background['fid'] );
      $image      = image_load( $image_file->uri );
      $image_url  = file_create_url( $image->source  );
    }

    //Background
    $bgc     = ($Values[$region."_bgc"]) ? $Values[$region."_bgc"] : "false";
    $bop     = ($Values[$region."_bgc_op"]) ? $Values[$region."_bgc_op"] : "false";

    $bgt     = ($Values[$region."_bg_type"]) ? $Values[$region."_bg_type"] : "false";

    //Background image path
    $bip     = ($image_url) ? '"'.$image_url.'"': "false";

    //Color
    $color   = ($Values[$region."_color"]) ? $Values[$region."_color"]: "false";
    $cop     = ($Values[$region."_color_op"]) ? $Values[$region."_color_op"] : "false";

    //Link & Hover
    $hover   = ($Values[$region."_hover"]) ? $Values[$region."_hover"] : "false";
    $hop     = ($Values[$region."_hover_op"]) ? $Values[$region."_hover_op"] : "false";

    $link    = ($Values[$region."_link"]) ? $Values[$region."_link"]: "false";
    $lop     = ($Values[$region."_link_op"]) ? $Values[$region."_link_op"]: "false";

    // Text Shadow
    $shadow  = ($Values[$region."_shadow"]) ? $Values[$region."_shadow"] : "false";
    $sop     = ($Values[$region."_shadow_op"]) ? $Values[$region."_shadow_op"] : "false";

    // Border
    $border  = ($Values[$region."_border"]) ? $Values[$region."_border"] : "false";
    $bro     = ($Values[$region."_border_op"]) ? $Values[$region."_border_op"] : "false";


$Scheme = <<<CS
  \$Wrapper: {$Wrapper};
  \$atrs: {$atrs};
  \$c  : {$color};
  \$cop: {$cop};

  \$b  : {$bgc};
  \$bop: {$bop};
  \$bip: {$bip};
  \$bgt: {$bgt};

  \$h  : {$hover};
  \$hop: {$hop};

  \$l  : {$link};
  \$lop: {$lop};

  \$s  : {$shadow};
  \$sop: {$sop};

  \$br : {$border} !default;
  \$bro: {$bro};

  @import "Scheme";
  @import "BodyBG";

CS;

    if ( $bgc || $color || $hover || $link || $shadow || $border ) {
      $CSS .= $scss->compile($Scheme);
    }

  }

}