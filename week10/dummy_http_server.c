#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

#include "dummy_http.h"

int main(int argc, char *argv[]) {
	int sockfd, newsockfd, num_bytes;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serv_addr = {0}, cli_addr;
	socklen_t clilen = sizeof(cli_addr);

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		fprintf(stderr, "ERROR: Failed to open socket\n");
		return -1;
	}

	/* allow to reuse the socket as soon as it stops being active */
	int so_reuse_enabled = 1;
	if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &so_reuse_enabled, sizeof(int)) < 0) {
		fprintf(stderr, "setsockopt(SO_REUSEADDR) failed");
		return -2;
	}

	/* Initialize socket structure (sockarrd_in) */
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK); //or INADDR_ANY
	serv_addr.sin_port = htons(HTTP_PORT);

	/* Bind the host address */
	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "ERROR: bind() failed\n");
		fprintf(stderr, "Error code: %s\n", strerror(errno));
		return -3;
	}

	/* Start listening for the clients (thread blocks) */
	if (listen(sockfd, MAX_CONNECTIONS) < 0) {
		fprintf(stderr, "ERROR: listen() failed\n");
		fprintf(stderr, "Error code: %s\n", strerror(errno));
		return -4;
	}

	//for (;;)
	//{
		/* Accept connection from a client */
		newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
		if (newsockfd < 0) {
			fprintf(stderr, "ERROR: accept() failed\n");
			return -5;
		}

		/* Clear buffer and start communicating */
		memset(buffer, 0, BUFFER_SIZE);
		num_bytes = recv(newsockfd, buffer, BUFFER_SIZE-1, 0);
		if (num_bytes < 0) {
			fprintf(stderr, "ERROR: recv() failed\n");
			return -6;
		}
		printf("Recieved: %s\n", buffer);

		/* Write a response to the client */
		printf("Sending: %s\n", DUMMY_RESPONSE);
		num_bytes = send(newsockfd, DUMMY_RESPONSE, strlen(DUMMY_RESPONSE), 0);
		if (num_bytes < 0) {
			fprintf(stderr, "ERROR: send() failed\n");
			return -7;
		}

		close(newsockfd);
	//}

	close(sockfd);
	return 0;
}
