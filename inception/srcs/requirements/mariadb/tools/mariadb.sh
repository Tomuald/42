if [ -f ".a" ]; then
	echo "DB is already set up"
else
	echo "Setting up the DB"
	mysql_install_db --user=mysql --basedir=/usr --datadir=/var/lib/mysql

	mysqld --user=mysql --datadir=/var/lib/mysql &
	sleep 5

	mysql -e "CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};"
	echo "DB is created"

	mysql -e "CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'localhost' IDENTIFIED BY '${MYSQL_PASSWORD}';"
	echo "User ${MYSQL_USER} created"

	mysql -e "GRANT ALL PRIVILEGES ON \`${MYSQL_DATABASE}\`.* TO \`${MYSQL_USER}\`@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';"
	echo "Privileges have been granted"

	mysql -e "ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';"
	echo "Root password is now set"

	mysql -u root -p${MYSQL_ROOT_PASSWORD} -e "FLUSH PRIVILEGES;"
	echo "Privileges have been flushed"

	touch ".a"
	pkill mysqld

fi
