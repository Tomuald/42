FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mariadb-server

RUN mkdir -p /var/run/mysqld
RUN chown -R mysql:mysql /var/run/mysqld
RUN chmod 777 /var/run/mysqld

EXPOSE 3306

CMD ["mysqld", "--bind-address=0.0.0.0"]
