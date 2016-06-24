<?php

/**
 * Implements hook_preprocess_html().
 */
function five0_preprocess_html(&$variables) {
  if (!empty($variables['page']['sidebar_first']) && !empty($variables['page']['sidebar_second'])) {
    $variables['attributes_array']['class'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['sidebar_first'])) {
    $variables['attributes_array']['class'][] = 'sidebar-first';
  }
  elseif (!empty($variables['page']['sidebar_second'])) {
    $variables['attributes_array']['class'][] = 'sidebar-second';
  }
  else {
    $variables['attributes_array']['class'][] = 'no-sidebars';
  }

	drupal_add_css('http://fonts.googleapis.com/css?family=Lato:300,400,700,400italic,700italic|Open+Sans:300italic,400italic,700italic,700,400',array('type' => 'external'));

}

