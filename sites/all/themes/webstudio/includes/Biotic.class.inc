<?php

class Biotic {

  private $Portfolio = "portfolio";
  private $Order = "DESC";
  private $ImageStyle = "medium";
  private $VideoStyle = FALSE;
  private $Limit = 4;
  private $BodyLength = 64;
  private $TitleLength = 16;

  public function __construct()
  {
    # code...
  }

  public function setImageStyle($style)
  {
    return $this->ImageStyle = $style;
  }

  public function setOrder($order)
  {
    return $this->Order = $order;
  }

  public function setLimit($lim)
  {
    return $this->Limit = $lim;
  }

  public function setBodyLength($length)
  {
     return $this->BodyLength = $length;
  }

  public function setTitleLength($length)
  {
    return $this->TitleLength = $length;
  }

  private function videoColorbox( $video=array() )
  {
    $element = array();
    $Style = $this->ImageStyle;

    if (isset($video['thumbnail_path'])) {
      $element = array(
        '#theme' => 'video_embed_field_colorbox_code',
        '#image_url' => $video['thumbnail_path'],
        '#image_style' => $Style,
        '#video_url' => $video['video_url'],
        '#video_style' =>  $this->VideoStyle,
        '#video_data' => unserialize($video['video_data']),
        '#videohash' => _video_embed_field_store_video($video['video_url'], $this->VideoStyle )
      );
    }

    return $element;
  }


  public function getPortfolio()
  {

  $type = $this->Portfolio;
  $order = $this->Order;
  $limit = $this->Limit;
  $taxonomy = "";
  $Style = $this->ImageStyle;
  $TitleLength = $this->TitleLength;
  $BodyLength = $this->BodyLength;

  $query = db_select('node', 'n')
    ->condition('n.type', $type, '=')
    ->condition('n.status',1,'=')
    ->fields('n', array('nid', 'title', 'status', 'created','sticky'))
    ->orderBy('n.sticky', 'DESC')
    ->orderBy('n.created', $order)
    ->range(0, $limit);

    $result = $query->execute();

    if (!$result->rowCount()) {
      return t("Could not find any Portfolio item!");
    }

  // Result is returned as a iterable object that returns a stdClass object on each iteration
  foreach ($result as $record) {
    // Perform operations on $record->title, etc. here.
    // in this example the available data would be mapped to object properties:
    $node = node_load($record->nid);
    // $image = $node->field_portfolio_images['und'][0]['uri'];
    $image = field_get_items('node', $node, 'field_portfolio_images');
    $video = field_get_items('node', $node, 'field_portfolio_video');

    if ($image) {
      $isVideo = FALSE;
      $image_title = $image['0']['title'];
      $image_url = image_style_url("adaptive", $image['0']['uri'] );



      $image_output = field_view_value('node', $node, 'field_portfolio_images', $image[0], array(
        'type' => 'image',
        'settings' => array(
          'image_style' => $Style,
          // 'image_link' => 'file',
        )
      ));

      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'title' => $record->title,
          'class' => "",
          'rel'   => "",
        )
      );
      $image = render($image_output);
      $icon_stack = '<span class="icon-stack"><i class="icon-circle icon-stack-base"></i><i class="icon-plus icon-light"></i></span>';
      $assets_link = l($icon_stack,$image_url, array('html' => TRUE, 'external' => TRUE, 'attributes' => array('class' => array('colorbox-load'))));

    } elseif (empty($image) && !empty($video) ) {

      $video_data = $this->videoColorbox($video[0]);
      $isVideo = TRUE;
      $video_thumb = array(
        'style_name' => $Style,
        'path' => $video[0]['thumbnail_path'],
        'width' => '',
        'height' => '',
      );

      $icon_stack = '<span class="hidden-phone icon-stack"><i class="icon-circle icon-stack-base"></i><i class="icon-play icon-light"></i></span>';
      $videolink = '?q=vef/load/' . $video_data['#videohash']. '&width=640px&height=480px';
      $image = theme('image_style',$video_thumb);
      $assets_link = l($icon_stack,$videolink, array('html' => TRUE, 'external' => TRUE, 'attributes' => array('class' => array('colorbox-load'))));
    }

    $title = $record->title;
    $title = truncate_utf8( $title, $TitleLength ,true,"...",3);

    $url = url('node/' . $record->nid, array('absolute' => TRUE) );

    /* Standart Drupal 7 */
    $body_field = field_get_items('node', $node, 'body');
    $body_value = field_view_value('node', $node, 'body', $body_field[0]);

    // Taxonomy
    $taxonomy = "";
    $tax_field = field_get_items ('node', $node, 'field_portfolio_category');
    $tax_value = field_view_value('node', $node, 'field_portfolio_category', $tax_field[0]);

    foreach ( $tax_field as $k => $v ) {
      $hasManyTaxo = ($k >= 1) ? TRUE : FALSE ;
      $vout = field_view_value('node', $node, 'field_portfolio_category', $tax_field[$k] );
      if ($hasManyTaxo) {
        $taxonomy .= " , ".render($vout);
        $tax_ico = "icon-tags";

      }else{
        $taxonomy .= render($vout);
        $tax_ico = "icon-tag";
      }
    }


    $body = render($body_value);
    $trim = strip_tags($body);

    // truncate_utf8($string, $max_length, $wordsafe = FALSE, $add_ellipsis = FALSE, $min_wordsafe_length = 1)
    $description = truncate_utf8( $trim, $BodyLength ,true,"...",3);


$item = <<< CON
<li>
  <div class="border-box custom-border">
    <div class="link-group">
    {$assets_link}

    <a href="$url">
      <span class="icon-stack">
        <i class="icon-circle icon-stack-base"></i>
        <i class="icon-link icon-light"></i>
      </span>
    </a>

    </div>
    <div class="thumbbox">$image</div>
    <div class="details">
      <h4 class="title">$title</h4>
      <p>$description</p>
      <em><i class="{$tax_ico}"></i> {$taxonomy} </em>
    </div>
  </div>
</li>
CON;
    $output[] = $item;
  }

  $items = "";
  foreach ($output as $key => $value){ $items .= $value; }

  $output = t('<ul id="BioticFolio" class="content row-fluid">!items</ul>', array('!items' => $items ) );

  return $output;

  }

/**
 * [getPortfolioPage description]
 * @param  integer $column [description]
 * @return [type]          [description]
 */
public function getPortfolioPage($column = 1)
  {

  $type = $this->Portfolio;
  $order = $this->Order;
  $limit = $this->Limit ;
  $taxonomy = "";
  $Style = $this->ImageStyle;

  $query = db_select('node', 'n')
    ->condition('n.type', $type, '=')
    ->condition('n.status',1,'=')
    ->fields('n', array('nid', 'title', 'status', 'created','sticky'))
    ->orderBy('n.sticky', 'DESC')
    ->orderBy('n.created', $order)
    ->range(0, $limit);

    $result = $query->execute();

    if (!$result->rowCount()) {
      return t("Could not find any Portfolio item!");
    }

  // Result is returned as a iterable object that returns a stdClass object on each iteration
  foreach ($result as $record) {
    // Perform operations on $record->title, etc. here.
    // in this example the available data would be mapped to object properties:
    $node = node_load($record->nid);
    // $image = $node->field_portfolio_images['und'][0]['uri'];
    $image = field_get_items('node', $node, 'field_portfolio_images');
    $video = field_get_items('node', $node, 'field_portfolio_video');

    if ($image) {
      $isVideo = FALSE;
      $image_title = $image['0']['title'];
      $image_url = image_style_url("adaptive", $image['0']['uri'] );



      $image_output = field_view_value('node', $node, 'field_portfolio_images', $image[0], array(
        'type' => 'image',
        'settings' => array(
          'image_style' => $Style,
          // 'image_link' => 'file',
        )
      ));

      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'title' => $record->title,
          'class' => "",
          'rel'   => "",
        )
      );
      $image = render($image_output);
      $icon_stack = '<span class="icon-stack"><i class="icon-circle icon-stack-base"></i><i class="icon-plus icon-light"></i></span>';
      $assets_link = l($icon_stack,$image_url, array('html' => TRUE, 'external' => TRUE, 'attributes' => array('class' => array('colorbox-load'))));

    } elseif (empty($image) && !empty($video) ) {

      $video_data = $this->videoColorbox($video[0]);
      $isVideo = TRUE;
      $video_thumb = array(
        'style_name' => $Style,
        'path' => $video[0]['thumbnail_path'],
        'width' => '',
        'height' => '',
      );

      $icon_stack = '<span class="hidden-phone icon-stack"><i class="icon-circle icon-stack-base"></i><i class="icon-play icon-light"></i></span>';
      $videolink = '?q=vef/load/' . $video_data['#videohash']. '&width=640px&height=480px';
      $image = theme('image_style',$video_thumb);
      $assets_link = l($icon_stack,$videolink, array('html' => TRUE, 'external' => TRUE, 'attributes' => array('class' => array('colorbox-load'))));
    }

    $title = $record->title;

    $url = url('node/' . $record->nid, array('absolute' => TRUE) );

    /* Standart Drupal 7 */
    $body_field = field_get_items('node', $node, 'body');
    $body_value = field_view_value('node', $node, 'body', $body_field[0]);

    // Taxonomy
    $taxonomy = "";
    $tax_field = field_get_items ('node', $node, 'field_portfolio_category');
    $tax_value = field_view_value('node', $node, 'field_portfolio_category', $tax_field[0]);

    foreach ( $tax_field as $k => $v ) {
      $hasManyTaxo = ($k >= 1) ? TRUE : FALSE ;
      $vout = field_view_value('node', $node, 'field_portfolio_category', $tax_field[$k] );
      if ($hasManyTaxo) {
        $taxonomy .= " , ".render($vout);
        $tax_ico = "icon-tags";

      }else{
        $taxonomy .= render($vout);
        $tax_ico = "icon-tag";
      }
    }


    $body = render($body_value);
    $trim = strip_tags($body);

    // truncate_utf8($string, $max_length, $wordsafe = FALSE, $add_ellipsis = FALSE, $min_wordsafe_length = 1)
    $description = truncate_utf8( $trim, 350 ,true,"...",3);


$item = <<< CON
<li>

  <div class="row-fluid">
    <div class="span6">

    <div class="thumbbox">$image</div>

    </div>
    <div class="span6">

      <h2 class="node-title">$title</h2>
      <p>$description</p>
      <em><i class="{$tax_ico}"></i> {$taxonomy} </em>

      <div>
        <a href="{$url}" class="btn" title="Read more">Read more</a>
      </div>

    </div>
  </div>

  <hr/>

</li>
CON;
    $output[] = $item;
  }

  $items = "";
  foreach ($output as $key => $value){ $items .= $value; }

  $output = t('<ul id="PortfolioPage" class="unstyled">!items</ul>', array('!items' => $items ) );

  return $output;

  }

  /**
   * [getBlogset description]
   * @param  string $value [description]
   * @return [type]        [description]
   */
  public function getBlogset($value='')
  {

  $type = "blog";
  $order = $this->Order;
  $limit = $this->Limit;
  $taxonomy = "";
  $Style = $this->ImageStyle;
  $TitleLength = $this->TitleLength;
  $BodyLength = $this->BodyLength;

  $query = db_select('node', 'n')
    ->condition('n.type', $type, '=')
    ->condition('n.status',1,'=')
    ->fields('n', array('nid', 'title', 'status', 'created','sticky'))
    ->orderBy('n.sticky', 'DESC')
    ->orderBy('n.created', $order)
    ->range(0, $limit);

    $result = $query->execute();


    if (!$result->rowCount()) {
      return t("Could not find any Blog item!");
    }

  // Result is returned as a iterable object that returns a stdClass object on each iteration
  foreach ($result as $record) {
    // Perform operations on $record->title, etc. here.
    // in this example the available data would be mapped to object properties:
    $node = node_load($record->nid);

    // Fields
    $image = field_get_items('node', $node, 'field_blog_images');
    $video = field_get_items('node', $node, 'field_blog_video');
    $media = field_get_items('node', $node, 'field_blog_multimedia');

    // field_tags (Array, 0 elements)
    // field_blog_images (Array, 0 elements)
    // field_blog_video (Array, 0 elements)
    // field_blog_multimedia (Array, 0 elements)
    if ($image) {
      $isVideo = FALSE;
      $image_title = $image['0']['title'];
      $image_url = image_style_url("adaptive", $image['0']['uri'] );



      $image_output = field_view_value('node', $node, 'field_blog_images', $image[0], array(
        'type' => 'image',
        'settings' => array(
          'image_style' => $Style,
          // 'image_link' => 'file',
        )
      ));

      $options = array(
        'html' => TRUE,
        'attributes' => array(
          'title' => $record->title,
          'class' => "",
          'rel'   => "",
        )
      );
      $image = render($image_output);
      $icon_stack = '<span class="icon-stack"><i class="icon-circle icon-stack-base"></i><i class="icon-plus icon-light"></i></span>';
      $assets_link = l($icon_stack,$image_url, array('html' => TRUE, 'external' => TRUE, 'attributes' => array('class' => array('colorbox-load'))));
    } elseif (empty($image) && !empty($video) ) {

      $video_data = $this->videoColorbox($video[0]);
      $isVideo = TRUE;
      $video_thumb = array(
        'style_name' => $Style,
        'path' => $video[0]['thumbnail_path'],
        'width' => '',
        'height' => '',
      );

      $icon_stack = '<span class="hidden-phone icon-stack"><i class="icon-circle icon-stack-base"></i><i class="icon-play icon-light"></i></span>';
      $videolink = '?q=vef/load/' . $video_data['#videohash']. '&width=640px&height=480px';
      $image = theme('image_style',$video_thumb);
      $assets_link = l($icon_stack,$videolink, array('html' => TRUE, 'external' => TRUE, 'attributes' => array('class' => array('colorbox-load'))));
    }elseif (empty($image) && empty($video) && !empty($media)) {

      $fid = $media[0]['fid'];
      $file = file_load($fid);

      if ($file->type == "audio") {
        $settings = array(
          'settings' => array(
            'width' => NULL,
            'autoplay' => NULL,
            'extra_params' => NULL
          )
        );
        module_load_include( 'inc', 'media_soundcloud', '/includes/media_soundcloud.formatters' );
        $content = media_soundcloud_file_formatter_audio_view($file, $settings, LANGUAGE_NONE);
        $image = render($content);
      }
      elseif ($file->type == "image")
      {
        $display['settings']['image_style'] = $Style;
        $display['settings']['link_to_flickr'] = FALSE;
        module_load_include( 'inc', 'media_flickr', '/includes/media_flickr.formatters' );
        $content = media_flickr_file_formatter_image_view($file, $display, LANGUAGE_NONE);
        $image = render($content);
      }

    }


    $title = $record->title;
    $title = truncate_utf8( $title, $TitleLength ,true,"...",3);

    $created = format_date($node->created,"custom","l, F d");

    $url = url('node/' . $record->nid, array('absolute' => TRUE) );

    $title = l($title, $url);

    /* Standart Drupal 7 */
    $body_field = field_get_items('node', $node, 'body');
    $body_value = field_view_value('node', $node, 'body', $body_field[0]);

    $body = render($body_value);
    $trim = strip_tags($body);

    // truncate_utf8($string, $max_length, $wordsafe = FALSE, $add_ellipsis = FALSE, $min_wordsafe_length = 1)
    $description = truncate_utf8( $trim, $BodyLength ,true,"...",3);

$item = <<< BLG
<li>
 <div class="blogset">
    <div class="box">
      {$image}
      <div class="title">{$title}</div>
      <p class="post-date"><span class="xbadge"><i class='icon-calendar'></i> {$created}</span></p>
      <p>{$description}</p>
    </div>
  </div>
</li>
BLG;
    $output[] = $item;
  }


    $items = "";
    foreach ($output as $key => $value){ $items .= $value; }

    $output = t('<ul id="BioticBlog" class="unstyled content row-fluid">!items</ul>', array('!items' => $items ) );

    return $output;

    # code...
    return "Hello World! style =" . $Style;
  }

  /**
   * [getSlideshow description]
   * @param  [type] $node [description]
   * @return [type]       [description]
   */
  public function getSlideshow($node)
  {
    $Style = $this->ImageStyle;
    $assets = array();
    $image = field_get_items('node', $node, 'field_portfolio_images');

    if ($image) {
      foreach ($image as $key => $value) {
        $hero_image = array(
          'style_name' => $Style,
          'path' => $value['uri'],
          'width' => '',
          'height' => '',
          'alt' => $value['alt'],
          'title' => $value['title'],
          );
        $assets[] = theme('image_style',$hero_image);
      }
    }

    if (count($image)>1) {
      $slide = "PortfolioSlideshow";
    } else {
      $slide = "";
    }

    $output = theme('item_list', array(
      'type' => "ul",
      'items' => $assets,
      'attributes' => array('id' => "node-".$node->nid."-images", 'class' => array("unstyled", $slide ) )
      ));

    return $output;


  } // end getSlideshow



}
