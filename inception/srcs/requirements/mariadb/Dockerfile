FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install mariadb-server mariadb-client



EXPOSE 3306

CMD ["mysqld", "--bind-address=0.0.0.0"]
