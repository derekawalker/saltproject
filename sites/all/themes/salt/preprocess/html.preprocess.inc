<?php

/**
 * Implements hook_preprocess_html().
 */
function salt_preprocess_html(&$variables) {
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

  drupal_add_css('http://fonts.googleapis.com/css?family=Arvo:400,700,400italic,700italic|Lato:100,300,400,700,400italic,700italic|Waiting+for+the+Sunrise|Open+Sans:300italic,400italic,700italic,700,400',array('type' => 'external'));

  drupal_add_css('http://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css', array('type' => 'external'));

  drupal_add_js(drupal_get_path('theme', 'salt') . '/js/jquery.sticky-kit.min.js');

  drupal_add_js(
    '<script async src="//pagead2.googlesyndication.com/pagead/js/adsbygoogle.js"></script>
    <script>
    (adsbygoogle = window.adsbygoogle || []).push({
      google_ad_client: "ca-pub-1610895198490741",
      enable_page_level_ads: true
    });
    </script>'
  );

  // add meta tag for the homepage only
  if (drupal_is_front_page()) {
    // Add a pinterest auth tag
    $pinterest_auth = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'p:domain_verify',
        'content' => '76ee92ea0801337c66d76b4da2f8b461',
      ),
    );
    $pinterest_auth2 = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'p:domain_verify',
        'content' => '00510accd41c19cd98aa8ba81c8bfc16',
      ),
    );
    drupal_add_html_head($pinterest_auth, 'salt_pinterest_auth');
    drupal_add_html_head($pinterest_auth2, 'salt_pinterest_auth2');
  }

}
