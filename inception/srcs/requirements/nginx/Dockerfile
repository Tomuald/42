FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install nginx
RUN apt-get -y install php-fpm
RUN apt-get -y install openssl

RUN mkdir /var/www/tgarriss.42.fr/
RUN groupmod -g 500 www-data && usermod -u 500 www-data && usermod -g 500 www-data
RUN chown -R www-data:www-data /var/www/tgarriss.42.fr/
RUN chmod g+s /var/www/tgarriss.42.fr/

RUN mkdir /etc/nginx/ssl/
RUN chown 777 /etc/nginx/ssl/
RUN usermod -aG www-data nginx
RUN openssl req -x509 -nodes -days 365 \
        -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/tgarriss.key \
        -out /etc/nginx/ssl/tgarriss.csr \
        -subj "/C=CA/ST=QC/L=Thomas/O=42Quebec/OU=tgarriss/CN=tgarriss"

COPY ./conf/tgarriss.42.fr /etc/nginx/sites-available/
RUN cp /etc/nginx/sites-available/tgarriss.42.fr /etc/nginx/sites-enabled/
EXPOSE 443

ENTRYPOINT ["/usr/sbin/nginx", "-g", "daemon off;"]
