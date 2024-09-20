/*
Ojas Hegde
MT2024105
32. Write a program to implement semaphore to protect any critical section.
a. rewrite the ticket number creation program using semaphore
b. protect shared memory from concurrent write access
c. protect multiple pseudo resources ( may be two) using counting semaphore
d. remove the created semaphore
*/
#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
int main(){
    key_t key = ftok(".", 65);
    int semid = semget(key, 1, IPC_CREAT | 0744);
    //semctl(semid, 0, SETVAL, 1);
    struct sembuf buf = {0, -1, 0};
    printf("Entering Critical section...\n");
    semop(semid, &buf, 1);
    int tno;
    int fd = open("ticket.txt", O_CREAT | O_RDWR, 0744);
    read(fd, &tno, sizeof(tno));

    printf("Read %d\n", tno);
    tno++;
    lseek(fd, -1 * sizeof(tno), SEEK_CUR);
    write(fd, &tno, sizeof(tno));
    printf("Enter to continue...");
    getchar();
    buf.sem_op = 1;
    semop(semid, &buf, 1);

    printf("Unlocked\n");
}

/*
$ ./a.out 
Entering Critical section...
Read 22
Enter to continue...
Unlocked
*/