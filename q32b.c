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
#include <sys/shm.h>

int main(){
    key_t shmkey, semkey;
    int shmid, semid;
    shmkey = ftok("q32b.c", 65);
    semkey = ftok(".", 65);
    shmid = shmget(shmkey, 1024, IPC_CREAT| 0744);
    semid = semget(semkey, 1, 0744);
    struct sembuf buf = {0, -1, 0};
    printf("Entering Critical section...\n");
    semop(semid, &buf, 1);
    char* str = (char*)shmat(shmid, (void*)0, 0);
    printf("The Current data is %s\n", str);
    printf("Enter a string: ");
    fgets(str, 1024, stdin);
    printf("The written data is %s\n", str);
    shmdt(str);
    printf("Enter to continue...");
    getchar();
    buf.sem_op = 1;
    semop(semid, &buf, 1);

    printf("Unlocked\n");
}
/*
$ ./a.out 
Entering Critical section...
The Current data is hello shm

Enter a string: bye shm
The written data is bye shm

Enter to continue...
Unlocked

*/