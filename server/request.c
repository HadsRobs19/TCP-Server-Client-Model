#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <stdio.h>

int main(){

    // create a socket endpoint
    unsigned short port = 8080;
    struct sockaddr_in http_addr;
    socklen_t http_l = sizeof(http_addr);

    http_addr.sin_family = AF_INET;
    http_addr.sin_port = htons(port);
    http_addr.sin_addr.s_addr = INADDR_ANY;

    int http_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(http_fd < 0){
        perror("Socket creation failure");
        exit(EXIT_SUCCESS);
    }
    
    // make a file loader program (html file into mem into buffer) and sends html as http message to client (massive string) 
    // send a general http request back to user
    // after, make file deloader
    // start with http 1.1

}