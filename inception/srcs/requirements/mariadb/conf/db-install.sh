mysql_secure_installation << _EOF_

Y
password
password
Y
n
Y
Y
_EOF_

mariadb -u root < db-config.sql
