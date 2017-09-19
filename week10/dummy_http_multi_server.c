#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#include "dummy_http.h"

void* handle_client(void *socket)
{
	char buffer[BUFFER_SIZE] = {0};
	int newsockfd = (int)socket;
	pthread_t thread_id = pthread_self();

	printf("----------\nThread %lu using socket %x\n", (unsigned long)thread_id, newsockfd);

	/* Start communicating */
	int num_bytes = recv(newsockfd, buffer, BUFFER_SIZE-1, 0);
	if (num_bytes < 0) {
		fprintf(stderr, "Thread %lu ERROR: recv() failed\n", (unsigned long)thread_id);
		return NULL;
	}
	printf("Thread %lu recieved request\n", (unsigned long)thread_id);

	/* Write a response to the client */
	printf("Thread %lu sending response\n", (unsigned long)thread_id);
	num_bytes = send(newsockfd, DUMMY_RESPONSE, strlen(DUMMY_RESPONSE), 0);
	if (num_bytes < 0) {
		fprintf(stderr, "Thread %lu ERROR: send() failed\n", (unsigned long)thread_id);
		return NULL;
	}

	close(newsockfd);
	return NULL;
}

int main( int argc, char *argv[] ) 
{
	struct sockaddr_in serv_addr, cli_addr;
	socklen_t clilen = sizeof(cli_addr);
	int sockfd, thread_res;
	pthread_t mythread;

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		fprintf(stderr, "ERROR: Failed to open socket\n");
		return 1;
	}

	/* Initialize socket structure (sockarrd_in) */
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //or INADDR_ANY
	serv_addr.sin_port = htons(HTTP_PORT);

	/* Bind the host address */
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "ERROR: bind() failed\n");
		return 2;
	}

	/* Start listening for the clients (thread blocks) */
	if (listen(sockfd, MAX_CONNECTIONS) != 0) {
		fprintf(stderr, "ERROR: listen() failed\n");
		return 3;
	}

	for (;;)
	{
		/* Accept connection from a client */
		int newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
		if (newsockfd < 0) {
			fprintf(stderr, "ERROR: accept() failed\n");
			return 4;
		}

		thread_res = pthread_create(&mythread, NULL, handle_client, (void*)newsockfd);
		if (thread_res != 0)
		{
			fprintf(stderr, "ERROR: pthread_create() failed\n");
			return 5;
		}
	}

	return 0;
}
