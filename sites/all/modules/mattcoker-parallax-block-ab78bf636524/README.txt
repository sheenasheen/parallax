<script>
	var controller;
	$(document).ready(function($) {
		// init controller
		controller = new ScrollMagic();
	});
</script>
 
<div class="spacer s2"></div>
<div id="trigger1" class="spacer s0"></div>
<div id="pin1" class="box2 blue">
<h1>Who is john doe?</h1>
	<p>Fry! Stay back! He's too powerful! What's with you kids?</p> 
   <p>Every other day it's food, food, food. Alright, I'll get you some stupid food.</p> 
</div>
<div class="spacer s2"></div>
<script>
	$(document).ready(function($) {
		// build scene
		var scene = new ScrollScene({triggerElement: "#trigger1", duration: 300})
						.setPin("#pin1")
						.addTo(controller);

		// show indicators (requires debug extension)
		scene.addIndicators();
	});
</script>


 
Light Background Presentation