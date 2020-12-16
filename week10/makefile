all: clean http_client simple_client server multi_server

http_client:
	gcc -Wall -o http_client dummy_http_client.c

simple_client:
	gcc -Wall -o simple_client simple_client.c

server:
	gcc -Wall -o server dummy_http_server.c

multi_server:
	gcc -Wall -o multi_server dummy_http_multi_server.c -lpthread

clean:
	-rm http_client server multi_server simple_client