#!/bin/bash
mysql_secure_installation << _EOF_

Y
password
password
Y
n
Y
Y
_EOF_

echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY 'password'; FLUSH PRIVILEGES;" | mysql -uroot

#Create database and user in the database for wordpress
echo "CREATE DATABASE IF NOT EXISTS wordpress; GRANT ALL ON $MYSQL_DATABASE.* TO 'tgarriss'@'%' IDENTIFIED BY 'password'; FLUSH PRIVILEGES;" | mysql -u root
mariadb -u root < db-config.sql
