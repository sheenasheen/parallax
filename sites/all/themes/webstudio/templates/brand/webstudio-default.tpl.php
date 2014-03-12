<?php

  $fixed = theme_get_setting("header_fixed");
  $css = ($fixed) ? "sticky" : null;

  $brand = $page['brand'];

?>

<?php if($brand || $logo || $site_name || $site_slogan || $MobileMenu || $primary_nav) : ?>

<!-- Global Brand
================================================== -->
<div id="GlobalBrand" class="wrapper <?php print $css ?>">
  <div id="BrandContainer" class="<?php print ($BrandRaw) ? "container-fluid" : $container; ?>">
    <div class="relative <?php print ($BrandRaw) ? "row-fluid" : $row; ?>">

    <?php print render($brand); ?>

      <?php if ($logo || $site_name || $site_slogan || $MobileMenu ) : ?>
      <div id="BrandBox" class="span3 <?php print $brandclasses; ?>">
      <?php if (!empty($logo)): ?>
          <a class="logo pull-left" href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>">
            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
          </a>
      <?php endif; ?>

      <?php if (!empty($site_name)): ?>
        <h1 id="site-name" class="site-name">
          <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" class="brand"><?php print $site_name; ?></a>
          <?php if (!empty($site_slogan)): ?>
            <small class="site-slogan"><?php print $site_slogan; ?></small>
          <?php endif; ?>
        </h1>
      <?php endif; ?>

      <?php if ($MobileMenu): ?>
        <nav id="MobileMenuLink" class="span9 text-right pull-right visible-phone" role="navigation">
            <a href="#MobileMenu">
            <i class="icon-reorder icon-2x"></i>
            </a>
        </nav>
      <?php endif; ?>


      </div>
    <?php endif; ?>

      <?php if ($primary_nav): ?>
      <nav  id="MainMenu" class="span9 hidden-phone" role="navigation" >
        <div class="vercenter">
        <?php if (!empty($primary_nav)): ?>
          <?php print render($primary_nav); ?>
        <?php endif; ?>
        </div>
      </nav>
    <?php endif; ?>

    </div>
  </div>
</div> <!-- /#Globalbrand -->

<?php endif; ?>
