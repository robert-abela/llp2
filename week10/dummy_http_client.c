#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <assert.h>
#include "dummy_http.h"

int main(int argc, char *argv[]) {
	int sockfd, num_bytes;
	struct sockaddr_in serv_addr;
	struct hostent *url;
	char buffer[BUFFER_SIZE] = {0};

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		fprintf(stderr, "ERROR: Failed to open socket\n");
		return 1;
	}

	/* get the url address */
	url = gethostbyname("mcast.edu.mt"); /* does not support IP6 */
	if (url == NULL) {
		fprintf(stderr, "ERROR: Host not found\n");
		return 2;
	}

	/* Initialize socket structure (sockarrd_in) */
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	memcpy(&serv_addr.sin_addr, url->h_addr, url->h_length);
	serv_addr.sin_port = htons(HTTP_PORT);

	/* Connect to the server */
	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "ERROR: Connection failed\n");
		return 3;
	}

	/* Prepare request */
	strcpy(buffer, DUMMY_REQUEST);
	printf("Sending: %s\n",buffer);

	/* Send message to the server */
	num_bytes = send(sockfd, buffer, strlen(buffer), 0);
	if (num_bytes < 0) {
		fprintf(stderr, "ERROR: Failed writing to socket\n");
		return 4;
	}

	/* make sure that all the request was sent */
	assert(num_bytes == strlen(DUMMY_REQUEST));

	/* Now read server response (may require multiple reads)*/
	do {
		memset(buffer, 0, BUFFER_SIZE);
		num_bytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
		printf("%s",buffer);
	} while (num_bytes > 0);
	
	if (num_bytes < 0) {
		fprintf(stderr, "ERROR: Failed reading from socket\n");
		return 5;
	}
	
	close(sockfd);
	return 0;
}
