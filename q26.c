/*
Ojas Hegde
MT2024105
26. Write a program to send messages to the message queue. Check $ipcs -q
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
    printf("Enter a message: ");
    fgets(message.msg_text, 80, stdin);
    message.mtype = 1;
    if (msgsnd(msqid, &message, sizeof(message.msg_text), 0) == -1) {
        perror("msgsnd failed");
        exit(1);
    }

    printf("Message sent to queue: %s", message.msg_text);

    return 0;
}
/*
$ ./a.out 
Enter a message: first message
Message sent to queue: first message
syssoftware-hl2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages    
0x41071a46 0          ojas       666        80           1           
*/
