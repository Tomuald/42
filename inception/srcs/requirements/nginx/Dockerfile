FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install nginx
RUN apt-get -y install php-fpm

RUN mkdir /var/www/tgarriss.42.fr/
RUN chown -R $USER:$USER /var/www/tgarriss.42.fr/

RUN mkdir /etc/nginx/ssl/
RUN openssl req -x509 -nodes -days 365 \
        -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/tgarriss.key \
        -out /etc/nginx/ssl/tgarriss.csr \
        -subj "/C=CA/ST=QC/L=Thomas/O=42Quebec/OU=tgarriss/CN=tgarriss"

COPY ./conf/tgarriss.42.fr /etc/nginx/sites-available/
RUN ln -s /etc/nginx/sites-available/tgarriss.42.fr/ /etc/nginx/sites-enabled/
EXPOSE 443

ENTRYPOINT ["/usr/bin/nginx", "-g", "daemon off;"]
