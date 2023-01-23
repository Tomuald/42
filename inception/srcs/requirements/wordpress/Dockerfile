FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install curl

WORKDIR /tmp
RUN curl -LO https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
COPY ./conf/wp-config.php /tmp/wordpress/wp-config.php
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
RUN cp -a /tmp/wordpress/. /var/www/html
RUN chown -R www-data:www-data /var/www/html

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.3", "-F"]
