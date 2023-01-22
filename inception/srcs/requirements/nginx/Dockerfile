# pull the debian:buster image
FROM debian:buster

RUN apt-get update -y
RUN apt-get -y install nginx openssl
# this installs php and php7.3-fpm
RUN apt-get -y install php php7.3-fpm

# required; if inexistant, openssl call raises an error
RUN mkdir /etc/nginx/ssl/
RUN openssl req -x509 -nodes -days 365 \
        -newkey rsa:2048 \
        -keyout /etc/nginx/ssl/tgarriss.key \
        -out /etc/nginx/ssl/tgarriss.csr \
        -subj "/C=CA/ST=QC/L=Thomas/O=42Quebec/OU=tgarriss/CN=tgarriss"

# replace this with your actual conf path
COPY nginx.conf /etc/nginx/conf.d/

# exposes the 443 port (the HTTPS port)
EXPOSE 443

CMD ["/usr/sbin/nginx", "-g", "daemon off;"]
