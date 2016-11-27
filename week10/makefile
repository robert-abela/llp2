all: clean client server

client:
	gcc -Wall -o client dummy_http_client.c

server:
	gcc -Wall -o server dummy_http_server.c

clean:
	-rm client server