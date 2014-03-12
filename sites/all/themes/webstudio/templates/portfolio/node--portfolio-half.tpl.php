<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>

  <?php
    // Hide comments, tags, and links now so that we can render them later.
    hide($content['comments']);
    hide($content['links']);
    hide($content['field_tags']);

    hide($content['field_portfolio_template']);
    hide($content['field_portfolio_category']);
    hide($content['field_portfolio_images']);
    hide($content['field_portfolio_video']);
  ?>


<div class="row-fluid">

  <div class="span6">
    <?php print render($content['field_portfolio_video']); ?>
    <?php print render( $content['field_portfolio_images'] ); ?>
  </div>

  <div class="span6">
    <?php  print render($content); ?>

  <?php if (!empty($content['field_tags']) || !empty($content['links'])): ?>
    <footer>
      <?php print render($content['field_portfolio_category']); ?>
      <?php print render($content['links']); ?>
    </footer>
  <?php endif; ?>
  </div>

</div>

<?php print render($content['comments']); ?>

</article> <!-- /.node -->
