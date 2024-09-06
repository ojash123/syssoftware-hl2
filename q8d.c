/*
Ojas Hegde
MT2024105
8. Write a separate program using signal system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
d. SIGALRM (use alarm system call)
e. SIGALRM (use setitimer system call)
f. SIGVTALRM (use setitimer system call)
g. SIGPROF (use setitimer system call)
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>

void handler(int signum){
    printf("Handling alarm signal no: %d\n", signum);
    exit(0);
}
int main(){
    signal(SIGALRM, (void *)handler);
    alarm(5);
    while(1);
}
/*
$ ./a.out 
Handling alarm signal no: 14
*/