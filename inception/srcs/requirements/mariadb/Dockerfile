FROM debian:buster

RUN apt-get -y update
RUN apt-get -y install mariadb-server

RUN mkdir -p /var/run/mysqld \
  && chown -R mysql:mysql /var/run/mysqld \
  && chmod 777 /var/run/mysqld

COPY ./tools/db_install.sh /usr/local/bin/

RUN chmod +x /usr/local/bin/db_install.sh

ENTRYPOINT ["/usr/local/bin/db_install.sh"]
EXPOSE 3306

CMD ["mysqld", "--bind-address=0.0.0.0"]
