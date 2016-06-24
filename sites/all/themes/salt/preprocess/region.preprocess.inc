<?php

/**
 * Implements hook_preprocess_region().
 */
function salt_preprocess_region(&$variables, $hook) {
	$variables['classes_array'][] = 'group';
}
