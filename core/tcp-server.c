#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>

// The connection of two nodes on a network to communicate with each other. The first node(socket fd) listens at port 8080 at an IP while the other node (socket new_fd) reaches out to the other to form a connection
// Server makes the listening socket 

int net_server() {

    unsigned short port = 8080;

    // local memory array used to temporarily hold data as it moves between application layer and the kernels internal TCP socket buffer
    char buffer[1024] = { 0 };

    //stores address for the Internet addr family
    struct sockaddr_in addr;
    socklen_t addr_l = sizeof(addr);

    // binding socket addr to a port (8080)
    addr.sin_family = AF_INET; //IPv4 
    addr.sin_port = htons(port); // 8080 local port
    addr.sin_addr.s_addr = INADDR_ANY; // any local IPv4 addr


    // creating of a server socket and check if it is created
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0){
        perror("socket not found");
        exit(EXIT_FAILURE);
    }

    // helps manipulate options for fd; prevents "address already in use" errors
    int option = 1;

    if(setsockopt(fd, IPPROTO_TCP, SO_REUSEADDR | SO_REUSEPORT, &option, sizeof(option))){
        perror("setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // binds a name to my socket fd (socket, points to sockaddr structure containing the address to the bound socket, specifies the length of the sockaddr structure pointed to by the address argument)
    if(!(bind(fd, (struct sockaddr_in*)&addr, addr_l))) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for socket connections and limit the queue of incoming connections
    // socket and backlog para -> backlog describes the limit for the queue

    // maximum kernel backlog -> 128 
    // backlog: number representing the size of the queue holding the pending connections while the server is waiting to accept a connection.
    if(!listen(fd, 2)){
        perror("listen failure");
        exit(EXIT_FAILURE);
    }
    
    // accept extracts the first connection on the queue of pending connections, creates a new socket with the same socket type protocol and address family as the specificied socket, and allocates a new file descriptor for that socket
    int new_fd = accept(fd, (struct sockaddr_in*)&addr, &addr_l);
    if(!new_fd){
        perror("accept failure");
        exit(EXIT_FAILURE);
    }
    
    // ssize_t -> signed int type representing a count of bytes and returns -1
    // read attempts to read byte data from fd socket into the buffer queue; subtracting 1 from total buffer for null
    ssize_t read_data = read(fd, buffer, 1024 - 1);
    printf("%s\n", buffer);

    // sending data to the client side (type ssize_t to send data in bytes) as a message
    char* server_message = "Hello from server";
    send(fd, server_message, strlen(server_message), 0);

    printf("Server message sent\n");

    // connected socket closed
    close(new_fd);

    // listen socket closed
    close(fd);
    return 0;
}