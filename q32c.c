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
#include <unistd.h>
int main(){
    key_t key = ftok("q32c.c", 65);
    int semid = semget(key, 1, IPC_CREAT | 0744);
    struct sembuf buf = {0, -1, 0};
    printf("Entering Critical section...\n");
    semop(semid, &buf, 1);
    printf("Using a resource...\n");
    printf("Enter to continue...");
    getchar();
    buf.sem_op = 1;
    semop(semid, &buf, 1);

    printf("Unlocked a resource\n");
}

/*
$ ./a.out 
Entering Critical section...
Using a resource...
Enter to continue...
Unlocked a resource
*/