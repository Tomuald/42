all:
	mkdir -p /home/tgarriss/data/mysql
	mkdir -p /home/tgarriss/data/wordpress
	docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker compose -f ./srcs/docker-compose.yml down

clean:
	docker stop $$(docker ps -qa)
	docker rm $$(docker ps -qa)
	docker rmi -f $$(docker images -qa)
	docker volume rm $$(docker volume ls -q)
	docker network rm $$(docker network ls -q)

fclean: clean
	rm -Rf /home/tgarriss/data/mysql
	rm -Rf /home/tgarriss/data/wordpress

re: fclean all

.PHONY: all down clean re
