<?php

$theme_path = drupal_get_path('theme', 'bootstrap');
require_once $theme_path . '/includes/bootstrap.inc';
require_once $theme_path . '/includes/theme.inc';
require_once $theme_path . '/includes/pager.inc';
require_once $theme_path . '/includes/form.inc';
require_once $theme_path . '/includes/admin.inc';
require_once $theme_path . '/includes/menu.inc';
require_once $theme_path . '/includes/extra.inc';
require_once $theme_path . '/includes/Biotic.class.inc';

// $extra = new extra();
// // $hash = $extra->getGitHash($theme_path."/.git-ftp.log");
// $Gitlog = $extra->getGitLog();

// if ($Gitlog) {
//   define('GITHASH', $Gitlog['branch'].' : '.$Gitlog['hash']);
// }else{
//   define('GITHASH',"");
// }


// Load module specific files in the modules directory.
$includes = file_scan_directory($theme_path . '/includes/modules', '/\.inc$/');
foreach ($includes as $include) {
  if (module_exists($include->name)) {
    require_once $include->uri;
  }
}

/**
 * Load Plugins
 */
foreach (file_scan_directory($theme_path . '/plugins', '/template.inc/i') as $file) {
  require_once($file->uri);
}

// Auto-rebuild the theme registry during theme development.
if (theme_get_setting('bootstrap_rebuild_registry') && !defined('MAINTENANCE_MODE')) {
  // Rebuild .info data.
  system_rebuild_theme_data();
  // Rebuild theme registry.
  drupal_theme_rebuild();
}


/**
 * Implements hook_theme().
 */
function bootstrap_theme(&$existing, $type, $theme, $path) {
  // If we are auto-rebuilding the theme registry, warn about the feature.
  if (
    // Only display for site config admins.
    function_exists('user_access') && user_access('administer site configuration')
    && theme_get_setting('bootstrap_rebuild_registry')
    // Always display in the admin section, otherwise limit to three per hour.
    && (arg(0) == 'admin' || flood_is_allowed($GLOBALS['theme'] . '_rebuild_registry_warning', 3))
  ) {
    flood_register_event($GLOBALS['theme'] . '_rebuild_registry_warning');
    drupal_set_message(t('For easier theme development, the theme registry is being rebuilt on every page request. It is <em>extremely</em> important to <a href="!link">turn off this feature</a> on production websites.', array('!link' => url('admin/appearance/settings/' . $GLOBALS['theme']))), 'warning', FALSE);
  }

  return array(
    'bootstrap_links' => array(
      'variables' => array(
        'links' => array(),
        'attributes' => array(),
        'heading' => NULL
      ),
    ),
    'bootstrap_btn_dropdown' => array(
      'variables' => array(
        'links' => array(),
        'attributes' => array(),
        'type' => NULL
      ),
    ),
    'bootstrap_modal' => array(
      'variables' => array(
        'heading' => '',
        'body' => '',
        'footer' => '',
        'attributes' => array(),
      ),
    ),
    'bootstrap_accordion' => array(
      'variables' => array(
        'id' => '',
        'elements' => array(),
      ),
    ),
    'bootstrap_search_form_wrapper' => array(
      'render element' => 'element',
    ),
    'bootstrap_nav' => array(
      'variables' => array(),
    )
  );
}

/**
 * Override theme_breadrumb().
 *
 * Print breadcrumbs as a list, with separators.
 */
function bootstrap_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {
    $breadcrumbs = '<ul class="breadcrumb">';

    $count = count($breadcrumb) - 1;
    foreach ($breadcrumb as $key => $value) {
      if ($count != $key) {
        $breadcrumbs .= '<li>' . $value . '<span class="divider">/</span></li>';
      }
      else{
        $breadcrumbs .= '<li>' . $value . '</li>';
      }
    }
    $breadcrumbs .= '</ul>';

    return $breadcrumbs;
  }
}


/**
 * Override or insert variables in the html_tag theme function.
 */
function bootstrap_process_html_tag(&$variables) {
  global $base_url, $base_path;
  $tag = &$variables['element'];

  if ($tag['#tag'] == 'style' || $tag['#tag'] == 'script') {
    // Remove redundant type attribute and CDATA comments.
    unset($tag['#attributes']['type'], $tag['#value_prefix'], $tag['#value_suffix']);

    // Remove media="all" but leave others unaffected.
    if (isset($tag['#attributes']['media']) && $tag['#attributes']['media'] === 'all') {
      unset($tag['#attributes']['media']);
    }
  }

}


/**
 * Override or insert variables in the html theme function.
 */
function bootstrap_preprocess_html(&$variables) {

  // Construct page title.
  if (drupal_get_title()) {
    $head_title = array(
      'title' => strip_tags(drupal_get_title()),
      'name' => strip_tags(variable_get('site_name', 'Drupal')),
    );
  }
  else {
    $head_title = array('name' => strip_tags(variable_get('site_name', 'Drupal')));
    if (variable_get('site_slogan', '')) {
      $head_title['slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
  }
  $variables['head_title_array'] = $head_title;
  $variables['head_title'] = implode(' | ', $head_title);


  if (variable_get("Websafefont", FALSE)) {
    $variables['classes_array'][] = "ws";
    drupal_add_js(array('websafefont' => array('status'=>TRUE)), 'setting');
  }

  if (theme_get_setting("header_fixed")) {
    $variables['classes_array'][] = "sticky-header";
    drupal_add_js(array('FixedHeader' => array('status'=>TRUE)), 'setting');
  } else {
    drupal_add_js(array('FixedHeader' => array('status'=>FALSE)), 'setting');
  }

  // Boxed Layout
  if ( theme_get_setting("layout_type") == "boxed" ) {

    $margin = "";

    if ( theme_get_setting("layout_top_margin") ) {
      // Top margin
      $margin_top = theme_get_setting("layout_top_margin");
      $margin .= "margin-top-".$margin_top;
    } else {
      $margin_top = NULL;
    }

    if ( theme_get_setting("layout_bottom_margin") ) {
      // Bottom Margin
      $margin_bottom = theme_get_setting("layout_bottom_margin");
      $margin .= " margin-bottom-".$margin_bottom;
    } else {
      $margin_bottom = NULL;
    }

    $variables['page']['page_top'][] = array('foo' => array('#markup' => '<div id="Boxed" class="'.$margin.'">'));
    $variables['page']['page_bottom'][] = array('foo' => array('#markup' => '</div><!-- end #Boxed -->'));

  }

}


/**
 * Preprocess variables for page.tpl.php
 *
 * @see page.tpl.php
 */
function bootstrap_preprocess_page(&$variables) {

  // Parallax images settings
  $ParallaxImages = array();

  // Regions images settings
  $RegionImages = array();

  // Add some class for logo, sitename, slogan etc.
  $BrandClasses = array();


  // Add information about the number of sidebars.
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['columns'] = 3;
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['columns'] = 2;
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['columns'] = 2;
  }
  else {
    $variables['columns'] = 1;
  }

  // Primary nav
  $variables['primary_nav'] = FALSE;
  if ($variables['main_menu']) {
    // Build links
    $variables['primary_nav'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function
    $variables['primary_nav']['#theme_wrappers'] = array('menu_tree__primary');
  }

  $variables['primary_mobile'] = FALSE;

  if ($variables['main_menu']) {
    // Build links
    $variables['primary_mobile'] = menu_tree(variable_get('menu_main_links_source', 'main-menu'));
    // Provide default theme wrapper function
    $variables['primary_mobile']['#theme_wrappers'] = array('menu_tree__mobile');
  }


  // Secondary nav
  $variables['secondary_nav'] = FALSE;
  if ($variables['secondary_menu']) {
    // Build links
    $variables['secondary_nav'] = menu_tree(variable_get('menu_secondary_links_source', 'user-menu'));
    // Provide default theme wrapper function
    $variables['secondary_nav']['#theme_wrappers'] = array('menu_tree__secondary');
  }

  if ( theme_get_setting('brand_layout') ) {
    $layout = theme_get_setting('brand_layout');
    $variables['brand_layout'] = $layout;
  }else{
    $variables['brand_layout'] = "bootstrap-bedafault-ass";
  }

  if ( theme_get_setting('header_layout') ) {
    $layout = theme_get_setting('header_layout');
    $variables['header_layout'] = $layout;
  }else{
    $variables['header_layout'] = "header-default-raw";
  }

  /* Layout Style */
  if ( theme_get_setting('layout_style') ) {
    $container = "container-".theme_get_setting('layout_style');
    $row       = "row-".theme_get_setting('layout_style');
    $variables['container'] = $container;
    $variables['row'] = $row;
  }else{
    $variables['container'] = "container";
    $variables['row'] = "row";
  }


  // Brand Classes for logo, sitename, slogan etc.
  $BrandClasses[] = ($variables['logo']) ? "sub-logo" : NULL;
  $BrandClasses[] = ($variables['site_name']) ? "sub-sitename" : NULL;
  $BrandClasses[] = ($variables['site_slogan']) ? "sub-slogan" : NULL;
  $variables['brandclasses'] = implode(" ", $BrandClasses);

  /* Mobile menu */
  // $variables['MobileMenu']  = TRUE;
  $variables['MobileMenu']  = theme_get_setting("mobilemenu");

  // <!-- Custom CSS
  // ================================================== -->

  $customCSS = theme_get_setting("custom_css");

  if ($customCSS) {
    drupal_add_css( $customCSS, "file" );
    // debug($customCSS);
  }



  // /* Google fonts */
  $Googlefonts = _get_google_fonts();

  if (count($Googlefonts) > 0) {

    drupal_add_js('http://ajax.googleapis.com/ajax/libs/webfont/1/webfont.js',
      array(
        'type' => 'external',
        'group' => JS_THEME,
        'every_page' => TRUE
      )
    );

    drupal_add_js(array('webfontloader' => array( 'fonts' => $Googlefonts ) ), 'setting');
  }



  if (theme_get_setting('pagetitle_layout') == "top") {
    $variables['PageTitle']   = TRUE;
  }else{
    $variables['PageTitle']   = FALSE;
  }


  if ( theme_get_setting('pagetitle_layout') == "top" &&  theme_get_setting('pagetitle_bg_type') == "fixed" ) {

    $image_url = FALSE;
    $background = theme_get_setting("pagetitle_background");

    if ( $background['fid']  ) {
      $image_file = file_load( $background['fid'] );
      $image      = image_load( $image_file->uri );
      $image_url  = file_create_url( $image->source  );
    }

    $data = array(
      'pageTitle' => array(
        'background' => true,
        'path' => $image_url
      ),
    );

    drupal_add_js( $data , "setting");

  }

  // Parallax Images
  if ( theme_get_setting('pagetitle_layout') == "top" &&  theme_get_setting('pagetitle_bg_type') == 'parallax' ) {

      $xpos = theme_get_setting("pagetitle_parallax_xpos");
      $speedfactor = theme_get_setting("pagetitle_parallax_speedFactor");

      $ParallaxImages += array(
        'pagetitle' => array(
          'id'          => "PageTitleWrapper",
          'xpos'        => $xpos,
          'speedfactor' => $speedfactor
        )
      );

    }


  /**
   * Set Background Image
   * @var [type]
   */
  $bg = theme_get_setting('body_bg_img') ;
  $type = theme_get_setting('body_bg_type');

  if ( $bg['fid'] && $type == "fixed" ) {
    $image_url = FALSE;
    $image_file = file_load( $bg['fid'] );
    $image      = image_load( $image_file->uri );
    $image_url  = file_create_url( $image->source  );

    $data = array(
      'bodyBG' => array(
        'background' => true,
        'path' => $image_url
      ),
    );

    drupal_add_js( $data , "setting");
  }



  /**
   * Set Raw mode for each Region
   * @var array
   */
  $regions = array(
    'brand'         => 'BrandRaw',
    'topbar'        => 'TopBarRaw',
    'header'        => 'HeaderRaw',
    'headerbottom'  => 'HeaderBottomRaw',
    // 'topraw'        => 'TopRaw',
    'intro'         => 'IntroRaw',
    'sidebarfirst'  => 'SidebarFirstRaw',
    'highlighted'   => 'HighlightedRaw',
    'main'          => 'MainRaw',
    'contenttop'    => 'ContentTopRaw',
    'contentbottom' => 'ContentBottomRaw',
    'sidebarsecond' => 'SidebarSecondRaw',
    'mainbottom'    => 'MainBottomRaw',
    'postscript'    => 'PostscriptRaw',
    // 'bottomraw'     => 'BottomRawWrapper',
    'footertop'     => 'FooterTopRaw',
    'footer'        => 'FooterRaw',
    'footerbottom'  => 'FooterBottomRaw'
  );

  foreach ($regions as $key => $value) {
    $variables[$value] = theme_get_setting($key."_raw");
  }

  /**
   * Set Background Image for each Region
   * @var  AllRegions = Html Id
   * [description]
   */

  $Allregions = array(
    'topbar'        => 'TopBarWrapper',
    'header'        => 'HeaderWrapper',
    'headerbottom'  => 'HeaderBottomWrapper',
    'topraw'        => 'TopRawWrapper',
    'intro'         => 'IntroWrapper',
    'sidebarfirst'  => 'SidebarFirst',
    'highlighted'   => 'Highlighted',
    'main'          => 'MainWrapper',
    'contenttop'    => 'ContentTop',
    'contentbottom' => 'ContentBottom',
    'sidebarsecond' => 'SidebarSecond',
    'mainbottom'    => 'MainBottomWrapper',
    'postscript'    => 'PostscriptWrapper',
    'bottomraw'     => 'BottomRawWrapper',
    'footertop'     => 'FooterTopWrapper',
    'footer'        => 'FooterWrapper',
    'footerbottom'  => 'FooterBottomWrapper'
  );

  foreach ($Allregions as $region => $id) {
    // $variables[$value] = theme_get_setting($key."_raw");
    $isBG = theme_get_setting($region.'_setbg');
    $bg_image = theme_get_setting($region.'_setbg_img');
    $bg_type = theme_get_setting($region.'_setbg_type');
    $image_url = FALSE;

    // Fixed Background
    if ($isBG && $bg_type == 'fixed' && $bg_image['fid']  ) {
      $image_file = file_load( $bg_image['fid'] );
      $image      = image_load( $image_file->uri );
      $image_url  = file_create_url( $image->source  );

      $RegionImages += array(
        $region => array(
          'id' => $id,
          'path' => $image_url
        )
      );

    }


    // Parallax Images
    if ($isBG && $bg_type == 'parallax' && $bg_image['fid']) {

      $xpos = theme_get_setting($region."_setbg_parallax_xpos");
      $speedfactor = theme_get_setting($region."_setbg_parallax_speedFactor");

      $ParallaxImages += array(
        $region => array(
          'id'          => $id,
          'xpos'        => $xpos,
          'speedfactor' => $speedfactor
        )
      );

    }


  } // end foreach


  // <!-- Region Background Fixed image
  // ================================================== -->
  if ( count($RegionImages) ) {
    $data = array(
      'RegionsBG' => array('regions' => $RegionImages),
    );
    drupal_add_js( $data , "setting");
  }

  // <!-- Region Background Parallax
  // ================================================== -->
  if ( count($ParallaxImages) ) {
    $data = array(
      'parallax' => array('regions' => $ParallaxImages),
    );
    drupal_add_js( $data , "setting");
  }

}

/**
 * Bootstrap theme wrapper function for the primary menu links
 */
function bootstrap_menu_tree__primary(&$variables) {
  return '<ul class="mainmenu inline nav pull-left">' . $variables['tree'] . '</ul>';
}

function bootstrap_menu_tree__mobile(&$variables){
  $source = $variables['tree'];
  $source = preg_replace('/ dropdown/', '', $source);
  $source = preg_replace('/dropdown-menu/', '', $source);
  $source = preg_replace('/<span class="caret"><\/span>/', '', $source);
  $source = preg_replace('/<i class="icon-angle-down"><\/i>/', '', $source);
  $source = preg_replace('/style=".*?"/', '', $source);
  $source = preg_replace('/data-toggle=".*?"/', '', $source);
  $source = preg_replace('/data-target=".*?"/', '', $source);
  return '<ul class="mobile">' . $source . '</ul>';
}

/**
 * Bootstrap theme wrapper function for the secondary menu links
 */
function bootstrap_menu_tree__secondary(&$variables) {
  return '<ul class="menu nav pull-right">' . $variables['tree'] . '</ul>';
}

function bootstrap_menu_tree__menu_demo(&$variables) {
  return '<ul class="menu ">' . $variables['tree'] . '</ul>';
}

function bootstrap_menu_tree__user_menu($variables) {
  $output = '';
  $output .= '<div id="user-menu" class="btn-group">';
  $output .= '<a class="btn btn-success dropdown-toggle" data-toggle="dropdown" href="#">User menu<span class="caret"></span></a>';
  $output .= '<ul class="dropdown-menu">' . $variables['tree'] . '</ul></div>';
  return $output;
}

/**
 * Returns HTML for a single local action link.
 *
 * This function overrides theme_menu_local_action() to add the icons that ship
 * with Bootstrap to the action links.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: A render element containing:
 *     - #link: A menu link array with "title", "href", "localized_options", and
 *       "icon" keys. If "icon" is not passed, it defaults to "plus-sign".
 *
 * @ingroup themeable
 *
 * @see theme_menu_local_action().
 */
function bootstrap_menu_local_action($variables) {
  $link = $variables['element']['#link'];

  // Build the icon rendering element.
  if (empty($link['icon'])) {
    $link['icon'] = 'plus-sign';
  }
  $icon = '<i class="' . drupal_clean_css_identifier('icon-' . $link['icon']) . '"></i>';

  // Format the action link.
  $output = '<li>';
  if (isset($link['href'])) {
    $options = isset($link['localized_options']) ? $link['localized_options'] : array();

    // If the title is not HTML, sanitize it.
    if (empty($link['localized_options']['html'])) {
      $link['title'] = check_plain($link['title']);
    }

    // Force HTML so we can add the icon rendering element.
    $options['html'] = TRUE;
    $output .= l($icon . $link['title'], $link['href'], $options);
  }
  elseif (!empty($link['localized_options']['html'])) {
    $output .= $icon . $link['title'];
  }
  else {
    $output .= $icon . check_plain($link['title']);
  }
  $output .= "</li>\n";

  return $output;
}

/**
 * Preprocess variables for node.tpl.php
 *
 * @see node.tpl.php
 */
function bootstrap_preprocess_node(&$variables) {

  // if ($variables['teaser']) {
  //   $variables['classes_array'][] = 'row-fluid';
  // }
  //

  // $variables['content']['links']['node']['#links']['node-readmore']['attributes']['class'][] = "btn";

  // dpm($variables);

  $variables['title_attributes_array']['class'][] = "node-title";


  // Portfolio type variables
  if ($variables['type'] == "portfolio") {

    if( $variables['view_mode'] == 'teaser') {
      $variables['theme_hook_suggestions'][] = 'node__' . "portfolio". '__teaser';
    }

    $node = node_load( $variables['nid'] );
    $field = field_get_items('node', $node, 'field_portfolio_template');
    $field_value = field_view_value('node', $node, 'field_portfolio_template', $field[0]);
    $output = render($field_value);

    if (!empty($output)) {
      $extra = new extra;
      $template = $extra->camelCase( $output , array(), FALSE  );
      $variables['theme_hook_suggestions'][] = 'node__' . "portfolio_" .$template;
      if( $variables['view_mode'] == 'teaser') {
        $variables['theme_hook_suggestions'][] = 'node__' . "portfolio_". $template . '__teaser';
      }
    }

  }

}

function bootstrap_links(&$variables){

  if (isset($variables['links']['blog_usernames_blog'])) {

    $variables['links']['blog_usernames_blog']['html'] = TRUE;
    $variables['links']['blog_usernames_blog']['title'] = '<i class="icon-user"></i>' . " " . $variables['links']['blog_usernames_blog']['title'] ;

    if ($variables['links']['blog_usernames_blog']['href'] == "blog/0") {
      if (theme_get_setting('hide_anonymous')) {
        unset( $variables['links']['blog_usernames_blog'] );
      }

    }

  }

  if ( isset($variables['links']['comment-add']) ) {
    $variables['links']['comment-add']['html'] = TRUE;
    $variables['links']['comment-add']['title'] = '<i class="icon-plus-sign"></i>' . " " . $variables['links']['comment-add']['title'];
  }

  if (isset($variables['links']['comment-comments'])) {
    $variables['links']['comment-comments']['html'] = TRUE;
    $variables['links']['comment-comments']['title'] = '<i class="icon-comments"></i>' . " " . $variables['links']['comment-comments']['title'];
  }

  if (isset($variables['links']['node-readmore'])) {
    // $variables['links']['node-readmore']['title'] .= " ".'<span class="padding-left-5"><i class="icon-share-alt"></i></span>';
    $variables['links']['node-readmore']['attributes']['class'][] = "btn btn-small";
  }


  $links = array_reverse($variables['links']);
  $attributes = $variables['attributes'];
  $heading = $variables['heading'];
  global $language_url;
  $output = '';

  if (count($links) > 0) {
    $output = '';

    // Treat the heading first if it is present to prepend it to the
    // list of links.
    if (!empty($heading)) {
      if (is_string($heading)) {
        // Prepare the array that will be used when the passed heading
        // is a string.
        $heading = array(
          'text' => $heading,

          // Set the default level of the heading.
          'level' => 'h2',
        );
      }
      $output .= '<' . $heading['level'];
      if (!empty($heading['class'])) {
        $output .= drupal_attributes(array('class' => $heading['class']));
      }
      $output .= '>' . check_plain($heading['text']) . '</' . $heading['level'] . '>';
    }

    $output .= '<ul' . drupal_attributes($attributes) . '>';

    $num_links = count($links);
    $i = 1;

    foreach ($links as $key => $link) {
      $class = array($key);

      // Add first, last and active classes to the list of links to help out themers.
      if ($i == 1) {
        $class[] = 'first';
      }
      if ($i == $num_links) {
        $class[] = 'last';
      }
      if (isset($link['href']) && ($link['href'] == $_GET['q'] || ($link['href'] == '<front>' && drupal_is_front_page())) && (empty($link['language']) || $link['language']->language == $language_url->language)) {
        $class[] = 'active';
      }
      $output .= '<li' . drupal_attributes(array('class' => $class)) . '>';

      if (isset($link['href'])) {
        // Pass in $link as $options, they share the same keys.
        $output .= l($link['title'], $link['href'], $link);
      }
      elseif (!empty($link['title'])) {
        // Some links are actually not links, but we wrap these in <span> for adding title and class attributes.
        if (empty($link['html'])) {
          $link['title'] = check_plain($link['title']);
        }
        $span_attributes = '';
        if (isset($link['attributes'])) {
          $span_attributes = drupal_attributes($link['attributes']);
        }
        $output .= '<span' . $span_attributes . '>' . $link['title'] . '</span>';
      }

      $i++;
      $output .= "</li>\n";
    }

    $output .= '</ul>';
  }

  return $output;


}



/**
 * Preprocess variables for region.tpl.php
 *
 * @see region.tpl.php
 */
function bootstrap_preprocess_region(&$variables, $hook) {

  /* Layout Style */
  if ( theme_get_setting('layout_style') ) {
    $container = "container-".theme_get_setting('layout_style');
    $row       = "row-".theme_get_setting('layout_style');
    $variables['container'] = $container;
    $variables['row'] = $row;
  }else{
    $variables['container'] = "container";
    $variables['row'] = "row";
  }



  if ($variables['region'] == 'content') {
    $variables['theme_hook_suggestions'][] = 'region__no_wrapper';
  }


  /* Top bar */
  if ($variables['region'] == "top_bar") {

    $str = $variables['region'];
    $raw = theme_get_setting($str."_raw");

    if ($raw) {
      $variables['theme_hook_suggestions'][] = 'region__top_bar_raw';
    }

  }

}


/**
 * Preprocess variables for block.tpl.php
 *
 * @see block.tpl.php
 */
function bootstrap_preprocess_block(&$variables, $hook) {
  //$variables['classes_array'][] = 'row';
  // Use a bare template for the page's main content.
  if ($variables['block_html_id'] == 'block-system-main') {
    $variables['theme_hook_suggestions'][] = 'block__no_wrapper';
  }

  $variables['title_attributes_array']['class'][] = 'block-title';
  // $variables['classes_array'][] = 'clearfix';

  if ($variables['block_html_id'] == 'block-blog-recent') {
    // dpm($variables);
  }

}


/**
 * Returns HTML for a list of recent comments to be displayed in the comment block.
 *
 * @ingroup themeable
 */
function bootstrap_comment_block() {

  $icon = '<i class="icon-li icon-comments-alt muted"></i>';

  $items = array();
  $number = variable_get('comment_block_count', 10);

  foreach (comment_get_recent($number) as $comment) {
    $items[] = $icon.l($comment->subject, 'comment/' . $comment->cid, array('fragment' => 'comment-' . $comment->cid)) . "\n".
    '<div class="muted">' . t('@time ago', array('@time' => format_interval(REQUEST_TIME - $comment->changed))) . '</div>';
  }

  if ($items) {
    return theme('bootstrap_nav', array(
      'items'      => $items,
      'type'       => 'ul',
      'attributes' => array(
        'class'    => array("icons-ul"),
        ),
      )
    );
  }

  else {
    return t('No comments available.');
  }

}





/**
 * Override or insert variables into the block templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("block" in this case.)
 */
function bootstrap_process_block(&$variables, $hook) {
  // Drupal 7 should use a $title variable instead of $block->subject.
  $variables['title'] = $variables['block']->subject;

  if ($variables['block_html_id'] == 'block-blog-recent') {
    // dpm($variables);
  }


}

/**
 * Returns the correct span class for a region
 */
function _bootstrap_content_span($columns = 1) {
  $class = FALSE;

  switch($columns) {
    case 1:
      $class = 'span12';
      break;
    case 2:
      $class = 'span9';
      break;
    case 3:
      $class = 'span6';
      break;
  }

  return $class;
}

/**
 * Adds the search form's submit button right after the input element.
 *
 * @ingroup themable
 */
function bootstrap_bootstrap_search_form_wrapper(&$variables) {
  $output = '<div class="input-append">';
  $output .= $variables['element']['#children'];
  $output .= '<button type="submit" class="btn">';
  $output .= '<i class="icon-search"></i>';
  $output .= '<span class="element-invisible">' . t('Search') . '</span>';
  $output .= '</button>';
  $output .= '</div>';
  return $output;
 }


// function bootstrap_field__field_portfolio_category__portfolio($variables){
//   $cont = render($variables['element'][0]);
//   dpm($variables);
//   return $cont;
// }

function bootstrap_preprocess_field(&$variables) {

  // <!-- Portflio Fields
  // ================================================== -->

  if($variables['element']['#field_name'] == 'field_portfolio_category') {
    $variables['classes_array'] = array('portfolio-category');
  }

}

/**
 * [bootstrap_field__field_portfolio_images__portfolio description]
 * @param  [type] $variables [description]
 * @return [type]            [description]
 */
function bootstrap_field__field_portfolio_images__portfolio($variables){

  // dpm($variables);

  $count = count(element_children($variables['items']));
  $output = '';

  if ( $count==1 ) {
    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }

    // Render the items.
    $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
      $classes = 'field-item ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<div class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</div>';
    }
    $output .= '</div>';

    // Render the top-level DIV.
    $output = '<div class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</div>';

  }

  /**
   * If Portfolio Image fields contains more than one image, then create slideshow.
   */
  else {

    $variables['classes'] = "PortfolioSlideshow unstyled";

    // Render the label, if it's not hidden.
    if (!$variables['label_hidden']) {
      $output .= '<div class="field-label"' . $variables['title_attributes'] . '>' . $variables['label'] . ':&nbsp;</div>';
    }

    // Render the items.
    // $output .= '<div class="field-items"' . $variables['content_attributes'] . '>';
    foreach ($variables['items'] as $delta => $item) {
      $classes = 'field-item field-type-image ' . ($delta % 2 ? 'odd' : 'even');
      $output .= '<li class="' . $classes . '"' . $variables['item_attributes'][$delta] . '>' . drupal_render($item) . '</li>';
    }
    // $output .= '</div>';

    // Render the top-level DIV.
    $output = '<ul class="' . $variables['classes'] . '"' . $variables['attributes'] . '>' . $output . '</ul>';

  }

  return $output;

}


/**
 * Returns HTML for an image using a specific Colorbox image style.
 *
 * @param $variables
 *   An associative array containing:
 *   - image: image item as array.
 *   - path: The path of the image that should be displayed in the Colorbox.
 *   - title: The title text that will be used as a caption in the Colorbox.
 *   - gid: Gallery id for Colorbox image grouping.
 *
 * @ingroup themeable
 */
function bootstrap_colorbox_imagefield($variables) {

  $class = array('colorbox');

  if ($variables['image']['style_name'] == 'hide') {
    $image = '';
    $class[] = 'js-hide';
  }
  elseif (!empty($variables['image']['style_name'])) {
    $image = theme('image_style', $variables['image']);
  }
  else {
    $image = theme('image', $variables['image']);
  }

  $class[] = 'thumbnail';

  $options = array(
    'html' => TRUE,
    'attributes' => array(
      'title' => $variables['title'],
      'class' => $class,
      'rel' => $variables['gid'],
    )
  );

  return l($image, $variables['path'], $options);
}
