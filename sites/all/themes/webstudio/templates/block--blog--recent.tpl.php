<section id="<?php print $block_html_id; ?>" class="<?php print $classes; ?>"<?php print $attributes; ?>>
  <?php print render($title_prefix); ?>
  <?php if ($title): ?>
    <h3<?php print $title_attributes; ?>><?php print $title; ?></h3>
  <?php endif;?>
  <?php print render($title_suffix); ?>
  <ul class="nav nav-tabs nav-stacked" >
	<?php foreach ($variables['elements']['blog_list']['#items'] as $item) {
		print "<li>".$item."</li>";	
	} ?>
  </ul>
  <?php // print $content ?>
  <?php // print render($variables['elements']['blog_more']) ?>
</section> <!-- /.block -->
