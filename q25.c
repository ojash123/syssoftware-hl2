/*
Ojas Hegde
MT2024105
25. Write a program to print a message queue's (use msqid_ds and ipc_perm structures)
a. access permission
b. uid, gid
c. time of last message sent and received
d. time of last change in the message queue
d. size of the queue
f. number of messages in the queue
g. maximum number of bytes allowed
h. pid of the msgsnd and msgrcv
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <time.h>
#define msgkey 0x41071a46
int main() {
    key_t key = msgkey;
    int msqid;
    struct msqid_ds buf;
    // Get the message queue ID
    msqid = msgget(key, 0666);
    if (msqid == -1) {
        perror("msgget failed");
        return 1;
    }

    // Get message queue info using msgctl and IPC_STAT
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl failed");
        return 1;
    }

    // Print access permissions
    printf("a. Access permissions: %o\n", buf.msg_perm.mode);

    // Print user ID and group ID
    printf("b. UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);

    // Print time of last message sent and received
    printf("c. Time of last message sent: %s", ctime(&buf.msg_stime));
    printf("   Time of last message received: %s", ctime(&buf.msg_rtime));

    // Print time of last change in the message queue
    printf("d. Time of last change: %s", ctime(&buf.msg_ctime));

    // Print the size of the queue
    printf("e. Size of the queue: %lu bytes\n", buf.__msg_cbytes);  // __msg_cbytes shows the current number of bytes in the queue

    // Print the number of messages in the queue
    printf("f. Number of messages in the queue: %lu\n", buf.msg_qnum);

    // Print the maximum number of bytes allowed in the queue
    printf("g. Maximum number of bytes allowed in the queue: %lu\n", buf.msg_qbytes);

    // Print the PID of the last msgsnd and msgrcv
    printf("h. PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("   PID of last msgrcv: %d\n", buf.msg_lrpid);

    return 0;
}

/*
$ ./a.out 
a. Access permissions: 666
b. UID: 1000, GID: 1000
c. Time of last message sent: Thu Jan  1 05:30:00 1970
   Time of last message received: Thu Jan  1 05:30:00 1970
d. Time of last change: Sun Sep 15 11:12:33 2024
e. Size of the queue: 0 bytes
f. Number of messages in the queue: 0
g. Maximum number of bytes allowed in the queue: 16384
h. PID of last msgsnd: 0
   PID of last msgrcv: 0
   */