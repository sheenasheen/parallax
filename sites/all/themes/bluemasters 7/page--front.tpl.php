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

   <!--header-->
<div id="header" class="clearfix container_12">    
<div id="container_12 NavBG">
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
                   <?php print drupal_render($page['navigation']); ?>
                  <!-- <ul id="Navitems">
                 	 <li><a href="#section-Services">Services</a></li>
                     <li><a href="#section2-Portfolio">Portfolio</a></li>
                     <li><a href="#section-Extra">Extra</a></li>
                     <li><a href="#section-Social">Social</a></li>
                     <li><a href="#section-About">About</a></li>
                     <li><a href="#section-Extra2">Extra2</a></li>
                     <li><a href="#section-Contact">Contact</a></li>
                   </ul>
                    
                </div>
                </div>-->
       
                <input type='checkbox' id='toggle'/>
                <div>
                    <label for='toggle' class='toggle'></label>
                        <ul class="menu">
                     <li><a href="#section-Services">Services</a></li>
                     <li><a href="#section2-Portfolio">Portfolio</a></li>
                     <li><a href="#section-Extra">Extra</a></li>
                     <li><a href="#section-Social">Social</a></li>
                     <li><a href="#section-About">About</a></li>
                     <li><a href="#section-Extra2">Extra2</a></li>
                     <li><a href="#section-Contact">Contact</a></li>
                        </ul>
                        
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

    </div>
                
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
	skrollr.init({
		forceHeight: false
	});
	
    var s = skrollr.init();

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
});
</script>
</div>
<!--EOF:page-->