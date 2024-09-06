/*
Ojas Hegde
MT2024105
7. Write a simple program to print the created thread ids.
Copied q6 as I already printed the thread ids in that one*/

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

void thread_func(void) { 
    printf("Process ID: %d\tThread id is %ld\n",getpid(), pthread_self()); 
}
int main ( ) {  
    pthread_t mythread1, mythread2, mythread3;  

    if(pthread_create( &mythread1, NULL, (void *) thread_func, NULL)!= 0)perror("Thread 1 error"); 
    if(pthread_create( &mythread2, NULL, (void *) thread_func, NULL)!= 0)perror("Thread 2 error"); 
    if(pthread_create( &mythread3, NULL, (void *) thread_func, NULL)!= 0)perror("Thread 3 error"); 
}

/*
$ ./a.out 
Process ID: 17935       Thread id is 128158745495232
Process ID: 17935       Thread id is 128158755980992
Process ID: 17935       Thread id is 128158735009472
*/