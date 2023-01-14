all:
	docker compose -f ./srcs/docker-compose.yml up -d --build

down:
	docker compose -f ./scrs/docker-compose.yml down

clean:
	docker stop $$(docker ps -qa);\
	docker rm $$(docker ps -qa);\
	docker image rm $$(docker images -qa);\

.PHONY: all down clean
