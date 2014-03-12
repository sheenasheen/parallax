/*
--------------------------------------------------------------------------------
Theme Settings Global Script
--------------------------------------------------------------------------------
*/

(function($) {
  "use strict";
  return Drupal.behaviors.tbSlider = {
    attach: function(context, settings) {
      var defaults, options;
      defaults = {
        debug: false,
        items: []
      };
      options = $.extend({}, defaults, settings.tbslider);
      if (options.debug) {
        console.log(options);
      }
      return _.each(options.items, function(value, key, list) {
        var default_value, sliderControl, sliderField;
        sliderControl = $("[data-name=" + key + "]");
        sliderField = $("[name=" + key + "]");
        default_value = sliderField.val();
        sliderControl.slider({
          min: value.min,
          max: value.max,
          range: "min",
          step: value.step,
          value: default_value,
          slide: function(event, ui) {
            return sliderField.val(ui.value);
          }
        });
        return sliderField.change(function() {
          value = this.value;
          console.log(value);
          return sliderControl.slider("value", parseInt(value, 10));
        });
      });
    }
  };
})(jQuery);

(function($) {
  "use strict";
  return Drupal.behaviors.GWFSelector = {
    attach: function(context, settings) {
      var defaults, options;
      if (!settings.theme_settings.show_font_variant) {
        return false;
      }
      defaults = {
        debug: false
      };
      options = $.extend({}, defaults, settings.fonts_variant);
      return $(".gwf-selector", context).once("GWFSelector", function() {
        $(this).each(function() {
          var intel, intname, intval;
          intval = $(this).val();
          intname = $(this).attr("name");
          intel = intname + "_weight";
          if (intval !== "0") {
            return $("input[name=" + intel + "]").each(function() {
              var intCr, intElm;
              intCr = $(this).val();
              intElm = $(this);
              intElm.closest(".form-item").removeClass("enable");
              intElm.closest(".form-item").addClass("disable");
              intElm.prop("disabled", true);
              return $.each(options[intval], function(int) {
                if (int === intCr) {
                  intElm.prop("disabled", false);
                  intElm.closest(".form-item").removeClass("disable");
                  return intElm.closest(".form-item").addClass("enable");
                }
              });
            });
          } else {
            return $("input[name=" + intel + "]").prop("disabled", true);
          }
        });
        return $(this).change(function() {
          var el, name, value;
          value = $(this).val();
          name = $(this).attr("name");
          el = name + "_weight";
          if (value !== "0") {
            return $("input[name=" + el + "]").each(function() {
              var currentv, element;
              currentv = $(this).val();
              element = $(this);
              element.closest(".form-item").removeClass("enable");
              element.closest(".form-item").addClass("disable");
              element.prop("disabled", true);
              return $.each(options[value], function(intValue) {
                if (intValue === currentv) {
                  element.prop("disabled", false);
                  element.closest(".form-item").removeClass("disable");
                  return element.closest(".form-item").addClass("enable");
                }
              });
            });
          } else {
            $("input[name=" + el + "]").prop("disabled", true);
            $(".typo-font-weight.typo-gwf .form-item").removeClass("enable");
            return $(".typo-font-weight.typo-gwf .form-item").addClass("disable");
          }
        });
      });
    }
  };
})(jQuery);

(function($) {
  "use strict";
  Drupal.behaviors.tbBootstrapSwitch = {
    attach: function(context, settings) {
      var default_settings, wrapper;
      default_settings = {
        data_on: "success",
        data_off: "danger",
        size: null,
        animated: true,
        on_label: "ON",
        off_label: "OFF"
      };
      settings = $.extend(default_settings, settings.BTSwitch);
      wrapper = $("<div/>", {
        "class": "switch " + settings.size,
        "data-on": settings.data_on,
        "data-off": settings.data_off,
        "data-animated": settings.animated,
        "data-on-label": settings.on_label,
        "data-off-label": settings.off_label
      });
      return $(".form-type-checkbox", context).each(function() {
        return $("input", $(this)).wrap(wrapper);
      });
    }
  };
  return $(document).ready(function() {
    return $(".switch").bootstrapSwitch();
  });
})(jQuery);

(function($) {
  "use strict";
  return $(document).ready(function() {
    var options;
    options = {
      animationSpeed: 100,
      animationEasing: "swing",
      changeDelay: 0,
      control: "hue",
      defaultValue: "",
      hide: null,
      hideSpeed: 100,
      inline: false,
      letterCase: "lowercase",
      opacity: true,
      position: "default",
      show: null,
      showSpeed: 100,
      swatchPosition: "left",
      textfield: true,
      theme: "default",
      change: function(hex, opacity) {
        var name, op_field;
        hex = hex;
        name = $(this).attr("name");
        op_field = $("[name=" + name + "_op]");
        return op_field.val(opacity);
      }
    };
    $(".minicolors").minicolors(options);
    return $("#system-theme-settings").bind("state:visible", function(e) {
      if (e.trigger) {
        return $(e.target).closest(".form-item, .form-submit, .form-wrapper")[(e.value ? "slideToggle" : "slideToggle")]();
      }
    });
  });
})(jQuery);

/*Live Preview Action*/


(function($, window, document) {
  "use strict";
  var Plugin, defaults, pluginName;
  pluginName = "tbPreview";
  defaults = {
    debug: true,
    background: null,
    color: null,
    border: null,
    shadow: false,
    _shadow: "1px 1px 2px",
    link: null,
    hover: null
  };
  Plugin = (function() {
    function Plugin(element, options) {
      this.element = element;
      this.settings = $.extend({}, defaults, options);
      this._defaults = defaults;
      this._name = pluginName;
      this.init();
    }

    Plugin.prototype.init = function() {
      return this.log("Preview Loaded");
    };

    Plugin.prototype.set = function(options) {
      this.settings = $.extend({}, defaults, options);
      if (this.settings.shadow) {
        this.settings.shadow = this.settings._shadow + this.settings.shadow;
      }
      $(this.element).css("background-color", this.settings.background);
      $(this.element).css("color", this.settings.color);
      $(this.element).css("text-shadow", this.settings.shadow);
      $("a", this.element).css("color", this.settings.link);
      return $("hr", this.element).css("background-color", this.settings.border);
    };

    Plugin.prototype.hex2rgba = function(hex, opacity) {
      var matches, patt, rgb;
      patt = /^#([\da-fA-F]{2})([\da-fA-F]{2})([\da-fA-F]{2})$/;
      matches = patt.exec(hex);
      return rgb = "rgba(" + parseInt(matches[1], 16) + "," + parseInt(matches[2], 16) + "," + parseInt(matches[3], 16) + "," + opacity + ");";
    };

    Plugin.prototype.log = function(msg) {
      if (this.settings.debug) {
        return typeof console !== "undefined" && console !== null ? console.log(msg) : void 0;
      }
    };

    return Plugin;

  })();
  $.fn[pluginName] = function(options) {
    return this.each(function() {
      if (!$.data(this, "plugin_" + pluginName)) {
        return $.data(this, "plugin_" + pluginName, new Plugin(this, options));
      }
    });
  };
  $(document).on("click.tbPreview.data-api", "[data-preview]", function(e) {
    var options, preview, region;
    region = $(this).data("preview");
    preview = "." + region + "_preview";
    $(preview).show("slow");
    options = {
      background: $("input[name=" + region + "_bgc]").val(),
      opacity: $("input[name=" + region + "_bgc_opacity]").val(),
      color: $("input[name=" + region + "_color]").val(),
      shadow: $("input[name=" + region + "_shadow]").val(),
      link: $("input[name=" + region + "_link]").val(),
      hover: $("input[name=" + region + "_hover]").val(),
      border: $("input[name=" + region + "_border]").val()
    };
    e.preventDefault();
    $(preview).tbPreview(options);
    return (($(preview)).data("plugin_tbPreview")).set(options);
  });
  return $(document).on("hover.tbPreview.data-api", "[data-region]", function(e) {
    var options, region;
    region = $(this).data("region");
    options = {
      background: $("input[name=" + region + "_bgc]").val(),
      opacity: $("input[name=" + region + "_bgc_opacity]").val(),
      color: $("input[name=" + region + "_color]").val(),
      shadow: $("input[name=" + region + "_shadow]").val(),
      link: $("input[name=" + region + "_link]").val(),
      hover: $("input[name=" + region + "_hover]").val(),
      border: $("input[name=" + region + "_border]").val()
    };
    e.preventDefault();
    return $("a", this).hover(function() {
      return $(this).css("color", options.hover);
    }, function() {
      return $(this).css("color", options.link);
    });
  });
})(jQuery, window, document);
