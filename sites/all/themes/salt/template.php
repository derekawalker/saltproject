<?php

/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * salt theme.
 */

/**
 * Overrides theme_on_the_web_image().
 */
function salt_on_the_web_image($variables) {
  return $variables['service'];
}
