#!/bin/bash

if [-f ./wp-config.php]
then
    echo "wordpress already set up"
    echo "run fclean to remove data files"
else
    wget http://wordpress.org/latest.tar.gz
    tar -zxvf latest.tar.gz
    mv wordpress/* .
    rm -rf latest.tar.gz
    rm -rf wordpress

    sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
    sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
    sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
    sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
    mariadb -uroot -p$MYSQL_ROOT_PASSWORD $MYSQL_DATABASE < /tmp/datadump.sql
    cp wp-config-sample.php wp-config.php
fi

exec "$@"
