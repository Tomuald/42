FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install php-fpm php-mysql mariadb-client

RUN mkdir -p /var/www /run/php

WORKDIR /var/www/

COPY /tools/* .
COPY ./conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf

RUN chmod +x wp-cli.phar && mv wp-cli.phar /usr/bin/wp

EXPOSE 9000

ENTRYPOINT ["./entry.sh"]

CMD ["php-fpm7.3", "-F", "-R"]
