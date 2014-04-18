/**
 * @file
 * Enable Parallax effect for any block created by the user
 *
 * This module enables the user to select none, Same, or Opposite directions
 * when creating a block. Selecting Same or Opposite places a data attribute
 * which is ready by the attached javascript file, and then targeted for
 * calculations causing parallax effect based on 'same' or 'opposite' value.
 */

(function ($, Drupal, window, document, undefined) {


  Drupal.behaviors.parallax_block = {
    attach: function(context, settings) {

    $(function() {
      $(document).ready(function(){

        var targets = $("[data-parallax]").toArray();

        // Enable parallax only if not mobile device
        if (/Android|webOS|iPhone|iPad|iPod|BlackBerry|IEMobile|Opera Mini/i.test(navigator.userAgent) === false) {
          enableParallax(targets);
        }
      });
    });
    }
  };

  // This function currently accepts an array of target selectors in the form
  // of strings, cycled through for parallax effects.
  function enableParallax(targetsObj) {
    $.each(targetsObj, function(){
      var currentObj = "#" + $(this).attr('id').toString();

      // check if object exists on page
      if (currentObj.length > 0) {
        $(window).load(function() {
          parallaxCalculation(currentObj);
        });
        $(window).scroll(function() {
          parallaxCalculation(currentObj);
        });
        $(window).resize(function() {
          parallaxCalculation(currentObj);
        })
      }
    });
  }

  // Determines if each element passed to enableParallax is in the viewport and
  // passes through TRUE when element dimensions first are visible in viewport
  function isScrolledIntoView(elem) {
    var docViewTop = $(window).scrollTop();
    var docViewBottom = docViewTop + $(window).height();

    if ($(elem).offset() != null) {
      var elemTop = $(elem).offset().top;
      var elemBottom = elemTop + $(elem).height();

      return ((elemTop <= docViewBottom) && (elemBottom >= docViewTop));
    } else {
      return true;
    }
  }

  function parallaxCalculation(currentObj) {

    if (isScrolledIntoView(currentObj)) {   //On Scroll or Load, check if object is in view

      // Calculate position of top of target element relative to top of page
      // and height of target element
      var divTop = $(currentObj).offset().top;
      var divHeight = $(currentObj).height();

      // Calculate distance scrolled from top, the center of the viewport
      // (necessary for calculations), and the height of the viewport
      var docViewTop = $(window).scrollTop();
      var docViewSize = $(window).height();
      var docViewCenter = docViewTop + (docViewSize / 2);

      // Calculate the full range of effective parallax movement on the page
      var fullRange = docViewSize + divHeight;

      // My head hurts too much to explain this one. Ask Kyle.
      var currPosition = docViewCenter - (divTop - (docViewSize / 2));

      // Calculate percentage location of current position baseed on full range of parallax movement
      var currVerticalPercentage = (currPosition / fullRange) * 100;
      var currHorizontalPercentage = (currPosition / fullRange) * 100;

      // Determines if vertical parallax direction is opposite, and invertes the value
      // on a scale of 1-100
      if (($(currentObj).attr('data-parallax').indexOf("opposite") > -1)) {
        $(currentObj).attr("data-position", currVerticalPercentage);
        currVerticalPercentage = 100 - $(currentObj).attr("data-position");
      }
      if (($(currentObj).attr('data-parallax').indexOf("rtl") > -1)) {
        $(currentObj).attr("data-position", currHorizontalPercentage);
        currHorizontalPercentage = 100 - $(currentObj).attr("data-position");
      }

      var dataValues = $(currentObj).attr("data-parallax").split(" ");

      console.log(dataValues);
      if (dataValues[0] != "none") {
        coords = currVerticalPercentage + "%";
      } else {
        coords = "50%";
      }

      if (dataValues[1] != "none") {
        coords += " " + currHorizontalPercentage + "%";
      } else {
        coords += " 50%";
      }
      console.log(coords);

      // Set percentage based on calculation
      // var coords = '50% ' + currPercentage + '%';

      // Apply background Position and apply background-size: Cover to avoid image tiling
      $(currentObj).css({ "backgroundPosition": coords, "backgroundSize": "cover" });
    }
  }
})(jQuery, Drupal, this, this.document);
