/*
 * Author:          Deep Aggarwal
 * Date Created:    10/10/2015
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
    /**
     * @brief Creates an endpoint for communication and returns a descriptor.
     *
     *  int socket(int domain, int type, int protocol);
     *
     * @param AF_INET This specifies a communication domain; this selects the protocol family
     *  which will be used for communication. AF_INET = IPv4
     * @param SOCK_STREAM Specifies the communication semantics. SOCK_STREAM = TCP
     * @param 0 Specifies a particular protocol to be used with the socket
     *
     * @return On success, a file descriptor for the new socket is returned.
     *  On error, -1 is returned, and errno is set appropriately.
     */
    int serverSockFd = socket(AF_INET, SOCK_STREAM, 0);
    if(serverSockFd == -1)
    {
        perror("Couldn't create server socket");
        exit(1);
    }

    /**
     * @brief This function shall set the option specified by the option_name argument,
     *  at the protocol level specified by the level argument, to the value pointed to by
     *  the option_value argument for the socket associated with the file descriptor specified
     *  by the socket argument.
     *
     *  int setsockopt(int socket, int level, int option_name, const void *option_value, socklen_t option_len);
     *
     * @param socket The socket file descriptor whose options will be manipulated.
     * @param level The level argument specifies the protocol level at which the option resides.
     *  To set options at the socket level, specify the level argument as SOL_SOCKET. To set options at other levels,
     *  supply the appropriate level identifier for the protocol controlling the option.
     *  For example, to indicate that an option is interpreted by the TCP (Transport Control Protocol),
     *  set level to IPPROTO_TCP as defined in the <netinet/in.h> header.
     * @param option_name The option_name argument specifies a single option to set.
     *  The option_name argument and any specified options are passed uninterpreted to the appropriate
     *  protocol module for interpretations. The <sys/socket.h> header defines the socket-level options. The options are as follows:
     *  SO_DEBUG, SO_BROADCAST, SO_REUSEADDR, etc.
     * @param option_value The value to be set for the socket associated with the file descriptor.
     * @param option_len The length of option_value
     *
     * @return On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
     */
    int optVal = 1;
    int socketOptionsSuccess = setsockopt(serverSockFd, SOL_SOCKET, SO_REUSEPORT, &optVal, sizeof(optVal));
    if(socketOptionsSuccess == -1)
    {
        perror("Couldn't make the port reusable");
        exit(1);
    }

    /*
     * The hints argument points to an addrinfo structure that specifies criteria for
     * selecting the socket address structures returned in the list pointed to by res in the call to getaddrinfo().
     * If hints is not NULL it points to an addrinfo structure whose ai_family, ai_socktype, and
     * ai_protocol specify criteria that limit the set of socket addresses returned by getaddrinfo(), as follows:
     *  ai_family   : Desired address family for the returned addresses - AF_INET, AF_INET6 or AF_UNSPEC
     *  ai_socktype : SOCK_STREAM, SOCK_DGRAM etc.
     *  ai_protocol : IPPROTO_TCP=6, IPPROTO_UDP=17, etc. Specifies the protocol for the returned socket addresses.
     *                Specifying 0 in this field indicates that socket addresses with any protocol can be returned by getaddrinfo().
     *                When the ai_family member is AF_INET or AF_INET6 and the ai_socktype member is SOCK_STREAM, the possible value is TCP (IPPROTO_TCP).
     *  ai_flags    : Multiple flags are specified by bitwise OR-ing them together. AI_PASSIVE, AI_CANONNAME, AI_V4MAPPED, etc.
     */
    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    /**
     * @brief Given node and service, which identify an Internet host and a service,
     *  getaddrinfo() returns one or more addrinfo structures, each of which contains
     *  an Internet address that can be specified in a call to bind() or connect().
     *  NOTE: The getaddrinfo() function combines the functionality provided by the gethostbyname()
     *  and getservbyname() functions into a single interface, but unlike the latter functions,
     *  getaddrinfo() is reentrant and allows programs to eliminate IPv4-versus-IPv6 dependencies.
     *
     *  int getaddrinfo(const char *node, const char *service, const struct addrinfo *hints, struct addrinfo **res);
     *
     * @param node It specifies either a numerical network address (for IPv4, numbers-and-dots notation or for IPv6,
     *  hexadecimal string format. If the AI_PASSIVE flag is specified in hints.ai_flags, and node is NULL, then the
     *  returned socket addresses will be suitable for bind()ing a socket that will accept() connections.
     *  The returned socket address will contain the "wildcard address" (INADDR_ANY for IPv4 addresses, IN6ADDR_ANY_INIT for IPv6 address).
     *  The wildcard address is used by applications (typically servers) that intend to accept connections on any of the hosts's network addresses.
     *  If node is not NULL, then the AI_PASSIVE flag is ignored.
     * @param service It sets the port in each returned address structure. Either node or service, but not both, may be NULL.
     * @param hints This argument points to an addrinfo structure that specifies criteria for selecting the socket address
     *  structures returned in the list pointed to by res. If hints is not NULL it points to an addrinfo structure whose ai_family,
     *  ai_socktype, and ai_protocol specify criteria that limit the set of socket addresses returned by getaddrinfo().
     * @param res An output parameter that is a pointer to the start of a linked list of addrinfo structures,
     *  one for each network address that matches node and service, subject to any restrictions imposed by hints.
     *
     * @return Returns 0 if it succeeds, or one of the following nonzero error codes: EAI_ADDRFAMILY, EAI_AGAIN, EAI_BADFLAGS, etc.
     */
    int resultOfAddressInfo = getaddrinfo(NULL, service, &hints, &res);
    if(resultOfAddressInfo != 0)
    {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(resultOfAddressInfo));
        exit(1);
    }

    /**
     * @brief When a socket is created with socket(), it exists in a name space (address family)
     *  but has no address assigned to it. bind() assigns the address specified by addr to the socket
     *  referred to by the file descriptor sockfd. addrlen specifies the size, in bytes, of the
     *  address structure pointed to by addr. Traditionally, this operation is called "assigning a name to a socket".
     *
     *  int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
     *
     * @param serverSockFd Socket referred to by the file descriptor serverSockFd
     * @param res->ai_addr sockaddr address that will be assigned to serverSockFd
     * @param res->ai_addrlen This specifies the size, in bytes, of the address structure pointed to by res->ai_addr
     *
     * @return On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
     *
     */
    if(bind(serverSockFd, res->ai_addr, res->ai_addrlen) != 0)
    {
        perror("Error in bind()");
        exit(1);
    }

    /**
     * @brief It marks the socket referred to by sockfd as a passive socket,that is, as a
     *  socket that will be used to accept incoming connection requests using accept().
     *
     *  int listen(int sockfd, int backlog);
     *
     * @param sockfd This argument is a file descriptor that refers to a socket of type SOCK_STREAM or SOCK_SEQPACKET.
     * @param backlog This argument defines the maximum length to which the queue of pending
     *  connections for sockfd may grow. If a connection request arrives when the queue is full,
     *  the client may receive an error with an indication of ECONNREFUSED or, if the underlying
     *  protocol supports retransmission, the request may be ignored so that a later reattempt at connection succeeds.
     *
     * @return On success, zero is returned. On error, -1 is returned, and errno is set appropriately.
     */
    if(listen(serverSockFd, 10) != 0)
    {
        perror("Error in listen()");
        exit(1);
    }

    /**
     * @brief The accept() system call is used with connection-based socket types (SOCK_STREAM, SOCK_SEQPACKET).
     *  It extracts the first connection request on the queue of pending connections for the listening socket,
     *  sockfd, creates a new connected socket, and returns a new file descriptor referring to that socket.
     *  The newly created socket is not in the listening state. The original socket sockfd is unaffected by this call.
     *
     *  int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
     *
     * @param sockfd This argument is a socket that has been created with socket(),
     *  bound to a local address with bind(), and is listening for connections after a listen().
     * @param addr This argument is a pointer to a sockaddr structure. This structure is filled in with the address
     *  of the peer socket, as known to the communications layer. The exact format of the address returned
     *  addr is determined by the socket's address family (see socket() and the respective protocol man pages).
     *  When addr is NULL, nothing is filled in; in this case, addrlen is not used, and should also be NULL.
     * @param addrlen This argument is a value-result argument: the caller must initialize it to contain the
     *  size (in bytes) of the structure pointed to by addr; on return it will contain the actual size of the peer address.
     *
     * @return On success, these system calls return a nonnegative integer that is a descriptor for the accepted
     *  socket. On error, -1 is returned, and errno is set appropriately.
     */
    while(1)
    {
        printf("Server is waiting for incoming connection\n");
        printf("-----------------------------------------\n\n");
        struct sockaddr clientAddr;
        socklen_t clientAddrLen;
        int clientSocketFd = accept(serverSockFd, (struct sockaddr *)&clientAddr, &clientAddrLen);
        if(clientSocketFd == -1)
        {
            perror("accept() calls fails to return client's socket descriptor");
            exit(1);
        }

        //Get the info of the client who server just accepted
        char clientStr[INET_ADDRSTRLEN];
        inet_ntop(clientAddr.sa_family, &(((struct sockaddr_in*)&clientAddr)->sin_addr), clientStr, sizeof(clientStr));
        printf("Connection made with clientSocketFd = %d and client's IP = %s\n", clientSocketFd, clientStr);

        //NOTE: The buffer size of 100 is sufficient for this project since the server expects a very
        //  small data (each time) from the client but it could be wrapped in a loop to receive a large data
        //  that will keep reading until all the data sent by the client is received
        int a = 3;
        while(a > 0)
        {
            char dataSentByClient[500];
            int len = recv(clientSocketFd, dataSentByClient, sizeof(dataSentByClient) - 1, 0);
            if(len == -1)
            {
                perror("recv() didn't return any bytes");
                exit(1);
            }
            dataSentByClient[len] = '\0';

            printf("Message size: %d bytes\n", len);
            printf("Message: %s\n", dataSentByClient);

            //Send a response to the client
            len = send(clientSocketFd, "I got your message", 18, 0);
            if(len < 0)
            {
                perror("Error writing to client's socket");
                exit(1);
            }
            a--;
        }
    }

    return 0;
}
