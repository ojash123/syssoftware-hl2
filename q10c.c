/*
Ojas Hegde
MT2024105
10. Write a separate program using sigaction system call to catch the following signals.
a. SIGSEGV
b. SIGINT
c. SIGFPE
*/
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handler(int signum){
    printf("Handling sigfpe with sigaction. Sig no: %d\n", signum);
    exit(0);
}

int main(){
    struct sigaction sa;
    
    sa.sa_handler=handler;
    sa.sa_flags=0;
    sigaction(SIGFPE,&sa,NULL);
    int b = 10/0;
}

/*
$ ./a.out 
Handling sigfpe with sigaction. Sig no: 8
*/