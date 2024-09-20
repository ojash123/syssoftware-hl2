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
    if(-1 == semctl(semid, 1, IPC_RMID)){
        perror("Semctl1");
        exit(EXIT_FAILURE);
    }
    printf("Destroyed Counting semaphore\n");
    key = ftok(".", 65);
    semid = semget(key, 1, IPC_CREAT | 0744);
    if(-1 == semctl(semid, 1, IPC_RMID)){
        perror("Semctl2");
        exit(EXIT_FAILURE);
    }
    printf("Destroyed binary semaphore\n");
}
/*
$ ./a.out 
Destroyed Counting semaphore
Destroyed binary semaphore
 ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems     
*/