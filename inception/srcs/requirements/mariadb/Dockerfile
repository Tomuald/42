FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install mariadb-server

WORKDIR /tmp/
RUN mkdir -p /run/mysql/
COPY conf/db-config.sql .

RUN service mysql start && mariadb -u root < ./db-config.sql
RUN 	sed 's/bind-address            = 127.0.0.1/bind-address            = 0.0.0.0/'\
		 -i /etc/mysql/mariadb.conf.d/50-server.cnf

EXPOSE 3306

CMD ["mysqld"]
