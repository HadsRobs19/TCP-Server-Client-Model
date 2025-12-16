// Client is reaching out to the servers listening socket
#include <sys/socket.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(int argc, char const* argv[]){
    unsigned short port = 8080;
    struct sockaddr_in s_addr;
    socklen_t addr_l = sizeof(s_addr);
    
    s_addr.sin_family = AF_INET;
    s_addr.sin_port = htons(port);

    int c_fd; 
    if((c_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0){
        printf("\nsocket failed to instatiate \n");
        return -1;
    }
        
    if(inet_pton(AF_INET, "127.0.0.1", &s_addr.sin_addr) <= 0){
        printf("Invalid/unsupported address");
        return -1;
    }

    int status;
    if((status = connect(c_fd, (struct sockaddr*) &s_addr, sizeof(s_addr))) < 0){
        perror("\nconnection failure \n");
        return -1;
    }
    char buffer[1024] = { 0 };

    char* c_message = "hello from client";
    send(c_fd, c_message, strlen(c_message), 0);
    int read_data = read(c_fd, buffer, 1024 - 1);

    printf("%s\n", buffer);

    close(c_fd);
    return 0;
}