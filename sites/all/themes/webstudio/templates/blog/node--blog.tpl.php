<?php // dpm($node); ?>

<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>


  <header class="blog-title text-center">
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
  </header>


  <?php print render($content['field_tags']); ?>

  <?php if ($display_submitted): ?>
    <span class="submitted">
      <?php print $user_picture; ?>
      <?php print $submitted; ?>

    </span>
  <?php endif; ?>

  <?php print render($content['submitted_by']); ?>

  <hr/>

  <?php if ( render($content['field_blog_images']) || render($content['field_blog_video']) || render($content['field_blog_multimedia'])  ): ?>
  <div class="text-center">
    <?php   print render($content['field_blog_images']);  ?>
    <?php   print render($content['field_blog_video']);  ?>
    <?php   print render($content['field_blog_multimedia']);  ?>
  </div>
<?php endif; ?>


  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);
    hide($content['field_blog_images']);
    hide($content['field_blog_video']);
    hide($content['field_blog_multimedia']);

    if ( module_exists("submitted_by") ) {
      # code...
      hide($content['submitted_by']);
    }

    print render($content);
  ?>

  <?php if ( render($content['links']) ): ?>
    <footer>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>

  <?php print render($content['comments']); ?>

</article> <!-- /.node -->


