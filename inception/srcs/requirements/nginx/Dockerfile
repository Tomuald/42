FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get install -y nginx openssl

RUN mkdir /etc/nginx/ssl
RUN openssl req -newkey rsa:4096 -x509 -sha256 -days 365 -nodes \
       -out /etc/nginx/ssl/tgarriss.crt \
       -keyout /etc/nginx/ssl/tgarriss.key \
       -subj "/C=CA/ST=Quebec/L=Quebec/O=42 Quebec/OU=tgarriss/CN=tgarriss/"

COPY ./conf/nginx.conf /etc/nginx/conf.d

RUN mkdir -p /run/nginx

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
