/*
Ojas Hegde
MT2024105
28. Write a program to change the exiting message queue permission. (use msqid_ds structure)
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

int main(){
    key_t key;
    int msqid;
    struct msqid_ds queue_info;

    key = ftok("messages", 65);
    msqid = msgget(key, IPC_CREAT | 0666);
    if (msgctl(msqid, IPC_STAT, &queue_info) == -1) {
        perror("msgctl IPC_STAT failed");
        exit(EXIT_FAILURE);
    }
    printf("Current permissions: %o\n", queue_info.msg_perm.mode);

    queue_info.msg_perm.mode = 0777;

    msgctl(msqid, IPC_SET, &queue_info);
    printf("Permissions changed successfully.\n");

    if (msgctl(msqid, IPC_STAT, &queue_info) == -1) {
        perror("msgctl IPC_STAT failed");
        exit(EXIT_FAILURE);
    }
    printf("Current permissions: %o\n", queue_info.msg_perm.mode);

}
/*
$ ./a.out 
Current permissions: 666
Permissions changed successfully.
Current permissions: 777
*/