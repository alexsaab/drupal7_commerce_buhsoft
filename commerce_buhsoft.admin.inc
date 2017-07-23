<?php

/**
 * Возвращаем форму администрирования
 *
 * @param $form
 * @param $form_state
 *
 * @return mixed
 */
function commerce_buhsoft_settings_form($form, &$form_state) {

  $form = [];

  $form = _commerce_buhsoft_settings_get_server_status($form);

  $form['commerce_buhsoft_token'] = [
    '#type' => 'textfield',
    '#title' => t('Token for Buhsoft'),
    '#default_value' => variable_get('commerce_buhsoft_token', ''),
    '#description' => t('Set token for online checkout'),
    '#required' => TRUE,
  ];

  $form['commerce_buhsoft_diller'] = [
    '#type' => 'textfield',
    '#title' => t('INN of store'),
    '#default_value' => variable_get('commerce_buhsoft_diller', ''),
    '#required' => TRUE,
  ];

  $form['commerce_buhsoft_cms'] = [
    '#type' => 'textfield',
    '#title' => t('CMS Name'),
    '#default_value' => variable_get('commerce_buhsoft_cms', 'Drupal 7 / Commerce 1'),
    '#required' => TRUE,
  ];

  $form['commerce_buhsoft_default_phone'] = [
    '#type' => 'textfield',
    '#title' => t('Default customer phone'),
    '#default_value' => variable_get('commerce_buhsoft_default_phone', variable_get('uc_store_phone', '')),
    '#description' => t('Set default customer phone for online checkout'),
    '#required' => TRUE,
  ];

  $form['commerce_buhsoft_default_email'] = [
    '#type' => 'textfield',
    '#title' => t('Default customer email'),
    '#default_value' => variable_get('commerce_buhsoft_default_email', variable_get('uc_store_email', '')),
    '#description' => t('Set default customer Email for online checkout'),
    '#required' => TRUE,
  ];

  $form['commerce_buhsoft_print'] = [
    '#type' => 'select',
    '#title' => t('Print document'),
    '#options' => [
      0 => t('No'),
      1 => t('Yes'),
    ],
    '#default_value' => variable_get('commerce_buhsoft_print', 1),
  ];

  $form['commerce_buhsoft_order_status_before'] = [
    '#type' => 'select',
    '#title' => t('Order status before'),
    '#description' => t('Set this status when order can send to Buhsoft checkout'),
    '#options' => _commerce_buhsoft_get_formated_order_statuses(),
    '#default_value' => variable_get('commerce_buhsoft_order_status_before', 'checkout_complete'),
  ];

  $form['commerce_buhsoft_order_status_after'] = [
    '#type' => 'select',
    '#title' => t('Order status after'),
    '#description' => t('Set this status after Buhsoft checkout'),
    '#options' => _commerce_buhsoft_get_formated_order_statuses(),
    '#default_value' => variable_get('commerce_buhsoft_order_status_after', 'processing'),
  ];


  $form['commerce_buhsoft_name_cashier'] = [
    '#type' => 'textfield',
    '#title' => t('Name of cashier'),
    '#default_value' => variable_get('commerce_buhsoft_name_cashier', ''),
    '#required' => FALSE,
  ];

  $payment_methods = array_filter(commerce_payment_methods(), function ($v, $k) {
    return $v['active'] == TRUE;
  }, ARRAY_FILTER_USE_BOTH);

  $form['payment_methods'] = [
    '#type' => 'fieldset',
    '#title' => t('Select payment methods for online checkout'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => t('If you want receive online checkout when got 100% payment with select methods'),
  ];

  foreach ($payment_methods as $key => $payment_method) {
    $form['payment_methods']['commerce_buhsoft_method_' . $key] = [
      '#type' => 'checkbox',
      '#title' => $payment_method['title'],
      '#description' => $payment_method['description'],
      '#default_value' => variable_get('commerce_buhsoft_method_' . $key, FALSE),
      '#return_value' => TRUE,
    ];
  }

  $product_types = commerce_product_types();

  $form['vats'] = [
    '#type' => 'fieldset',
    '#title' => t('Set VAT% for product types'),
    '#collapsible' => FALSE,
    '#collapsed' => FALSE,
    '#description' => t('Set products types VAT, in store each products type has self VAT rate'),
  ];

  foreach ($product_types as $key => $product_type) {
    $form['vats']['commerce_buhsoft_vat_' . $key] = [
      '#type' => 'select',
      '#title' => $product_type['name'],
      '#description' => $product_type['description'],
      '#options' => [
        1 => t('18% VAT'),
        2 => t('10% VAT'),
        3 => t('0% VAT'),
        4 => t(' Without VAT'),
      ],
      '#default_value' => variable_get('commerce_buhsoft_vat_' . $key, 1),
      '#required' => TRUE,
    ];
  }

  $form['vats']['commerce_buhsoft_vat_delivery'] = [
    '#type' => 'select',
    '#title' => t('Select VAT rate for delivery'),
    '#options' => [
      1 => t('18% VAT'),
      2 => t('10% VAT'),
      3 => t('0% VAT'),
      4 => t(' Without VAT'),
    ],
    '#default_value' => variable_get('commerce_buhsoft_vat_delivery', 1),
  ];

  return system_settings_form($form);

}

