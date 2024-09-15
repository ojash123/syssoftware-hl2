/*
Ojas Hegde
MT2024105
27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <string.h>

struct my_msg{
    long mtype;
    char msg_text[80];
};

int main(){
    struct my_msg message;
    key_t key;
    int msqid;

    key = ftok("messages", 65);
    msqid = msgget(key, IPC_CREAT | 0666);

    if (msgrcv(msqid, &message, sizeof(message.msg_text), 1, 0) == -1) {
        perror("msgrcv failed");
        exit(EXIT_FAILURE);
    }

    // Print the received message
    printf("Received message: %s\n", message.msg_text);
}
/*
$ ./a.out 
Received message: first message
*/