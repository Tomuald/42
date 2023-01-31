CREATE DATABASE IF NOT EXISTS wordpress;
CREATE USER 'tgarriss'@'localhost';
SET PASSWORD FOR 'tgarriss'@'localhost' = PASSWORD('password');
GRANT ALL PRIVILEGES ON wordpress.* TO 'tgarriss'@'localhost' IDENTIFIED BY 'password';
GRANT ALL ON wordpress.* to 'tgarriss'@'%' IDENTIFIED BY 'password';

FLUSH PRIVILEGES;

CREATE USER 'superuser'@'localhost' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON *.* TO 'superuser'@'localhost' WITH GRANT OPTION;
FLUSH PRIVILEGES;
CREATE USER 'superuser'@'%' IDENTIFIED BY 'password';
GRANT ALL PRIVILEGES ON *.* TO 'superuser'@'%' WITH GRANT OPTION;

FLUSH PRIVILEGES;

ALTER USER 'root'@'localhost' IDENTIFIED BY 'newpass';
flush privileges;
