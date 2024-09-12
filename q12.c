/*
Ojas Hegde
MT2024105
12. Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
the parent process from the child process.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
    if(!fork()){
        printf("Killing Parent process. Parent: %d child: %d\n", getppid(), getpid());
        kill(getppid(), SIGKILL);
        sleep(10);
    }else{
        printf("Created Child process\n");
        sleep(10);
    }
    
}
/*
$ ./a.out 
Created Child process
Killing Parent process. Parent: 4330 child: 4331
Killed
*/