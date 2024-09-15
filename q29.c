/*
Ojas Hegde
MT2024105
29. Write a program to remove the message queue.
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){
    key_t key;
    int msqid;

    key = ftok("messages", 65);
    msqid = msgget(key, IPC_CREAT | 0666);
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl IPC_RMID failed");
        exit(EXIT_FAILURE);
    }
    printf("Message queue with id %x removed\n", msqid);
}
/*
$ ./a.out 
Message queue with id 0 removed
*/