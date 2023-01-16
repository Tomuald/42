FROM debian:buster

RUN apt-get -y update && apt-get -y install php-fpm php-mysql
RUN apt-get -y install curl
WORKDIR /tmp/
RUN curl -LO https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
RUN cp /tmp/wordpress/wp-config-sample.php /tmp/wordpress/wp-config.php

COPY ./conf/www.conf /etc/php/7.3/pool.d/

EXPOSE 9000
