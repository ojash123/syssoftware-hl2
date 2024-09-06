/*
Ojas Hegde
MT2024105
11. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -
use sigaction system call.
*/
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
    struct sigaction sa;
    sa.sa_handler = SIG_IGN;
    sa.sa_flags = 0;
    sigaction(SIGINT, &sa, NULL);
    printf("The program is ignoring keyboard interrupts\n");
    sleep(5);
    sa.sa_handler = SIG_DFL;
    sigaction(SIGINT, &sa, NULL);
    printf("The program will no longer ignore keyboard interrupts\n");
    sleep(5);
    printf("Didn't Interrupt?\n");
}
/*
$ ./a.out 
The program is ignoring keyboard interrupts
^C^C^C^C^C
The program will no longer ignore keyboard interrupts
^C
*/