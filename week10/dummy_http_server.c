#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include "dummy_http.h"

int main( int argc, char *argv[] ) 
{
	int sockfd, newsockfd, clilen, num_bytes;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serv_addr, cli_addr;

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		fprintf(stderr, "ERROR: Failed to open socket\n");
		return 1;
	}

	/* Initialize socket structure (sockarrd_in) */
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(HTTP_PORT);

	/* Bind the host address */
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "ERROR: bind() failed\n");
		return 2;
	}

	/* Start listening for the clients (thread blocks) */
	listen(sockfd, 5);
	clilen = sizeof(cli_addr);

	/* Accept connection from a client */
	newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
	if (newsockfd < 0) {
		fprintf(stderr, "ERROR: accept() failed\n");
		return 3;
	}

	/* Clear buffer and start communicating */
	memset(buffer, 0, BUFFER_SIZE);
	num_bytes = read(newsockfd, buffer, BUFFER_SIZE-1);
	if (num_bytes < 0) {
		fprintf(stderr, "ERROR: read() failed\n");
		return 4;
	}
	printf("Recieved: %s\n", buffer);

	/* Write a response to the client */
	printf("Sending: %s\n", DUMMY_RESPONSE);
	num_bytes = write(newsockfd, DUMMY_RESPONSE, strlen(DUMMY_RESPONSE));
	if (num_bytes < 0) {
		fprintf(stderr, "ERROR: write() failed\n");
		return 5;
	}

	return 0;
}