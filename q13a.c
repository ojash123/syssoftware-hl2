/*
Ojas Hegde
MT2024105
13. Write two programs: first program is waiting to catch SIGSTOP signal, the second program
will send the signal (using kill system call). Find out whether the first program is able to catch
the signal or not.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void handle_sigstop(int signum){
    printf("I have been sent sigstop\n");
    exit(0);
}

int main(){
    signal(SIGSTOP, (void *)handle_sigstop);
    printf("My process id is %d\n", getpid());
    while(1);
}

/*
sigstop cannot be caught blocked or ignored
$ ./a.out 
My process id is 5248

[5]+  Stopped                 ./a.out
*/