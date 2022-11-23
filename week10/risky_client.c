#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>

/*       _                             
      __| | __ _ _ __   __ _  ___ _ __ 
     / _` |/ _` | '_ \ / _` |/ _ \ '__|
    | (_| | (_| | | | | (_| |  __/ |   
     \__,_|\__,_|_| |_|\__, |\___|_|   
                       |___/            

    this client is too simple - does not check the return codes */

#define MAX_DATA_SIZE 25 /* max number of bytes we can get at once */

int main(int argc, char *argv[]) {
    char buf[MAX_DATA_SIZE] = {0};
    struct sockaddr_in srv_addr = {0};
	
    srv_addr.sin_family = AF_INET;      /* host byte order */
    srv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    srv_addr.sin_port = htons(11111);    /* short, network byte order */

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr));
    send(sockfd, "Hello\n", 7, 0);
    recv(sockfd, buf, MAX_DATA_SIZE-1, 0);

    printf("Received: %s", buf);
    close(sockfd);
    return 0;
}
