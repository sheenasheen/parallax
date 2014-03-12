<article id="node-<?php print $node->nid; ?>" class="row-fluid <?php print $classes; ?> clearfix"<?php print $attributes; ?>>

<?php
  // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);

    hide($content['field_portfolio_template']);
   // hide($content['field_portfolio_category']);
    hide($content['field_portfolio_images']);
    hide($content['field_portfolio_video']);
?>

  <div class="span6">
    <?php print render( $content['field_portfolio_images'] ); ?>
    <?php print render( $content['field_portfolio_video'] ); ?>
  </div>

  <div class="span6">
    <header>
    <?php print render($title_prefix); ?>
    <?php if (!$page && $title): ?>
      <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
    <?php endif; ?>
    <?php print render($title_suffix); ?>
    </header>

    <?php // print render($content['field_portfolio_category']); ?>
    <?php print render($content);  ?>

  </div>

  <footer class="clearBoth">
    <?php print render($content['links']); ?>
  </footer>

</article> <!-- /.node -->
