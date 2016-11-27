#include <stdio.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE	1024
#define HTTP_PORT	80

int main(int argc, char *argv[]) 
{
	int sockfd, num_bytes;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[BUFFER_SIZE] = {0};

	/* Create a socket */
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0) {
		fprintf(stderr, "ERROR: Failed to open socket\n");
		return 1;
	}

	/* get the server address */
	server = gethostbyname("mcast.edu.mt");
	if (server == NULL) {
		fprintf(stderr, "ERROR: Host not found\n");
		return 2;
	}

	/* Prepare the sockarrd_in structure */
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	strncpy((char *)&serv_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
	serv_addr.sin_port = htons(HTTP_PORT);

	/* Connect to the server */
	if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
		fprintf(stderr, "ERROR: Connection failed\n");
		return 3;
	}

	/* Prepare request */
	strcpy(buffer, "GET http://www.mcast.edu.mt HTTP/1.0\r\n\r\n");
	printf("Sending: %s\n",buffer);

	/* Send message to the server */
	num_bytes = write(sockfd, buffer, strlen(buffer));
	if (num_bytes < 0) {
		fprintf(stderr, "ERROR: Failed writing to socket\n");
		return 4;
	}

	/* Now read server response */
	memset(buffer, 0, BUFFER_SIZE);
	num_bytes = read(sockfd, buffer, BUFFER_SIZE-1);
	if (num_bytes < 0) {
		fprintf(stderr, "ERROR: Failed reading from socket\n");
		return 5;
	}

	printf("Recieved: %s\n",buffer);
	return 0;
}