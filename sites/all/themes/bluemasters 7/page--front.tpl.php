<div id="page">
 <!--header-top-->
    <div id="header-top">
    
            <div class="grid_7">
                <!--header-top-inside-left-->
                <div id="header-top-inside-left"><?php print render($page['header']); ?></div>
                <!--EOF:header-top-inside-left-->
            </div>

            <div class="grid_2">
                <!--header-top-inside-left-feed-->
             
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

       
       
            <div class="grid_12">
   <!--header-->
<div id="header" class="clearfix container_12">  
<div id="wrapper-nav">  
<div id="container_12 NavBG">
<div class="grid_12">
                <!--logo-floater-->
                
                   
                <!--navigation-->
                   <?php print drupal_render($page['navigation']); ?>
                    <div class="cbp-af-header">
							<?php if ($logo): ?>
                            <a href="<?php print check_url($front_page); ?>" title="<?php print t('Home'); ?>" id="logo-floater">
                            <img src="<?php print $logo; ?>" alt="<?php print t('Home'); ?>" />
                            </a> 
                            <?php endif; ?>
                            <nav>
                                <a href="#Services">Services</a>
                                <a href="#Portfolio">Portfolio</a>
                                <a href="#Extra">Extra</a>
                                <a href="#Social">Social</a>
                                <a href="#About">About</a>
                                <a href="#Extra2">Extra2</a>
                                <a href="#Contact">Contact</a>
                            </nav>
                            <div id="block-superfish-1" class="block block-superfish">


<div class="content">
<select id="superfish-1-select"><select id="superfish-1-select"><option>Main menu</option><select id="superfish-1-select"><option>Main menu</option><option value="#Services">Services</option><option value="#Portfolio">Portfolio</option><option value="#Extra">Extra</option><option value="#Social">Social</option><option value="#About">About</option><option value="#Extra2">Extra 2</option><option value="#Contact">Contact</option></select><ul id="superfish-1" class="menu sf-menu sf-main-menu sf-horizontal sf-style-none sf-total-items-5 sf-parent-items-1 sf-single-items-4 superfish-processed sf-js-enabled" style="display: none;"><li id="menu-221-1" class="active-trail first odd sf-item-1 sf-depth-1 sf-no-children"><a href="/bluemasters/site/" class="sf-depth-1 active">Home</a></li><li id="menu-355-1" class="middle even sf-item-2 sf-depth-1 sf-total-children-3 sf-parent-children-1 sf-single-children-2 menuparent"><a href="/bluemasters/site/node/3" title="" class="sf-depth-1 menuparent">About</a><ul class="sf-hidden" style="float: none; width: 12em;"><li id="menu-378-1" class="first odd sf-item-1 sf-depth-2 sf-no-children" style="white-space: normal; float: left; width: 100%;"><a href="/bluemasters/site/NODE/1" title="" class="sf-depth-2" style="float: none; width: auto;">Semper sed</a></li><li id="menu-353-1" class="middle even sf-item-2 sf-depth-2 sf-total-children-2 sf-parent-children-0 sf-single-children-2 menuparent" style="white-space: normal; float: left; width: 100%;"><a href="/bluemasters/site/node/2" title="" class="sf-depth-2 menuparent" style="float: none; width: auto;">Vivamus</a><ul class="sf-hidden" style="left: 12em; float: none; width: 12em;"><li id="menu-379-1" class="first odd sf-item-1 sf-depth-3 sf-no-children" style="white-space: normal; float: left; width: 100%;"><a href="/bluemasters/site/node/3" title="" class="sf-depth-3" style="float: none; width: auto;">Vestibulum</a></li><li id="menu-380-1" class="last even sf-item-2 sf-depth-3 sf-no-children" style="white-space: normal; float: left; width: 100%;"><a href="/bluemasters/site/node/1" title="" class="sf-depth-3" style="float: none; width: auto;">Proin dui</a></li></ul></li><li id="menu-381-1" class="last odd sf-item-3 sf-depth-2 sf-no-children" style="white-space: normal; float: left; width: 100%;"><a href="/bluemasters/site/node/3" title="" class="sf-depth-2" style="float: none; width: auto;">Praesent</a></li></ul></li><li id="menu-312-1" class="middle odd sf-item-3 sf-depth-1 sf-no-children"><a href="/bluemasters/site/node/1" class="sf-depth-1">Portfolio</a></li><li id="menu-386-1" class="middle even sf-item-4 sf-depth-1 sf-no-children"><a href="/bluemasters/site/blog" title="" class="sf-depth-1">Blog</a></li><li id="menu-363-1" class="last odd sf-item-5 sf-depth-1 sf-no-children"><a href="/bluemasters/site/contact" title="Contact" class="sf-depth-1">Contact</a></li></ul></div>
</div>
               		 </div> 
                    </div>
                   
               		 </div> 
				</div>
			</div>
      
           
                <!--EOF:navigation-->
            </div>
           
        </div>
        <!--EOF:header-->
<div id="wrapper-banner">
        <div class="container_12">
            
            <div class="grid_12">
                <!--banner-->
                <div id="banner">
                <?php print render($page['banner']); ?>
                
                
            	</div>
            </div>      
        </div>
    </div>
<section id="Services" data-menu-offset="-100">    
 <div id="wrapper-green">
        <div class="container_12">
        	<div class="grid_12"> 
              <div id="fullwidth" class="clearfix">
       
            <div class="grid_12">
                <!--home-block-area-->
                <div id="home-blocks-area" class="clearfix">
                
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
                            <div class="home-block-area">
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
                    
                <!--EOF:services-area-->
            </div>    

        </div>

    </div>
    <!--EOF:wrapper-->
<section id="Portfolio" data-menu-offset="-100">    
    <div id="wrapper-portfolio">
            <div class="container_12">
       
            <div class="grid_12">
                <div id="thumbnails" class="clearfix">
                <?php print render($page['portfolio']);?> 
                
                </div>
                </div>
                </div>
                </div>
                
    <section id="Extra">
       <div id="wrapper-default">
            <div class="container_12">
       
            <div class="grid_12">
                <div id="default" class="clearfix">
                <?php print render($page['default']);?> 
                
                </div>
                </div>
                </div>
                </div>
         <section id="Social" data-menu-offset="-100">        
           <div id="wrapper-social">
            <div class="container_12">
       
            <div class="grid_12">
                <div id="social" class="clearfix">
                <?php print render($page['social']);?> 
                
                
                </div>
                </div>
                </div>
                </div>
                 <!--about-area-->
     <section id="About" data-menu-offset="-100">          
   		<div id="wrapper-about">
            <div class="container_12">
              <div class="grid_12">
                <div id="about_area" class="clearfix">
                            <div id="about_fullwidth" class="clearfix">
                                 <?php print render($page['about_fullwidth']);?> 
                
                </div>
                </div>
                                
                            </div>
                        </div>
                    </div>
         <section id="Extra2" data-menu-offset="-100">           
           <div id="wrapper-white_section2">
            <div class="container_12">
              <div class="grid_12">
                <div id="white_section2" class="clearfix">
                            <div id="white-2" class="clearfix">
                                 <?php print render($page['white_section2']);?> 
                
                </div>
                </div>
                                
                            </div>
                        </div>
                    </div>
             <section id="Contact" data-menu-offset="-100">      
              <div id="wrapper_contact">
            	<div class="container_12">
              		<div class="grid_12">
               			 <div id="contact" class="clearfix">
                            <div id="contact" class="clearfix">
                                 <?php print render($page['contact']);?> 
                
                                
                            </div>
                        </div>
                    </div>
                <!--EOF:about-area-->
            </div>    

        </div>

    </section>
               

    <!--footer-bottom-->
    <div id="footer-bottom">
        
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
        	   <div class="credits-container" style="clear:both; padding-top:12px;">A Copyright Would Look AWESOME Here</div>     
            </div>

        </div>

        <div class="container_12">

            <div class="grid_12">
                
            </div>

        </div>  

    </div>
    
    <!--EOF:footer-bottom-->
<script type="text/javascript">
   /* var s = skrollr.init({
		forceHeight: false
	});

skrollr.menu.init(s, {
	animate: true,
    easing: 'sqrt',
    scale: 2,
    duration: function(currentTop, targetTop) {
        return 500;
    },
    handleLink: function(link) {
        return 250;
    }
});*/

//setTimeout(function() {
		var s = skrollr.init({
			forceHeight: false
		});

		skrollr.menu.init(s);
	//}, 500);
</script>
</div>
<!--EOF:page-->