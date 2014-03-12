/*! WebStudio - v0.0.1 - 2014-01-21 */!function(a){"use strict";return a(document).ready(function(){return a.support.transition||(a.fn.transition=a.fn.animate),jQuery("#MainMenu > .mainmenu > .dropdown > .dropdown-toggle").dropdownHover(),a("[rel='tooltip']").tooltip(),a("[data-toggle='popover']").popover(),a(".alert").bind("closed",function(){return this.remove()}),a(".alert").bind("close",function(){return a(this).animate({opacity:0,marginTop:0,marginBottom:0,height:"toggle"},"slow",function(){return a(this).trigger("closed")})}),a(".big-title, .block-title , .tl").wrapInner("<span class='hline' />"),Modernizr.canvas&&a(".hline").prepend("<canvas class='line-55' width='55px' height='1px' data-animation='load' data-delay='250' />"),a(".field-type-video-embed-field").fitVids(),a(".media-vimeo-preview-wrapper").fitVids(),a(".player").fitVids(),a('.brand:contains("webstudio"), .block-title:contains("webstudio")').each(function(){return a(this).html(a(this).html().split("webstudio").join('<span class="light">web</span><span class="semibold">studio</span>'))})})}(jQuery),jQuery.expr[":"].regex=function(a,b,c){"use strict";var d,e,f,g,h;return e=c[3].split(","),h=/^(data|css):/,d={method:e[0].match(h)?e[0].split(":")[0]:"attr",property:e.shift().replace(h,"")},g="ig",f=new RegExp(e.join("").replace(/^\s+|\s+$/g,""),g),f.test(jQuery(a)[d.method](d.property))},function(a){"use strict";return Drupal.setColor=function(b,c){var d;return console.log(b),console.log(c),d=document.getElementById(c),a(d).css({background:"blue"})},Drupal.initCustomizer=function(){var b;return b=a("<div>",{id:"customizer","class":"customizer"}),a("body").append(b)},Drupal.PopoverSwipe=function(b){var c;return c=a("<div>",{id:"info-swipe","class":"SwipeInfo text-right","data-toggle":"popover","data-content":"Some Content here for the Swipe usage details :)","data-original-title":"Popup title here for detail","data-placement":"right"}),c.html("<i class='icon-eye-open'> </i>"),a(b).after(c)},Drupal.behaviors.Customizer={attach:function(b,c){var d,e;return d={debug:!1},e=a.extend({},d,c.customizer),a("body",b).once("Customizer",function(){return e.debug&&console.log("Customizer behavior loaded..."),Drupal.initCustomizer(),a(".region-name-debug",b).on("click",function(){var b,c;return a(this).toggleClass("active"),b=a(this).data("target"),c=a(this).closest(".wrapper,.wrapper-debug"),c.toggleClass("OutLined")})})}}}(jQuery),function(a,b,c){"use strict";var d,e,f;return f="tbAnimation",e={debug:!1,property:"value"},d=function(){function b(b,c){this.element=b,this.settings=a.extend({},e,c),this._defaults=e,this._name=f,this.init()}return b.prototype.init=function(){return this.play()},b.prototype.log=function(a){return this.settings.debug?"undefined"!=typeof console&&null!==console?console.log(a):void 0:void 0},b.prototype.play=function(){var b,c,d;return d=a(this.element),d.data("animation")&&(b=d.data("animation"),this.log("data-animation value : "+b)),d.data("delay")&&(c=d.data("delay"),this.log("data-delay value : "+c)),d.bind("inview",function(a,e,f,g){var h;return e?(c?h=setTimeout(function(){return d.addClass("animated "+b),d.removeData("delay")},c):d.addClass("animated "+b),void 0):clearTimeout(h)})},b}(),a.fn[f]=function(b){return this.each(function(){return a.data(this,"plugin_"+f)?void 0:a.data(this,"plugin_"+f,new d(this,b))})},a(c).ready(function(){return a("body:not(.page-node-edit) [data-animation]").tbAnimation({debug:!1})})}(jQuery,window,document),function(a,b,c){"use strict";var d,e,f;return f="tbBgc",e={debug:!1},d=function(){function b(b,c){this.element=b,this.settings=a.extend({},e,c),this._defaults=e,this._name=f,this.init()}return b.prototype.init=function(){return this.getCss(),this.getData()},b.prototype.log=function(a){return this.settings.debug?"undefined"!=typeof console&&null!==console?console.log(a):void 0:void 0},b.prototype.getCss=function(){var b,c,d,e;return b=a(this.element),b.attr("class")?b.attr("class").toString().match(/\b(bgc-\w*)\b/g)?(c=b.attr("class").toString().match(/\b(bgc-\w*)\b/g).toString().split("-"),d=c[1],e=/(^[0-9A-F]{6}$)|(^[0-9A-F]{3}$)/i.test(d),e&&(d="#"+d),b.css("background-color",d)):void 0:!1},b.prototype.getData=function(){var b,c,d;return b=a(this.element),this.log(b.data("bgc")),b.data("bgc")?(c=b.data("bgc"),d=/(^[0-9A-F]{6}$)|(^[0-9A-F]{3}$)/i.test(c),d&&(c="#"+c),b.css("background-color",c)):void 0},b}(),a.fn[f]=function(b){return this.each(function(){return a.data(this,"plugin_"+f)?void 0:a.data(this,"plugin_"+f,new d(this,b))})},a(c).ready(function(){return a("[data-bgc], [class^='bgc-'],[class*=' bgc-']").tbBgc({debug:!1})})}(jQuery,window,document),function(a,b,c){"use strict";var d,e,f;return f="tbFsize",e={debug:!1,property:"value"},d=function(){function b(b,c){this.element=b,this.settings=a.extend({},e,c),this._defaults=e,this._name=f,this.init()}return b.prototype.init=function(){return this.setFont()},b.prototype.log=function(a){return this.settings.debug?"undefined"!=typeof console&&null!==console?console.log(a):void 0:void 0},b.prototype.setFont=function(){var b,c;return b=a(this.element),b.data("fsize")?(c=b.data("fsize"),this.log("data-fsize value : "+c)):(c=b.attr("class").toString().match(/fsize-\d+/g).toString().split("-"),c=c[1]),a.isNumeric(c)&&(c+="px"),b.css("font-size",c),b.css("line-height","1.4em")},b}(),a.fn[f]=function(b){return this.each(function(){return a.data(this,"plugin_"+f)?void 0:a.data(this,"plugin_"+f,new d(this,b))})},a(c).ready(function(){return a("[data-fsize], [class^='fsize-'],[class*=' fsize-']").tbFsize({debug:!1})})}(jQuery,window,document),function(a,b,c){"use strict";var d,e,f;return f="tbMargin",e={debug:!1},d=function(){function b(b,c){this.element=b,this.settings=a.extend({},e,c),this._defaults=e,this._name=f,this.init()}var c;return b.prototype.init=function(){return this.setFromData(),this.setFromClass()},c=Array.isArray||function(a){return"[object Array]"==={}.toString.call(a)},b.prototype.log=function(a){return this.settings.debug?"undefined"!=typeof console&&null!==console?console.log(a):void 0:void 0},b.prototype.setFromData=function(){var b,c;return b=a(this.element),b.data("margin")&&(c=b.data("margin"),(a.isNumeric(c.top)||a.isNumeric(c.bottom)||a.isNumeric(c.left)||a.isNumeric(c.right))&&(c.top&&(c.top=c.top+"px"),c.bottom&&(c.bottom=c.bottom+"px"),c.left&&(c.left=c.left+"px"),c.right&&(c.right=c.right+"px")),c.top&&b.css("margin-top",c.top),c.bottom&&b.css("margin-bottom",c.bottom),c.left&&b.css("margin-left",c.left),c.right)?b.css("margin-right",c.right):void 0},b.prototype.setFromClass=function(){var b,d,e,f,g,h,i,j,k;if(b=a(this.element),f=b.attr("class"),f&&(f=b.attr("class").toString().match(/\b(margin-\w*-\d*)\b/g),c(f))){for(k=[],i=0,j=f.length;j>i;i++)e=f[i],d=e.split("-"),g=d[1],h=d[2],k.push(a(this.element).css("margin-"+g,h+"px"));return k}},b}(),a.fn[f]=function(b){return this.each(function(){return a.data(this,"plugin_"+f)?void 0:a.data(this,"plugin_"+f,new d(this,b))})},a(c).ready(function(){return a("[data-margin], [class^='margin-'],[class*=' margin-']").tbMargin({debug:!0})})}(jQuery,window,document),function(a,b,c){"use strict";var d,e,f;return f="tbPadding",e={debug:!1},d=function(){function b(b,c){this.element=b,this.settings=a.extend({},e,c),this._defaults=e,this._name=f,this.init()}var c;return b.prototype.init=function(){return this.setFromData(),this.setFromClass()},c=Array.isArray||function(a){return"[object Array]"==={}.toString.call(a)},b.prototype.log=function(a){return this.settings.debug?"undefined"!=typeof console&&null!==console?console.log(a):void 0:void 0},b.prototype.setFromData=function(){var b,c;return b=a(this.element),b.data("padding")&&(c=b.data("padding"),(a.isNumeric(c.top)||a.isNumeric(c.bottom)||a.isNumeric(c.left)||a.isNumeric(c.right))&&(c.top&&(c.top=c.top+"px"),c.bottom&&(c.bottom=c.bottom+"px"),c.left&&(c.left=c.left+"px"),c.right&&(c.right=c.right+"px")),c.top&&b.css("padding-top",c.top),c.bottom&&b.css("padding-bottom",c.bottom),c.left&&b.css("padding-left",c.left),c.right)?b.css("padding-right",c.right):void 0},b.prototype.setFromClass=function(){var b,d,e,f,g,h,i,j,k;if(b=a(this.element),f=b.attr("class"),f&&(f=b.attr("class").toString().match(/\b(padding-\w*-\d*)\b/g),c(f))){for(k=[],i=0,j=f.length;j>i;i++)e=f[i],d=e.split("-"),g=d[1],h=d[2],k.push(a(this.element).css("padding-"+g,h+"px"));return k}},b}(),a.fn[f]=function(b){return this.each(function(){return a.data(this,"plugin_"+f)?void 0:a.data(this,"plugin_"+f,new d(this,b))})},a(c).ready(function(){return a("[data-padding], [class^='padding-'],[class*=' padding-']").tbPadding({debug:!0})})}(jQuery,window,document);