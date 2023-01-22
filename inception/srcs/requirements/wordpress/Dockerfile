FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install php-fpm php-mysql
RUN apt-get -y install curl

RUN mkdir -p /var/www/tgarriss.42.fr/
RUN mkdir -p /run/php

WORKDIR /tmp/

RUN curl -LO https://wordpress.org/latest.tar.gz
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN tar -xzvf latest.tar.gz

COPY ./conf/wp-config.php .
COPY /conf/index.php .

RUN chown -R tgarriss:tgarriss
RUN chmod -R tgarriss:tgarriss .
RUN chmod -R 777 .
RUN sed 's/listen = \/run\/php\/php7.3-fpm.sock/listen = 0.0.0.0:9000/' -i /etc/php/7.3/fpm/pool.d/www.conf

RUN mkdir -p /var/www/tgarriss.42.fr/wordpress/
RUN chmod 777 wp-cli.phar && mv wp-cli.phar /usr/local/bin/wp-cli
RUN cp -a /tmp/wordpress/. /var/www/tgarriss.42.fr/wordpress/

RUN chown -R tgarriss:tgarriss /var/www/tgarriss.42.fr/
RUN chmod -R tgarriss:tgarriss /var/www/tgarriss.42.fr/

EXPOSE 9000

CMD wp-cli core install --allow-root --title="Wordpress" --admin_name="nimda" --admin_password="password" --admin_email="tgarriss@student.42quebec.com" --path="/var/www/tgarriss.42.fr" --url="https://localhost/" && php-fpm7.3 -F -R
