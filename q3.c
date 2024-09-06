/*
Ojas Hegde
MT2024105
3. Write a program to set (any one) system resource limit. Use setrlimit system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

int main(){
    struct rlimit limit;
    getrlimit(RLIMIT_LOCKS, &limit);
    printf("The current soft limit for File locks is: %ld\n", (long)limit.rlim_cur);
    limit.rlim_cur = 1;
    setrlimit(RLIMIT_LOCKS, &limit);
    getrlimit(RLIMIT_LOCKS, &limit);
    printf("The changed soft limit for File locks is: %ld\n", (long)limit.rlim_cur);
}
/*
$ ./a.out 
The current soft limit for File locks is: -1 // -1 corresponds to infinity
The changed soft limit for File locks is: 1
*/