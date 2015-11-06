/*
 * Author:          Deep Aggarwal
 * Date Created:    14/10/2015
 * Description:     An example client talking to the server using PUT, GET, DELETE commands
 */

#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

//Port number, should be >=1024
const char *service =  "5007";

int main(int argc, char **argv)
{
    int clientSocketFd = socket(AF_INET, SOCK_STREAM, 0);

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int resultOfAddressInfo = getaddrinfo("localhost", service, &hints, &res);
    if(resultOfAddressInfo != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(resultOfAddressInfo));
        exit(1);
    }

    connect(clientSocketFd, res->ai_addr, res->ai_addrlen);

    int a = 3;
    while(a > 0)
    {
        char *buffer = "PUT CS 101";
        printf("SENDING: %s\n", buffer);
        send(clientSocketFd, buffer, strlen(buffer), 0);

        char responseFromServer[100];
        int len = recv(clientSocketFd, responseFromServer, sizeof(responseFromServer) - 1, 0);
        responseFromServer[len] = '\0';
        printf("%s\n", responseFromServer);
        a--;
    }

    return 0;
}
