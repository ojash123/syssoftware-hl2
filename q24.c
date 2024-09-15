/*
Ojas Hegde
MT2024105
24. Write a program to create a message queue and print the key and message queue id.
*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msqid;

    key = ftok("messages", 65);  // "progfile" is a file path; 65 is an arbitrary id value
    if (key == -1) {
        perror("ftok failed");
        return 1;
    }

    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget failed");
        return 1;
    }

    // Print the key and the message queue ID
    printf("Message Queue Key: %x\n", key);  
    printf("Message Queue ID: %d\n", msqid);

    return 0;
}
/*
$ ./a.out 
Message Queue Key: 41071a46
Message Queue ID: 0
*/