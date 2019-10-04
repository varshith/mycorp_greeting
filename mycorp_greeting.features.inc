<?php

/**
 * @file
 * mycorp_greeting.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function mycorp_greeting_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_node_info().
 */
function mycorp_greeting_node_info() {
  $items = array(
    'greeting' => array(
      'name' => t('Greeting'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
