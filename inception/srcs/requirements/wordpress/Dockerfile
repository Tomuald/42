FROM debian:buster

RUN apt-get -y update && apt-get -y install php-fpm php-mysql

RUN adduser -S nginx && addgroup -S nginx
COPY conf/www.conf /etc/php/7.3/fpm/pool.d

RUN mkdir /tmp/
COPY conf/index.html /tmp/index.html
COPY tools/configure.sh /tmp/configure.sh

RUN wget https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN cp wp-cli.phar /usr/bin/wp

WORKDIR /var/www/html/wordpress

ENTRYPOINT ["sh", "/tmp/configure.sh"]
