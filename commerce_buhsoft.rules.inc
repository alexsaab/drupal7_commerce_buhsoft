<?php

/**
 * @file
 * This file contains the Rules hooks and functions necessary to make the order
 * related entity, conditions, events, and actions work.
 */

/**
 * Implements hook_rules_data_info().
 */
function commerce_buhsoft_rules_data_info() {
    $types['commerce_payment'] = array(
        'label' => t('Commerce order object'),
        'wrap' => TRUE,
        'group' => t('Commerce Payment'),
    );

    return $types;
}

/**
 * Implements hook_rules_event_info().
 */
function commerce_buhsoft_rules_event_info() {
    $events['commerce_buhsoft_online_checkout'] = array(
        'label' => t('Buhsoft online checkout'),
        'group' => t('Commerce Payment'),
        'variables' => array(
            'commerce_order' => array(
                'type' => 'commerce_order',
                'label' => t('Commerce order'),
            ),
        ),
    );

    return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function commerce_buhsoft_rules_action_info() {

    $order_arg = array(
        'type' => 'commerce_order',
        'label' => t('Commerce order'),
    );

    $actions['commerce_buhsoft_online_checkout'] = array(
        'label' => t('Buhsoft online checkout'),
        'group' => t('Commerce Payment'),
        'base' => 'commerce_buhsoft_online_checkout',
        'parameter' => array(
            'commerce_order' => $order_arg
        ),
    );

    return $actions;
}