<?php if ($MobileMenu): ?>
<nav id="MobileMenu" class="element-invisible">
  <?php if (!empty($primary_mobile)): ?>
  <?php  print render($primary_mobile);  ?>
<?php endif; ?>
</nav>
<?php endif; ?>

<?php if (!empty($page['topbar'])): ?>
<!-- Top bar
================================================== -->
<div id="TopBarWrapper" class="wrapper">
  <header id="TopBarContainer" class="<?php print ($TopBarRaw) ? "raw-container" : $container; ?>">
    <nav id="TopBar" class="<?php print ($TopBarRaw) ? "raw" : $row; ?>" role="navigation">
      <?php print render($page['topbar']); ?>
    </nav><!-- /TopBar -->
  </header>
</div>
<?php endif; ?>

<?php

  /*
  <!-- Brand
  ================================================== --> */
  require_once 'brand/'.$brand_layout.'.tpl.php';
?>

<?php if (!empty($page['header'])): ?>
<!-- Header
================================================== -->
<div id="HeaderWrapper" class="wrapper">
  <div id="HeaderContainer" class="<?php print ($HeaderRaw) ? "raw-container" : $container; ?>">
    <div id="Header" class="<?php print ($HeaderRaw) ? "raw" : $row; ?>">
      <?php print render($page['header']); ?>
    </div>
  </div>
</div>
<?php endif; ?>


<?php if (!empty($page['header_bottom'])): ?>
  <!-- HeaderBottom
  ================================================== -->
<div id="HeaderBottomWrapper" class="wrapper" role="region">
  <div id="HeaderBottomContainer" class="<?php print ($HeaderBottomRaw) ? "raw-container" : $container; ?>">
    <div class="<?php print ($HeaderBottomRaw) ? "raw" : $row; ?>">
      <section id="HeaderBottom" class="span12" >
        <?php print render($page['header_bottom']); ?>
      </section>  <!-- /#header_bottom -->
    </div>
  </div>
</div>
<?php endif; ?>


<?php if(!empty($page['top_raw'])): ?>
<!-- Top Raw Regions
================================================== -->
<div id="TopRawWrapper" class="wrapper">
  <div id="TopRawContainer" class="raw">
    <?php print render($page['top_raw']); ?>
  </div>
</div>
<?php endif; ?>


<?php if(!empty($page['intro'])): ?>
<!-- Intro Regions
================================================== -->
<div id="IntroWrapper" class="wrapper">
  <div id="IntroContainer" class="<?php print ($IntroRaw) ? "raw-container" : $container; ?>" >
    <section id="Intro" class="<?php print ($IntroRaw) ? "raw" : $row; ?>" >
      <?php print render($page['intro']); ?>
    </section>
  </div>
</div>
<?php endif; ?>




<?php if ($PageTitle && !empty($title) ) : ?>
<!-- Page Title
================================================== -->
<div id="PageTitleWrapper" class="wrapper">
  <div id="PageTitleContainer" class="<?php print $container; ?>">
    <header id="PageTitle" class="<?php print $row; ?>">
      <?php print render($title_prefix); ?>
        <?php if (!empty($title)): ?>
          <h1 class="page-title span"><span><?php print $title; ?></span></h1>
        <?php endif; ?>
      <?php print render($title_suffix); ?>
      <?php if (theme_get_setting('pagetitle_breadcrumb')) { print $breadcrumb; } ?>
    </header>
  </div>
</div>
<?php endif; ?>


<!-- Main
================================================== -->
<div id="MainWrapper" class="wrapper <?php print ( theme_get_setting('debug') ) ? "regions-debug-info" : "";  ?>">

<?php

if ( theme_get_setting('debug') ) {
  $name = strtoupper('main');
  // print '<div class="regions-debug-info">';
  print t('<div class="region-name-debug bare" data-outline="wrapper" data-target="MainWrapper" ><i class="icon-code"></i> !name </div>', array('!name'=> $name) );
}

?>


<div id="MainContainer" class="<?php print ($MainRaw) ? "container-fluid" : $container; ?>">

  <?php if ($messages): ?>
  <!-- Messages
  ================================================== -->
    <?php print $messages; ?>
  <?php endif; ?>

  <div class="<?php print ($MainRaw) ? "row-fluid" : $row; ?>">

    <?php if (!empty($page['sidebar_first'])): ?>
      <!-- Sidebar first
      ================================================== -->
      <aside id="SidebarFirst" class="span3 wrapper-debug" role="complementary">
        <?php print ($SidebarFirstRaw) ? "<div id='SidebarFirstRaw'>" : ""; ?>
        <?php print render($page['sidebar_first']); ?>
        <?php print ($SidebarSecondRaw) ? "</div><!-- /end raw -->" : ""; ?>
      </aside>  <!-- /sidebar-first -->
    <?php endif; ?>

    <section id="MainContentWrapper" class="<?php print _bootstrap_content_span($columns); ?>">

    <?php if (!empty($page['highlighted'])): ?>

        <div id="Highlighted" class="highlighted wrapper-debug">
        <?php print ($HighlightedRaw) ? "<div id='HighlightedRaw'>" : ""; ?>
          <?php print render($page['highlighted']); ?>
        <?php print ($HighlightedRaw) ? "</div><!-- /end raw -->" : ""; ?>
        </div>

    <?php endif; ?>

      <?php if (theme_get_setting('breadcrumb') && $breadcrumb) : ?>
      <div id="Breadcrumb"><?php print $breadcrumb; ?></div>
      <?php endif; ?>

      <a id="main-content"></a>

    <?php if(!$PageTitle) : ?>
      <?php print render($title_prefix); ?>
    <?php if (!empty($title)): ?>
        <h1 class="page-title page-header"><?php print $title; ?></h1>
    <?php endif; ?>
      <?php print render($title_suffix); ?>
    <?php endif; ?>

    <?php if (!empty($tabs)): ?>
        <?php print render($tabs); ?>
    <?php endif; ?>

    <?php if (!empty($page['help'])): ?>
        <div class="well wrapper-debug"><?php print render($page['help']); ?></div>
    <?php endif; ?>

    <?php if (!empty($action_links)): ?>
        <ul class="action-links unstyled"><?php print render($action_links); ?></ul>
    <?php endif; ?>

    <?php if (!empty($page['content_top'])): ?>
      <!-- Content Top
      ================================================== -->
      <section id="ContentTop" class="wrapper-debug">
      <?php print ($ContentTopRaw) ? "<div id='ContentTopRaw'>" : ""; ?>
        <?php print render($page['content_top']); ?>
      <?php print ($ContentTopRaw) ? "</div><!-- /end raw -->" : ""; ?>
      </section><!-- /ContentTop -->
    <?php endif; ?>

      <?php if (!empty($page['content'])): ?>
        <!-- Main Content
        ================================================== -->
        <div id="MainContent" class="wrapper-debug"><?php print render($page['content']); ?></div>
      <?php endif; ?>

    <?php if (!empty($page['content_bottom'])): ?>
      <!-- Concent bottom
      ================================================== -->
      <section id="ContentBottom" class="wrapper-debug">
      <?php print ($ContentBottomRaw) ? "<div id='ContentBottomRaw'>" : ""; ?>
        <?php print render($page['content_bottom']); ?>
      <?php print ($ContentBottomRaw) ? "</div><!-- /end raw -->" : ""; ?>
      </section><!-- /ContetBottom -->
    <?php endif; ?>


    </section><!-- /MainContentWrapper -->

    <?php if (!empty($page['sidebar_second'])): ?>
      <aside id="SidebarSecond" class="span3 wrapper-debug" role="complementary">
        <?php print ($SidebarSecondRaw) ? "<div id='SidebarSecondRaw'>" : ""; ?>
        <?php print render($page['sidebar_second']); ?>
        <?php print ($SidebarSecondRaw) ? "</div><!-- /end raw -->" : ""; ?>
      </aside>  <!-- /#sidebar-second -->
    <?php endif; ?>

  </div><!-- /row -->

</div><!-- /MainContainer -->
</div><!-- /MainWrapper -->

<?php if(!empty($page['main_bottom'])): ?>
<!-- Main Bottom Regions
================================================== -->
<div id="MainBottomWrapper" class="wrapper">
  <div id="MainBottomContainer" class="<?php print ($MainBottomRaw) ? "container-fluid" : $container; ?>" >
    <section id="MainBottom" class="<?php print ($MainBottomRaw) ? "row-fluid" : $row; ?>" >
      <?php print render($page['main_bottom']); ?>
    </section>
  </div>
</div>
<?php endif; ?>

<?php if(!empty($page['postscript'])): ?>
<!-- Postscript Regions
================================================== -->
<div id="PostscriptWrapper" class="wrapper">
  <div id="PostscriptContainer" class="<?php print ($PostscriptRaw) ? "raw-container" : $container; ?>" >
    <section id="Postscript" class="<?php print ($PostscriptRaw) ? "raw" : $row; ?>" >
      <?php print render($page['postscript']); ?>
    </section>
  </div>
</div>
<?php endif; ?>


<?php if (!empty($page['bottom_raw'])): ?>
<!-- Bottom Raw Regions
================================================== -->
<div id="BottomRawWrapper" class="wrapper">
  <div id="BottomRawContainer" class="raw">
    <section id="BottomRaw">
      <?php print render($page['bottom_raw']); ?>
    </section>
  </div>
</div>
<?php endif; ?>



<?php
  if (
    !empty($page['footer_top']) ||
    !empty($page['footer']) ||
    !empty($page['footer_bottom'])
  ):
?>
<!-- Global Footer Wrapper
================================================== -->
<div id="GlobalFooterWrapper">
  <?php if (!empty($page['footer_top'])): ?>
  <!-- Footer top Region
  ================================================== -->
  <div id="FooterTopWrapper" class="wrapper">
    <div id="FooterTopContainer" class="<?php print ($FooterTopRaw) ? "container-fluid" : $container; ?>">
      <div id="FooterTop">
        <div class="<?php print ($FooterTopRaw) ? "row-fluid" : $row; ?>">
          <?php print render($page['footer_top']); ?>
        </div>
      </div>
    </div>
  </div>
  <?php endif; ?>

  <?php if (!empty($page['footer'])): ?>
  <!-- Footer region
  ================================================== -->
  <div id="FooterWrapper" class="wrapper">
    <div id="FooterConteiner" class="<?php print ($FooterRaw) ? "container-fluid" : $container; ?>">
      <footer id="Footer">
        <div class="<?php print ($FooterRaw) ? "row-fluid" : $row; ?>">
          <?php print render($page['footer']); ?>
        </div><!-- /row -->
      </footer>
    </div>
  </div>
  <?php endif; ?>


  <?php if (!empty($page['footer_bottom'])): ?>
  <!-- Footer bottom region
  ================================================== -->
  <div id="FooterBottomWrapper" class="wrapper">
    <div id="FooterBottomContainer" class="<?php print ($FooterBottomRaw) ? "container-fluid" : $container; ?>">
      <div id="FooterBottom">
        <div class="<?php print ($FooterBottomRaw) ? "row-fluid" : $row; ?>">
          <?php print render($page['footer_bottom']); ?>
        </div><!-- /row -->
      </div>
    </div>
  </div>
  <?php endif; ?>

  </div><!-- /GlobalFooterWrapper -->
<?php endif; ?>
