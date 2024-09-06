/*
Ojas Hegde
MT2024105
9. Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
signal - Use signal system call.
*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main(){
    signal(SIGINT, SIG_IGN);
    printf("The program is ignoring keyboard interrupts\n");
    sleep(5);
    signal(SIGINT, SIG_DFL);
    printf("The program will no longer ignore keyboard interrupts\n");
    sleep(5);
    printf("Didn't Interrupt?\n");
}

/*
$ ./a.out 
The program is ignoring keyboard interrupts
^C^C^C^C^CThe program will no longer ignore keyboard interrupts
^C
*/