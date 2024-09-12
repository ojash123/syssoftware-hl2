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



int main(){
    int pid;
    printf("Enter Process id of 13a: ");
    scanf("%d", &pid);
    kill(pid, SIGSTOP);
}
/*
$ ./a.out 
Enter Process id of 13a: 5248
*/