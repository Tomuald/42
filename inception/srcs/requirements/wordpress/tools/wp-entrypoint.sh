#!/bin/bash

wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
chmod +x wp-cli.phar

./wp-cli.phar core download

./wp-cli.phar config create \
    --dbname=$WP_DB_NAME    \
    --dbuser=$WP_DB_ADM_USER    \
    --dbpass=$WP_DB_ADM_PASSWORD \
    --dbhost=$WP_DB_HOST    \
    --dbprefix=$WP_TABLE_PREFIX \
    --dbcharset=$WP_DB_CHARSET  \
    --dbcolalte=$WP_DB_COLLATE

./wp-cli.phar db create

./wp-cli.phar core install  \
    --url=$WP_SITE_URL  \
    --title=$WP_SITE_TITLE  \
    --admin_user=$WP_DB_ADM_USER    \
    --admin_password=$WP_DB_ADM_PASSWORD    \
    --admin_email=$WP_ADMIN_EMAIL   \
    --skip-email

php-fpm7.3
