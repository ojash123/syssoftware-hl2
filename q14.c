/*
Ojas Hegde
MT2024105
14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor
*/
#include <stdio.h>
#include <unistd.h>

int main(){
    int p[2];
    pipe(p);
    char buf[10] = "Hello!\n";
    write(p[1], buf, sizeof(buf));
    printf("Written\n");
    char r[10];
    read(p[0], r, sizeof(r));
    printf("Read: %s", r);
}
/*
$ ./a.out 
Written
Read: Hello!
*/