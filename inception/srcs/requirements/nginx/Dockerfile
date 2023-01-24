FROM debian:buster

RUN apt-get update -y && apt-get -y upgrade
RUN apt-get -y install nginx openssl
RUN apt-get -y install php php7.3-fpm

RUN mkdir /etc/nginx/ssl

RUN openssl req -x509 -nodes -days 365 \
        -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/tgarriss.key \
        -out /etc/nginx/ssl/tgarriss.csr \
        -subj "/C=CA/ST=QC/L=Thomas/O=42Quebec/OU=tgarriss/CN=tgarriss"

COPY ./conf/nginx.conf .
RUN rm -rf /etc/nginx/sites-enabled/* && \
	mv nginx.conf /etc/nginx/sites-available/nginx.conf && \
	ln -fs /etc/nginx/sites-available/nginx.conf /etc/nginx/sites-enabled/
# COPY ./index.html /var/www/html/

EXPOSE 443

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]
