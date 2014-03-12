<?php

$PersonalStyle = $Values['personal_style'];

if( !empty($PersonalStyle) ) {

  $CSS .= <<< EOT
\n/* Custom CSS */
$PersonalStyle
\n/* End Custom CSS */
EOT;

}

?>
