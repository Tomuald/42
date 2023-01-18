FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install mariadb-server

RUN mysql_secure_installation < "Y\npassword\npassword\nY\nn\nY\nY\n"
RUN mariadb -u root < "db-config.sql"

EXPOSE 3306

ENTRYPOINT ["mysqld", "--bind-address=0.0.0.0"]
