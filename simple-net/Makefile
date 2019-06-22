.PHONY: all run
all: server client

server: server.c
	gcc -o server server.c

client: client.c
	gcc -o client client.c

run:
	@./server &
	@sleep 1
	@./client `netstat -l | grep -e "^tcp" | grep -oP "(?<= 0.0.0.0:)[0-9]*"`
