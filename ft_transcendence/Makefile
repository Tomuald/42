all:
# mkdir the directories you need
	docker compose -f ./docker-compose.yml up -d --build

down:
	docker compose -f ./docker-compose.yml down

clean:
	docker stop $$(docker ps -qa) 2>/dev/null
	docker rm $$(docker ps -qa) 2>/dev/null
	docker rmi -f $$(docker images -qa) 2>/dev/null
	docker volume rm $$(docker volume ls -q) 2>/dev/null
	docker network rm $$(docker network ls -q) 2>/dev/null

fclean: clean

re: fclean all

.PHONY: all down clean re
