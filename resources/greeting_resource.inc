<?php

/**
 * @file
 * Greeting content resource definition and callback functions.
 */

/**
 * Greeting content resource definition.
 *
 * @return array
 */
function _greeting_resource_definition() {
  $greeting_resource = array(
    'greetings' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieve a greeting',
          'file' => array('type' => 'inc', 'module' => 'mycorp_greeting', 'name' => 'resources/greeting_resource'),
          'callback' => '_greeting_resource_retrieve',
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => 'The id of the greeting to retrieve',
            ),
          ),
          'access callback' => '_greeting_resource_access',
          'access arguments' => array('view'),
          'access arguments append' => TRUE,
        ),
        'create' => array(
          'help' => 'Create a greeting',
          'file' => array('type' => 'inc', 'module' => 'mycorp_greeting', 'name' => 'resources/greeting_resource'),
          'callback' => '_greeting_resource_create',
          'args' => array(
            array(
              'name' => 'node',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'The greeting data to create',
              'type' => 'array',
            ),
          ),
          'access callback' => '_greeting_resource_access',
          'access arguments' => array('create'),
          'access arguments append' => TRUE,
        ),
        'update' => array(
          'help' => 'Update a greeting',
          'file' => array('type' => 'inc', 'module' => 'mycorp_greeting', 'name' => 'resources/greeting_resource'),
          'callback' => '_greeting_resource_update',
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => 'The id of the greeting to update',
            ),
            array(
              'name' => 'node',
              'optional' => FALSE,
              'source' => 'data',
              'description' => 'The greeting data to update',
              'type' => 'array',
            ),
          ),
          'access callback' => '_greeting_resource_access',
          'access arguments' => array('update'),
          'access arguments append' => TRUE,
        ),
        'delete' => array(
          'help' => t('Delete a greeting'),
          'file' => array('type' => 'inc', 'module' => 'mycorp_greeting', 'name' => 'resources/greeting_resource'),
          'callback' => '_greeting_resource_delete',
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => 'The id of the greeting to delete',
            ),
          ),
          'access callback' => '_greeting_resource_access',
          'access arguments' => array('delete'),
          'access arguments append' => TRUE,
        ),
        'index' => array(
          'help' => 'List all greetings',
          'file' => array('type' => 'inc', 'module' => 'mycorp_greeting', 'name' => 'resources/greeting_resource'),
          'callback' => '_greeting_resource_index',
          'args' => array(
            array(
              'name' => 'page',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'The zero-based index of the page to get, defaults to 0.',
              'default value' => 0,
              'source' => array('param' => 'page'),
            ),
            array(
              'name' => 'fields',
              'optional' => TRUE,
              'type' => 'string',
              'description' => 'The fields to get.',
              'default value' => '*',
              'source' => array('param' => 'fields'),
            ),
            array(
              'name' => 'parameters',
              'optional' => TRUE,
              'type' => 'array',
              'description' => 'Parameters array',
              'default value' => array(),
              'source' => array('param' => 'parameters'),
            ),
            array(
              'name' => 'pagesize',
              'optional' => TRUE,
              'type' => 'int',
              'description' => 'Number of records to get per page.',
              'default value' => variable_get('services_node_index_page_size', 20),
              'source' => array('param' => 'pagesize'),
            ),
            array(
              'name' => 'options',
              'optional' => TRUE,
              'type' => 'array',
              'description' => 'Additional query options.',
              'default value' => array(
                'orderby' => array(
                  'sticky' => 'DESC',
                  'created' => 'DESC'
                )
              ),
              'source' => array('param' => 'options'),
            ),
          ),
          'access arguments' => array('access content'),
        ),
      ),
      'targeted_actions' => array(
        'publish' => array(
          'help' => t('Publish a specific greeting.'),
          'callback' => '_greeting_resource_publish',
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => t('The id of the greeting to publish'),
            ),
          ),
          'access callback' => '_greeting_resource_access',
          'access arguments' => array('update'),
          'access arguments append' => TRUE,
        ),
        'unpublish' => array(
          'help' => t('Unpublish a specific greeting.'),
          'callback' => '_greeting_resource_unpublish',
          'args' => array(
            array(
              'name' => 'nid',
              'optional' => FALSE,
              'source' => array('path' => 0),
              'type' => 'int',
              'description' => t('The id of the greeting to unpublish'),
            ),
          ),
          'access callback' => '_greeting_resource_access',
          'access arguments' => array('update'),
          'access arguments append' => TRUE,
        ),
      ),
    ),
  );

  return $greeting_resource;
}

/**
 * Callback for greeting content get.
 *
 * @param $nid
 *
 * @return bool|mixed
 */
function _greeting_resource_retrieve($nid) {
  module_load_include('inc', 'services', 'resources/node_resource');

  return _node_resource_retrieve($nid);
}

/**
 * Callback for greeting content create.
 *
 * @param $node
 *
 * @return array|mixed
 */
function _greeting_resource_create($node) {
  // Only create 'greeting' type content.
  $node['type'] = 'greeting';
  module_load_include('inc', 'services', 'resources/node_resource');

  return _node_resource_create($node);
}

/**
 * Callback for greeting content update.
 *
 * @param $nid
 * @param $node
 *
 * @return array|mixed
 */
function _greeting_resource_update($nid, $node) {
  module_load_include('inc', 'services', 'resources/node_resource');

  return _node_resource_update($nid, $node);
}

/**
 * Callback for greeting content delete.
 *
 * @param $nid
 *
 * @return bool
 */
function _greeting_resource_delete($nid) {
  module_load_include('inc', 'services', 'resources/node_resource');

  return _node_resource_delete($nid);
}

/**
 * Callback for greeting content index (list all greetings).
 *
 * @param $page
 * @param $fields
 * @param $parameters
 * @param $page_size
 * @param array $options
 *
 * @return array
 */
function _greeting_resource_index($page, $fields, $parameters, $page_size, $options = array()) {
  // Make sure only content of type 'greeting' is returned.
  $parameters['type'] = 'greeting';
  $options['parameters_op']['type'] = 'IN';
  module_load_include('inc', 'services', 'resources/node_resource');

  return _node_resource_index($page, $fields, $parameters, $page_size, $options);
}

/**
 * Determine whether the current user can access a greeting resource.
 *
 * Code borrowed from _node_resource_access() with some modification to
 * only support greeting content type.
 *
 * @param string $op
 * @param array $args
 *
 * @return bool|mixed
 *
 * @throws ServicesException
 *
 * @see _node_resource_access()
 */
function _greeting_resource_access($op = 'view', $args = array()) {
  // Adds backwards compatability with regression fixed in #1083242
  if (isset($args[0])) {
    $args[0] = _services_access_value($args[0], 'node');
  }

  // Make sure we have an object or this all fails, some servers can
  // mess up the types.
  if (is_array($args[0])) {
    $args[0] = (object) $args[0];
  }
  elseif (!is_array($args[0]) && !is_object($args[0])) {  //This is to determine if it is just a string happens on node/%NID
    $args[0] = (object)array('nid' => $args[0]);
  }

  if ($op != 'create' && !empty($args)) {
    $node = node_load($args[0]->nid);
  }
  elseif ($op == 'create') {
    return node_access($op, 'greeting');
  }

  if (!isset($node->nid) || !$node->nid || $node->type != 'greeting') {
    return services_error(t('Greeting @nid could not be found', array('@nid' => $args[0]->nid)), 404);
  }

  return node_access($op, $node);
}


/**
 * Publish requested node.
 *
 * @param $nid
 *
 * @return array
 *
 * @throws Exception
 */
function _greeting_resource_publish($nid) {
  $node = node_load($nid);
  $node->status = 1;
  node_save($node);

  return array(
    'nid' => $nid,
    'status' => ($node->status == 1) ? 'Published' : 'Unpublished',
  );
}

/**
 * Unpublish requested node.
 *
 * @param $nid
 *
 * @return array
 *
 * @throws Exception
 */
function _greeting_resource_unpublish($nid) {
  $node = node_load($nid);
  $node->status = 0;
  node_save($node);

  return array(
    'nid' => $nid,
    'status' => ($node->status == 1) ? 'Published' : 'Unpublished',
  );
}
