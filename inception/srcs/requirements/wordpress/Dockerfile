FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install php-fpm php-mysql
RUN apt-get -y install wget

RUN mkdir -p /var/www/html
WORKDIR /var/www/html
#WORKDIR /tmp
#RUN curl -LO https://wordpress.org/latest.tar.gz
#RUN tar -xzvf latest.tar.gz
COPY ./conf/wp-config.php /tmp/wordpress/wp-config.php
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/
#RUN mv /tmp/wordpress/ /var/www/html
RUN chown -R www-data:www-data /var/www/html

COPY ./tools/wp-entrypoint.sh /usr/local/bin/

EXPOSE 9000

USER www-data

ENTRYPOINT ["wp-entrypoint.sh"]
