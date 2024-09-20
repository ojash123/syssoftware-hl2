/*
Ojas Hegde
MT2024105
34. Write a program to create a concurrent server.
a. use fork
b. use pthread_create
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <pthread.h>
void handle_client(void* sock) {
    int client_socket = *((int *)sock);
    free(sock);
    char buffer[1024] = {0};
    int bytes_read;
    while ((bytes_read = read(client_socket, buffer, 1024)) > 0) {
        printf("Received from client: %s\n", buffer);
        memset(buffer, 0, 1024);
    }
    if(bytes_read == -1){
        perror("read");
    }
    close(client_socket);
}
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

    while(1){
        newsd = accept(sd, &cli, &addrlen);
        if(newsd == -1){
            perror("accept failed");
            exit(EXIT_FAILURE);
        }
        int *sock = malloc(sizeof(int));
        *sock = newsd; 
        pthread_t mythread;
        if(pthread_create( &mythread, NULL, (void *) handle_client, sock) != 0){
            perror("Thread");
            free(sock);
        }
        pthread_detach(mythread);
    }
}
/*
$ ./server 
server listening on port 8080
Received from client: Hello from client
Received from client: Hello from client
Received from client: Hello from client
^C

*/