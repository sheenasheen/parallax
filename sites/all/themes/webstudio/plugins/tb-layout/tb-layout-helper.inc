<?php

/**
 * custom_classes function
 *
 * @return array
 * @author
 **/
function custom_classes(){
  $options = array(
    'Pull' => array(
      'pull-right' => t('Pull right'),
      'pull-left' => t('Pull left'),
    ),
    'Center' => array(
      'mobile-centered' => t('Mobile centered'),
      'tablet-centered' => t('Tablet centered'),
      'centered'  => t('Centered'),
    ),
    'Visible' => array(
      'visible-phone'   => t("Phone"),
      'visible-tablet'  => t("Tablet") ,
      'visible-desktop' => t("Dekstop"),
    ),
    'Hidden' => array(
      'hidden-phone'   => t("Phone"),
      'hidden-tablet'  => t("Tablet") ,
      'hidden-desktop' => t("Dekstop"),
    )
  );
  // asort($options);
  return $options;
}
