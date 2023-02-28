#!bin/bash

set -eo pipefail

if [ ! -f "/var/www/html/wp-config.php" ]; then
	wp core download --allow-root --path="/var/www/html"

	rm -f /var/www/html/wp-config.php8
	rm -f /var/www/html/wp-config.php
	rm -f /etc/php8/php-fpm.d/www.conf

	cp ./www.conf /etc/php8/php-fpm.d/www.conf

	for i in {0..42}; do
		if mariadb -hmariadb -u$MYSQL_USER -p$MYSQL_PASSWORD --database=$MYSQL_DATABASE <<< 'SELECT 1;'&>/dev/null; then
			break
		fi
		sleep 5
	done

	wp config create --allow-root --dbname=$MYSQL_DATABASE --dbuser=$MYSQL_USER --dbpass=$MYSQL_PASSWORD \
		--dbhost=mariadb --dbcharset="utf8" --dbcollate="utf8_general_ci" --path="/var/www/html"

	wp core install --allow-root --title="Inception" --admin_name="superuser" --admin_password="superuser" \
		--admin_email="email@email.com" --skip-email --url="tgarriss.42.fr" --path="/var/www/html"
	wp user create --allow-root $MYSQL_USER "other@email.com" --role=author --user_pass=$MYSQL_PASSWORD --path="/var/www/html"
	echo "Wordpress has been set up"
fi
