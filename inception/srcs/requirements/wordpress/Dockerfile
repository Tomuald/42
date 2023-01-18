FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install php-curl php-gd php-intl php-mbstring php-soap php-xml php-xmlrpc php-zip
RUN apt-get -y install php-fpm php-mysql
RUN apt-get -y install curl

WORKDIR /tmp/
RUN curl -LO https://wordpress.org/latest.tar.gz
RUN tar -xzvf latest.tar.gz
COPY ./conf/wp-config.php /tmp/wordpress/
RUN cp -a /tmp/wordpress/. /var/www/tgarriss.42.fr/
RUN chown -R www-data:www-data /var/www/tgarriss.42.fr/

EXPOSE 9000

CMD ["/usr/sbin/php-fpm7.3", "-F"]
