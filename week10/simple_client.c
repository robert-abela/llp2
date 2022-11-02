#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define PORT 11111    /* the port client will be connecting to */
#define MSG "Hi i am a client\n"
#define MAX_DATA_SIZE 25 /* max number of bytes we can get at once */

int main(int argc, char *argv[]) {
    int sockfd, numbytes;  
    char buf[MAX_DATA_SIZE] = {0};
    struct sockaddr_in srv_addr = {0};

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("socket() failed\n");
        return -1;
    }

    srv_addr.sin_family = AF_INET;      /* host byte order */
    //srv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    srv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    srv_addr.sin_port = htons(PORT);    /* short, network byte order */

    if (connect(sockfd, (struct sockaddr *)&srv_addr, sizeof(srv_addr)) == -1) {
        printf("connect() failed\n");
        return -2;
    }

    if (send(sockfd, MSG, strlen(MSG), 0) == -1){
        printf("send() failed\n");
        return -3;
    }
    
    printf("Data sent successfully \n");

    /* normally you would put recv() in a loop */    
    numbytes = recv(sockfd, buf, MAX_DATA_SIZE, 0);
    if (numbytes == -1) {
        printf("recv() failed\n");
        return -4;
    }

    printf("Received: %s", buf);
    close(sockfd);
    return 0;
}
