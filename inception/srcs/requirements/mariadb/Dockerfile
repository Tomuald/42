FROM alpine:3.16

RUN apk update && apk upgrade && apk add --update dumb-init mariadb mariadb-common mariadb-client mariadb-server-utils gettext bash

RUN rm -rf /etc/my.cnf
COPY conf/my.cnf /etc/my.cnf

RUN rm -rf /etc/mysql/my.cnf
COPY conf/my.cnf /etc/mysql/my.cnf

COPY tools/mariadb.sh ./mariadb.sh
# COPY conf/datadump.sql /tmp/datadump.sql

RUN chmod +x mariadb.sh

RUN mkdir -p /run/mysqld /var/lib/mysql /var/log/mysql

RUN chmod 777 /var/lib/mysql
RUN chmod 777 /run/mysqld
RUN chmod 777 /var/log/mysql
RUN chown -R mysql:mysql /var/log/mysql
RUN chown -R mysql:mysql /var/lib/mysql
RUN chown -R mysql:mysql /run/mysqld

EXPOSE 3306

ENTRYPOINT ["/usr/bin/dumb-init", "--"]

CMD ["bash", "-c", "./mariadb.sh && exec mysqld"]
