jQuery(document).ready(function($) {	

	//Set Default State of each portfolio piece
	$(".paging").show();
	$(".paging a:first").addClass("active");

	//Get size of images, how many there are, then determin the size of the image reel.
	var imageWidth = $(".window").width();
	var imageSum = $(".image_reel img").size();
	var imageReelWidth = imageWidth * imageSum;
	
	//Adjust the image reel to its new size
	$(".image_reel").css({'width' : imageReelWidth});

	//Paging + Slider Function
	rotate = function(){	
	    var triggerID = $active.attr("rel") - 1; //Get number of times to slide
	    var image_reelPosition = triggerID * imageWidth; //Determines the distance the image reel needs to slide
	
	    $(".paging a").removeClass('active'); //Remove all active class
	    $active.addClass('active'); //Add active class (the $active is declared in the rotateSwitch function)
	    
		$(".desc").stop(true,true).slideUp('slow');
		
		$(".desc").eq( $('.paging a.active').attr("rel") - 1 ).slideDown("slow"); 
		
	    //Slider Animation
	    $(".image_reel").animate({ 
	        left: -image_reelPosition
	    }, 500 ); 
	
		
	}; 

	//Rotation + Timing Event
	rotateSwitch = function(){	
	$(".desc").eq( $('.paging a.active').attr("rel") - 1 ).slideDown("slow");	
	    play = setInterval(function(){ //Set timer - this will repeat itself every 3 seconds
	        $active = $('.paging a.active').next();
	        if ( $active.length === 0) { //If paging reaches the end...
	            $active = $('.paging a:first'); //go back to first
	        }
	        rotate(); //Trigger the paging and slider function
	    }, 10000); //Timer speed in milliseconds (3 seconds)	
	
	};
	
	rotateSwitch(); //Run function on launch

 //On Click
    $(".paging a").click(function() {    
        $active = $(this); //Activate the clicked paging
        //Reset Timer
        clearInterval(play); //Stop the rotation
        rotate(); //Trigger rotation immediately
        rotateSwitch(); // Resume rotation
        return false; //Prevent browser jump to link anchor
    });    

});

/**
 * Created by Sallar Kaboli <sallar.kaboli@gmail.com>
 * @sallar
 * 
 * Released under the MIT License.
 * http://sallar.mit-license.org/
 * 
 * This document demonstrates three things:
 * 
 * - Creating a simple parallax effect on the content
 * - Creating a Medium.com-style blur on scroll image
 * - Getting scroll position using requestAnimationFrame for better performance
 */


/**
 * Cache
 */
var $content = $('header .content')
  , $blur    = $('header .overlay')
  , wHeight  = $(window).height();

$(window).on('resize', function(){
  wHeight = $(window).height();
});

/**
 * requestAnimationFrame Shim 
 */
window.requestAnimFrame = (function()
{
  return  window.requestAnimationFrame       ||
          window.webkitRequestAnimationFrame ||
          window.mozRequestAnimationFrame    ||
          function( callback ){
            window.setTimeout(callback, 1000 / 60);
          };
})();

/**
 * Scroller
 */
function Scroller()
{
  this.latestKnownScrollY = 0;
  this.ticking            = false;
}

Scroller.prototype = {
  /**
   * Initialize
   */
  init: function() {
    window.addEventListener('scroll', this.onScroll.bind(this), false);
  },

  /**
   * Capture Scroll
   */
  onScroll: function() {
    this.latestKnownScrollY = window.scrollY;
    this.requestTick();
  },

  /**
   * Request a Tick
   */
  requestTick: function() {
    if( !this.ticking ) {
      window.requestAnimFrame(this.update.bind(this));
    }
    this.ticking = true;
  },

  /**
   * Update.
   */
  update: function() {
    var currentScrollY = this.latestKnownScrollY;
    this.ticking       = false;
    
    /**
     * Do The Dirty Work Here
     */
    var slowScroll = currentScrollY / 4
      , blurScroll = currentScrollY * 2;
    
    $content.css({
      'transform'         : 'translateY(-' + slowScroll + 'px)',
      '-moz-transform'    : 'translateY(-' + slowScroll + 'px)',
      '-webkit-transform' : 'translateY(-' + slowScroll + 'px)'
    });
    
    $blur.css({
      'opacity' : blurScroll / wHeight
    });
  }
};

/**
 * Attach!
 */
var scroller = new Scroller();  
scroller.init();
