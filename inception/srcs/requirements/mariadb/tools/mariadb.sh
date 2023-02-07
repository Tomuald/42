#!/bin/sh

mysql_install_db

/etc/init.d/mysql start

if [-d "/var/lib/mysql/$MYSQL_DATABASE"]
then
    echo "database already exists."
else
mysql_secure_installation << _EOF_

Y
root
root
Y
n
Y
Y
_EOF_

echo "GRANT ALL ON *.* TO 'root'@'%' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD'; FLUSH PRIVILEGES;" | mysql -uroot
echo "CREATE DATABASE IF NOT EXISTS $MYSQL_DATABASE; GRANT ALL ON $MYSQL_DATABASE.* TO '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD'; FLUSH PRIVILEGES;" | mysql -u root

UPDATE mysql.user SET plugin = '' WHERE user = 'root' AND host = 'localhost';
FLUSH PRIVILEGES;

fi

/etc/init.d/mysql stop
# exec "$@" is necessary for proper signal handling; it makes the
# final running application become the container’s PID 1. This allows
# the application to receive any Unix signals sent to the container.
# it replaces the parent process with the child process
exec "$@"
