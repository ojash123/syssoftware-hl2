/*
Ojas Hegde
MT2024105
4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.*/

#include <unistd.h>
#include <stdio.h>
#include <time.h>

int rdtsc(){
    unsigned long long dst;
    __asm__ __volatile__ ("rdtsc": "=A" (dst));
}

int main(){
    int nano;
    unsigned long long start, end;
    start = rdtsc();
    for(int i = 0; i < 100; i++)
        getppid();
    end = rdtsc();
    nano = (end - start)/ 1.20;
    printf("The function takes %d nano secs\n", nano);
}

/*
$ ./a.out 
The function takes 42723 nano secs
*/