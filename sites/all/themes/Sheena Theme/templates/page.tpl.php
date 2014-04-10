<div id="page" class="<?php print $classes; ?>"<?php print $attributes; ?>>
<!-- ______________________ HEADER _______________________ -->

  <header id="header">
    <?php if ($logo): ?>
      <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
        <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>"/>
      </a>
    <?php endif; ?>
    <?php if ($site_name || $site_slogan): ?>
      <div id="name-and-slogan">
        <?php if ($site_name): ?>
          <?php if ($title): ?>
            <div id="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
            </div>
          <?php else: /* Use h1 when the content title is empty */ ?>
            <h1 id="site-name">
              <a href="<?php print $front_page; ?>" title="<?php print t('Home'); ?>" rel="home"><?php print $site_name; ?></a>
            </h1>
          <?php endif; ?>
        <?php endif; ?>
        <?php if ($site_slogan): ?>
          <div id="site-slogan"><?php print $site_slogan; ?></div>
        <?php endif; ?>
      </div>
    <?php endif; ?>
    <?php if ($page['header']): ?>
      <div id="header-region">
        <?php print render($page['header']); ?>
      </div>
    <?php endif; ?>
      <?php if ($main_menu || $secondary_menu || $page['navbar']): ?>
      <nav id="navigation" class="menu <?php !empty($main_menu) ? print "with-primary" : ''; !empty($secondary_menu) ? print " with-secondary" : ''; ?>">
        <?php print theme('links', array('links' => $main_menu, 'attributes' => array('id' => 'primary', 'class' => array('links', 'clearfix', 'main-menu')))); ?>
        <?php print theme('links', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary', 'class' => array('links', 'clearfix', 'sub-menu')))); ?>
        <?php if ($page['navbar']): ?>
          <div id="navbar" class="clear">
            <?php print render($page['navbar']); ?>
          </div>
        <?php endif; ?>
      </nav>
    <?php endif; ?><div class="container demo-2">
			<header class="codrops-header">
				<div class="codrops-top clearfix">
				</div>
				<h1>Item Transition Inspiration</h1>	
			</header>
			<section>
				<div id="component" class="component component-fullwidth">
					<ul class="itemwrap">
						<li class="current"><img src="/img/6.jpg" alt="img06"/></li>
						<li><img src="/img/7.jpg" alt="img07"/></li>
						<li><img src="/img/8.jpg" alt="img08"/></li>
					</ul>
					<nav>
						<a class="prev" href="#">Previous item</a>
						<a class="next" href="#">Next item</a>
					</nav>
				</div>
			</section>
  </header> <!-- /header -->
 
  <div id="main" class="clearfix" role="main">
    <div id="content">
      <div id="content-inner" class="inner column center">
        <?php if ($page['content_top']): ?>
              <div id="content_top"><?php print render($page['content_top']) ?></div>
        <?php endif; ?>
        <?php if ($breadcrumb || $title|| $messages || $tabs || $action_links): ?>
          <div id="content-header">
            <?php print $breadcrumb; ?>
            <?php if ($title): ?>
              <h1 class="title"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print $messages; ?>
            <?php print render($page['help']); ?>
            <?php if ($tabs): ?>
              <div class="tabs"><?php print render($tabs); ?></div>
            <?php endif; ?>
            <?php if ($action_links): ?>
              <ul class="action-links"><?php print render($action_links); ?></ul>
            <?php endif; ?>
            <?php if ($page['highlight']): ?>
              <div id="highlight"><?php print render($page['highlight']) ?></div>
            <?php endif; ?>
          </div> <!-- /#content-header -->
        <?php endif; ?>
        <div id="content-Sutro-area-wrapper" class="wrapper">
          <?php print render($page['content']) ?>
        </div>
          <div class="sutro-double-container sutro-double-column-content sutro-double-first-column-content clearfix">
    <div class="sutro-double-column-content-region sutro-double-column1 sutro-double-column panel-panel">
      <div class="sutro-double-column-content-region-inner sutro-double-column1-inner sutro-double-column-inner panel-panel-inner">
        <?php print $content['column1']; ?>
      </div>
    </div>
    <div class="sutro-double-column-content-region sutro-double-column2 sutro-double-column panel-panel">
      <div class="sutro-double-column-content-region-inner sutro-double-column2-inner sutro-double-column-inner panel-panel-inner">
        <?php print $content['column2']; ?>
      </div>
    </div>
  </div>

  <div class="sutro-double-container sutro-double-middle clearfix panel-panel">
    <div class="sutro-double-container-inner sutro-double-middle-inner panel-panel-inner">
      <?php print $content['middle']; ?>
    </div>
  </div>

  <div class="sutro-double-container sutro-double-column-content sutro-double-second-column-content clearfix">
    <div class="sutro-double-column-content-region sutro-double-column1 sutro-double-column panel-panel">
      <div class="sutro-double-column-content-region-inner sutro-double-column1-inner sutro-double-column-inner panel-panel-inner">
        <?php print $content['secondcolumn1']; ?>
      </div>
    </div>
    <div class="sutro-double-column-content-region sutro-double-column2 sutro-double-column panel-panel">
      <div class="sutro-double-column-content-region-inner sutro-double-column2-inner sutro-double-column-inner panel-panel-inner">
        <?php print $content['secondcolumn2']; ?>
      </div>
    </div>
  </div>
 </div>
        <?php print $feed_icons; ?>
        <?php if ($page['content_bottom']): ?>
              <div id="content_bottom"><?php print render($page['content_bottom']) ?></div>
        <?php endif; ?>
      </div>
    </div> 
    
	<?php if(!empty($page['main_bottom'])): ?>

<div id="MainBottomWrapper" class="wrapper">
  <div id="MainBottomContainer" class="<?php print ($MainBottomRaw) ? "container-fluid" : $container; ?>" >
    <section id="MainBottom" class="<?php print ($MainBottomRaw) ? "row-fluid" : $row; ?>" >
      <?php print render($page['main_bottom']); ?>
    </section>
  </div>
</div>
<?php endif; ?>
    <!-- /content-inner /content -->
    <?php if ($page['sidebar_first']): ?>
      <aside id="sidebar-first" class="column sidebar first">
        <div id="sidebar-first-inner" class="inner">
          <?php print render($page['sidebar_first']); ?>
        </div>
      </aside>
    <?php endif; ?> <!-- /sidebar-first -->
    <?php if ($page['sidebar_second']): ?>
      <aside id="sidebar-second" class="column sidebar second">
        <div id="sidebar-second-inner" class="inner">
          <?php print render($page['sidebar_second']); ?>
        </div>
      </aside>
    <?php endif; ?> <!-- /sidebar-second -->
  <!-- ______________________ FOOTER _______________________ -->
    <?php if ($page['footer']): ?>
      <footer id="footer">
        <?php print render($page['footer']); ?>
      </footer> <!-- /footer -->
    <?php endif; ?>
  </div> <!-- /main -->
</div> <!-- /page -->
