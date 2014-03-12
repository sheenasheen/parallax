<?php

$scss = new scssc();
// $scss->setImportPaths(dirname(__FILE__));
$scss->setImportPaths(SCSS_PATH);
$scss->setFormatter(SCSS_FORMATTER);


$Boxed = array(
  'box' => 'Boxed',
);

foreach ($Boxed as $key => $value) {

  if ( $Values[$key."_customize"] && $Values['layout_type'] == "boxed" ) {
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

  @import "Scheme.scss";
CS;

    if ( $bgc || $color || $hover || $link || $shadow || $border ) {
      $CSS .= $scss->compile($Scheme);
    }

  }


}


 if ( $Values["pagetitle_layout"] == "top" && $Values['pagetitle_customize'] ) {

  $Wrapper = "PageTitleWrapper";
  $atrs    = "true";
  $image_url = FALSE;

  $background = $Values["pagetitle_background"];

    if ( $background['fid']  ) {
      $image_file = file_load( $background['fid'] );
      $image      = image_load( $image_file->uri );
      $image_url  = file_create_url( $image->source  );
    }

  //Background image path
  $bip     = ($image_url) ? '"'.$image_url.'"': "false";


  $top_padding = ($Values["pagetitle_top_padding"]) ? $Values["pagetitle_top_padding"] : "false";
  $bottom_padding = ($Values["pagetitle_bottom_padding"]) ? $Values["pagetitle_bottom_padding"] : "false";


  $region  = "pagetitle";

  //Background
  $bgc     = ($Values[$region."_bgc"]) ? $Values[$region."_bgc"] : "false";
  $bop     = ($Values[$region."_bgc_op"]) ? $Values[$region."_bgc_op"] : "false";

  $bgt     = ($Values[$region."_bg_type"]) ? $Values[$region."_bg_type"] : "false";

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

  \$top: {$top_padding};
  \$bottom: {$bottom_padding};

  \$c  : {$color};
  \$cop: {$cop};

  \$b  : {$bgc} ;
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

  @import "PageTitle.scss";
CS;

    if ( $bip || $top_padding || $bottom_padding || $bgc || $color || $hover || $link || $shadow || $border  ) {
      $CSS .= $scss->compile($Scheme);
    }

 }
