/*
Ojas Hegde
MT2024105
30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
*/
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>

int main(){
    key_t key;
    int shmid;
    key = ftok(".", 66);
    shmid = shmget(key, 1024, IPC_CREAT | 0744);
    char* str = (char*)shmat(shmid, (void*)0, 0);
    printf("Enter a string: ");
    fgets(str, 1024, stdin);
    printf("The data is %s\n", str);
    shmdt(str);
    char* s2 = (char*)shmat(shmid, 0, SHM_RDONLY);
    printf("Reading with read only: %s\nEnter new data: ", s2);
    fgets(s2, 1024, stdin);
    printf("Tried to overwrite. Data: %s\n", s2);
    
    shmdt(s2);
    shmctl(shmid, IPC_RMID, 0);

}
/*
 ./a.out 
Enter a string: hello shm
The data is hello shm

Reading with read only: hello shm

Enter new data: overwrite
Segmentation fault (core dumped)

without shm_rdonly
$ ./a.out 
Enter a string: hello shm
The data is hello shm

Reading with read only: hello shm

Enter new data: overwrite
Tried to overwrite. Data: overwrite
*/