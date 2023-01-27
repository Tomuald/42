FROM debian:buster

RUN apt-get -y update && apt-get -y upgrade
RUN apt-get -y install mariadb-server mariadb-client

WORKDIR /tmp

COPY ./tools/entry.sh .
COPY ./conf/50-server.conf /etc/mysql/mariadb.conf.d/50-server.cnf

RUN mkdir -p /run/mysqld && chown mysql:mysql /run/mysqld

EXPOSE 3306

ENTRYPOINT ["./entry.sh"]

CMD ["mysqld"]
