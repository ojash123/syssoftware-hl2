/*
Ojas Hegde
MT2024105
33. Write a program to communicate between two machines using socket.
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>

int main(){
    struct sockaddr_in server;
    int sd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    int e = connect(sd, &server, sizeof(server));
    if(e == -1){
        perror("connect failed");
    }
    char buffer[1024];
    char* msg = "Hello from client";
    //read(sd, buffer, 1024);
    send(sd, msg, strlen(msg), 0);
    printf("The message from Server is %s\n", buffer);
    close(sd);
}
/*
$ ./client 
The message from Server is Connected to Server
*/