**Модуль для Drupal 7 и Commerce для работы с сервисом для онлайн кассы Бухсофт (Buhsoft)**

1. Для установки модуля просто скопируйте его в директорию "sites/all/modules/commerce_buhsoft". Эту директорию предварительно конечно необходимо создать. Если у вас "мультисайтовый" Drupal и вы хотите ставить модуль на определенный сайт скопируйте его в папку "sites/url вашего сайта.ru/modules/commerce_buhsoft". 
2. Включите его через "admin/modules" или с помощью утилиты drush команда "drush en commerce_buhsoft". У вас в базе данных создадутся необходимые поля и сущности в заказах commerce и профилях пользователя (в частности в профайле доставки у вас создасться поле phone - телефон, для работы с сервисом Бухсофт это обязательный параметр)
3. Далее настраиваем модуль через меню "admin/commerce/config/advanced-settings/commerce_buhsoft" никаких трудностей в настройке модуля нет. Только если у вас на сайте продаются несколько товаров с разными ставками НДС вам для каждого такого товара необходимо создать отдельный тип. Также необходимо выбрать тип оплаты через, который(ые) в автоматическом режиме будут автоматически пробиваться онлайн чеки через сервис Бухсофта. 



