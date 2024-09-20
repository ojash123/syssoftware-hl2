/*
Ojas Hegde
MT2024105
31. Write a program to create a semaphore and initialize value to the semaphore.
a. create a binary semaphore
b. create a counting semaphore
*/
#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <stdlib.h>

int main(){
    key_t key = ftok(".", 65);
    int semid;
    semid = semget(key, 2, IPC_CREAT | 0744);
    if(semid == -1){
        perror("Semget");
        exit(EXIT_FAILURE);
    }
    if(semctl(semid, 0, SETVAL, 1) == -1){
        perror("Semctl 1");
        exit(EXIT_FAILURE);
    }
    printf("Binary semaphore initialized\n");
    if(semctl(semid, 1, SETVAL, 5) == -1){
        perror("Semctl 2");
        exit(EXIT_FAILURE);
    }
    printf("Counting Semaphore initialized\n");
    
}
/*
$ ./a.out 
Binary semaphore initialized
Counting Semaphore initialized
*/