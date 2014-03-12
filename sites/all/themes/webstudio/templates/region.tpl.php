<?php

/**
 * @file
 * Default theme implementation to display a region.
 *
 * Available variables:
 * - $content: The content for this region, typically blocks.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the following:
 *   - region: The current template type, i.e., "theming hook".
 *   - region-[name]: The name of the region with underscores replaced with
 *     dashes. For example, the page_top region would have a region-page-top class.
 * - $region: The name of the region variable as defined in the theme's .info file.
 *
 * Helper variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $is_admin: Flags true when the current user is an administrator.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 *
 * @see template_preprocess()
 * @see template_preprocess_region()
 * @see template_process()
 */

  $debugClass = "bare";
  if ( theme_get_setting('debug') ) {
    // $classes .= ' regions-debug-info';

    // regions[highlighted]    = 'Highlighted'

    // regions[help]           = 'Help'

    // regions[sidebar_first]  = 'Primary'
    // regions[content_top]    = 'Content Top'
    // regions[content]        = 'Content'
    // regions[content_bottom] = 'Content Bottom'
    // regions[sidebar_second] = 'Secondary'


    if ($region=='highlighted'||$region=='help'||$region=='sidebar_first'||$region=='content_top'||$region=='content'||$region=='content_bottom'||$region=='sidebar_second')
      $debugClass = NULL;

      switch ($region) {
        case 'highlighted':
          $target = extra::camelCase($region);
          break;
        case 'help':
          $target = extra::camelCase($region);
          break;
        case 'sidebar_first':
          $target = extra::camelCase($region);
          break;
        case 'content_top':
          $target = extra::camelCase($region);
          break;
        case 'content':
          $target = extra::camelCase($region);
          break;
        case 'content_bottom':
          $target = extra::camelCase($region);
          break;
        case 'sidebar_second':
          $target = extra::camelCase($region);
          break;
        default:
          $target = extra::camelCase($region). "Wrapper";
          break;
      }

    }


?>

<?php

if ( theme_get_setting('debug') ) {
  $name = strtoupper(str_replace('_', '', $region));

  print ($debugClass) ? "" : '<div class="regions-debug-info">';

  print t('<div class="region-name-debug !debugClass" data-outline="wrapper" data-target="!target" ><i class="icon-code"></i> !name </div>',
    array(
      '!debugClass' => $debugClass,
      '!name'=> $name,
      '!target' => $target
    )
  );
}

?>

<?php if ($content): ?>
  <div class="<?php print $classes; ?>">
    <?php print $content; ?>
  </div>
<?php endif; ?>

<?php  if (theme_get_setting('debug')) {

  print  ($debugClass) ? "" : '</div>';

  } ?>
