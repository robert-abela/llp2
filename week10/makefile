all: clean client server multi_server

client:
	gcc -Wall -o client dummy_http_client.c

server:
	gcc -Wall -o server dummy_http_server.c

multi_server:
	gcc -Wall -o multi_server dummy_http_multi_server.c -lpthread

clean:
	-rm client server multi_server