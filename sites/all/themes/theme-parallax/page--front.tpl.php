<div id="page">
    <div id="wrapper">
        <div id="header" class="clearfix container_12">
        <div class="cbp-af-header">
    	<div class="cbp-af-inner">
            <div class="grid_5">
                <!--logo-floater-->
                <div id="logo-floater"> 
                    <?php if ($logo): ?>
                    <a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>">
                    <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                    </a>
                    <?php endif; ?>
                    
                    <?php if ($site_name || $site_slogan): ?>
                    <div class="clearfix">
                        <?php if ($site_name): ?>
                        <span id="site-name"><a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>"><?php print $site_name; ?></a></span>
                        <?php endif; ?>
                        
                        <?php if ($site_slogan): ?>
                        <span id="slogan"><?php print $site_slogan; ?></span>
                        <?php endif; ?>
                    </div>
                    <?php endif; ?>
                </div> 
                <!--EOF:logo-floater-->
            </div>
    
            <div class="grid_7">
                <!--navigation-->
                <div id="navigation">
                    <?php if ($page['navigation']) :?>
                    <?php print drupal_render($page['navigation']); ?>
                    <?php else :
                    if (module_exists('i18n_menu')) {
                    $main_menu_tree = i18n_menu_translated_tree(variable_get('menu_main_links_source', 'main-menu'));
                    } else { $main_menu_tree = menu_tree(variable_get('menu_main_links_source', 'main-menu')); }
                    print drupal_render($main_menu_tree);
                    endif; ?>
                </div>
                <!--EOF:navigation-->
            </div>
        </div>
    </div>
</div>
</div>
</div>



    <?php 
		//var_dump($page['content']['system_main']['nodes']);
		//die();
		/*foreach($page['content']['system_main']['nodes'] as $node) {
			if (is_object($node['#node'])) {
				if ($node['#node']->type === 'page') {
					//var_dump($node['#node']);
					if(property_exists($node['#node']->body['und'][0], 'value')) echo "<div id='front-page-" . $node['#node']->title . "'>" . $node['#node']->body['und'][0]['value'] . "</div>";
				}
			}
		} 
		die(); */
	?>
    


<!--
<div id="page">


    <!--header-top-->
    <div id="header-top">
        <div id="header-top-inside" class="clearfix container_12">
        	
            <div class="grid_7">
                <!--header-top-inside-left-->
                <div id="header-top-inside-left"><?php print render($page['header']); ?></div>
                <!--EOF:header-top-inside-left-->
            </div>

            <div class="grid_2">
                <!--header-top-inside-left-feed-->
                <div id="header-top-inside-left-feed">
                    
                    </div>
                </div>
                <!--EOF:header-top-inside-left-feed-->
            </div>
            
            <div class="grid_3">
                <!--header-top-inside-left-right-->
                <div id="header-top-inside-right"><?php print render($page['search_area']);?></div> 
                <!--EOF:header-top-inside-left-right-->
            </div>
             
        </div>
    </div>
    <!--EOF:header-top-->
    
    <div id="wrapper">
    	
        <!--header-->
        
        <!--EOF:header-->

        <div class="container_12-slider">
          
            <div class="grid_12">
            <div id="slider">
            <?php print render($page['slider']); ?>
            
           
            <div class="gallery autoplay items-3">
  <div id="item-1" class="control-operator"></div>
  <div id="item-2" class="control-operator"></div>
  <div id="item-3" class="control-operator"></div>

  <figure class="item">
  <br/><br />
    <h1>1</h1>
  </figure>

  <figure class="item">
   <br/><br />
    <h1>2</h1>
  </figure>

  <figure class="item">
   <br/><br />
    <h1>3</h1>
  </figure>

  <div class="controls">
    <a href="#item-1" class="control-button">•</a>
    <a href="#item-2" class="control-button">•</a>
    <a href="#item-3" class="control-button">•</a>
    
  </div>
</div>
</div>
            
            </div>
            </div>
            </div>
            
                <!--banner
                
<?php /*?>                <?php print render($page['banner']); ?>
                
                <?php if (theme_get_setting('slideshow_display','bluemasters')): ?> -->
<?php */?>
                <!--#slideshow
                <div id="slideshow">
                
                <div class="flexslider">
                <ul class="slides">
                
                
                <li class="slider-item">
                <div class="slider-item-image">
                <a href="<?php print url('node/3'); ?>"><img src="<?php print base_path() . drupal_get_path('theme', 'bluemasters') . '/images/slide-image-3.jpg'; ?>"></a>
                </div>
                <div class="slider-item-caption">About Bluemasters</div>
                </li>
                
                
               
                <li class="slider-item">
                <div class="slider-item-image">
                <a href="<?php print url('node/2'); ?>"><img src="<?php print base_path() . drupal_get_path('theme', 'bluemasters') . '/images/slide-image-2.jpg'; ?>"></a>
                </div>
                <div class="slider-item-caption">Our Portfolio</div>
                </li>
             
                
               
                <li class="slider-item">
                <div class="slider-item-image">
                <a href="<?php print url('node/1'); ?>"><img src="<?php print base_path() . drupal_get_path('theme', 'bluemasters') . '/images/slide-image-1.jpg'; ?>"></a>
                </div>
                <div class="slider-item-caption">Creation of Beaches</div>
                </li>
                
                
                </ul>
                </div>
                
                </div>
                <!--EOF:#slideshow-->

               <?php /*?> <?php endif; ?><?php */?>

                </div>
                <!--EOF:banner-->
            </div>    

        </div>
<!--div id="wrapper">
        <div class="container_12">
          
            <div class="grid_12">
             <div id="parallax-bottom">
             <?php print render($page['parallax-bottom']);?> 	        
        <div id="footer-bottom-inside" class="clearfix container_12">

            <div class="grid_12">
        	       
            </div>
            </div>

        </div> -->
                <!--home-block-area-->
               <div id="wrapper">
                <div class="container_12-home-blocks-area-bg-green">
                <div id="home-blocks-area2" class="clearfix">
               
                
            		<?php if ($messages): ?>
                    <div class="clearfix">
                    <?php print $messages; ?>
                    </div>
                    <?php endif; ?>

                    <div class="grid_3 alpha">
                        <div class="column-fix">
                            <div class="home-block-area first">
                                <?php print render($page['home_area_1']);?> 		
                            </div>
                        </div>
                    </div>

                    <div class="grid_3 alpha omega">
                        <div class="column-fix">
                            <div class="home-block-area">
                                <?php print render($page['home_area_2']);?> 
                            </div>
                        </div>
                    </div>
                    
                    <div class="grid_3 alpha omega">
                        <div class="column-fix">
                            <div class="home-block-area last">
                                <?php print render($page['home_area_3']);?> 
                               
                            </div>
                        </div>
                    </div>

                    <div class="grid_3 omega">
                        <div class="column-fix">
                            <div class="home-block-area last">
                                <?php print render($page['home_area_4']);?> 
                                
                            </div>
                        </div>
                    </div>
</div>
                </div>
                </div>
                 
                
                        
        <div id="wrapper">
        <div class="container_12-thumb">
       <div id="Thumbnails-area" class="clearfix">
             <div class="grid_12">
             <div id="thumbnails-1">
             <?php print render($page['thumbnails-1']);?> 
             		
             
             <div class="container_12">
          	<div class="grid_12">
             <div id="parallax-section">
             <?php print render($page['parallax-section']);?> 		
        
        <div id="footer-bottom-inside" class="clearfix container_12">

            <div class="grid_12">
        	       
            </div>

        </div>
                <!--EOF:home-block-area-->
            </div>    

        </div>

    </div>
    </div>
     <div class="container_12">
            <div class="grid_12">
                <div id="blue-area" class="clearfix">
                
                    <div id="blue-area-inside" class="clearfix">
                    
        
                        
                        <div class="grid_12 alpha omega">    
                       

                            <div id="main"  class="inside clearfix">
                                
                                
                            </div>
                            
                        </div>
    <!--EOF:wrapper-->

    <!--footer-->
    <div id="footer">
    
        <div id="footer-inside" class="clearfix container_12">
            
            <div class="grid_4">
            	<div id="footer-left">
                    <div class="grid_2 alpha">
                		<div id="footer-left-1">
                			<?php print render($page['footer_left_1']);?>
                		</div>
                    </div>
                    <div class="grid_2 omega">
                		<div id="footer-left-2">
                			<?php print render($page['footer_left_2']);?>
                		</div>
                    </div>
                </div>
            </div>
            
            <div class="grid_4">
                <div id="footer-center">
                	<?php print render($page['footer_center']);?>
                </div>
            </div>

            <div class="grid_4">
                <div id="footer-right">
                	<?php print render($page['footer_right']);?>
                </div>
            </div>            
            
        </div>
    </div>
    <!--EOF:footer-->

    <!--footer-bottom-->
    <div id="footer-bottom"> <script>
	var controller;
	$(document).ready(function($) {
		// init controller
		controller = new ScrollMagic({vertical: true});
	});
</script>
 
<div id="parallaxText">
	<h1 class="layer1">PARALLAX</h1>
	<h1 class="layer2">PARALLAX</h1>
	<h1 class="layer3">
		PARALLAX
		
	</h1>
	
</div>
<script>
	$(document).ready(function($) {
		// build tween
		var tween = new TimelineMax ()
			.add([
				TweenMax.fromTo("#parallaxText .layer1", 1, {scale: 3, autoAlpha: 0.05, left: 300}, {left: -350, ease: Linear.easeNone}),
				TweenMax.fromTo("#parallaxText .layer2", 1, {scale: 2, autoAlpha: 0.3, left: 150}, {left: -175, ease: Linear.easeNone})
			]);

		// build scene
		var scene = new ScrollScene({triggerElement: "#trigger2", duration: $(window).width()})
						.setTween(tween)
						.addTo(controller);

		// show indicators (requires debug extension)
		scene.addIndicators();
	});
</script>
        
        <div id="footer-bottom-inside" class="clearfix container_12">

            <div class="grid_5">
            	<div id="footer-bottom-inside-left">
            		<?php print render($page['footer']);?>
            	</div>
            </div>

            <div class="grid_7">
            	<div id="footer-bottom-inside-right">
        		<?php print theme('links__system_secondary_menu', array('links' => $secondary_menu, 'attributes' => array('id' => 'secondary-menu', 'class' => array('links', 'inline', 'clearfix')))); ?>
            	<?php if ($page['footer_bottom']) :?>
                <?php print render($page['footer_bottom']); ?>
                <?php endif; ?>
                </div>
            </div>

            <div class="grid_12">
        	   <div class="credits-container" style="clear:both; padding-top:12px;"></div>     
            </div>

        </div>
        <div id="wrapper">
        <div class="container_12-parallax">
       
          
            <div class="grid_12">
             <div id="parallax-bottom">
             <?php print render($page['parallax-bottom']);?> 	
           
        <div class="container_12">
        

            <div class="grid_12">
                <div class="credits-container clearfix">
                    
                </div>
            </div>

        </div>  

    </div>
    <!--EOF:footer-bottom-->

</div>
<!--EOF:page-->