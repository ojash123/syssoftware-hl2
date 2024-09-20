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
    struct sockaddr_in server, cli;
    int sd, newsd;
    sd = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);
    int e;
    e = bind(sd, &server, sizeof(server));
    if(e == -1){
        perror("bind failed");
    }
    e = listen(sd, 5);
    if(e == -1){
        perror("bind failed");
    }
    printf("server listening on port 8080\n");
    int addrlen = sizeof(cli);
    newsd = accept(sd, &cli, &addrlen);
    if(newsd == -1){
        perror("accept failed");
    }
    char buffer[1024];
    char* msg = "Connected to Server";
    int s = send(newsd, msg, strlen(msg), 0);
    if(s == -1){
        perror("Send failed");
    }
    read(newsd, buffer, 1024);
    printf("sent %d The message from the client is %s\n",s,  buffer);
    close(sd);
    close(newsd);
}
/*
$ ./server 
server listening on port 8080
sent 19 The message from the client is Hello from client

*/