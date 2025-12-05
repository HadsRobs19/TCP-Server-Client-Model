#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>


int net_server() {

    unsigned short port = 8080;

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

    // binds a name to my socket fd
    if(!(bind(fd, &addr, sizeof(addr_l)))) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
     
    //return 0;
}

int net_client(){

}

int main(void){
    printf("Hello World\n");
    return 0;
}