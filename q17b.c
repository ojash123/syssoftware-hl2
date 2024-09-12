/*
Ojas Hegde
MT2024105
17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
*/
#include <stdio.h>
#include <unistd.h>

int main(){
    int p[2];
    pipe(p);
    if(!fork()){
        close(p[1]);
        dup2(p[0], 0);
        execlp("wc","wc",  (char *)NULL);
    }else{
        close(p[0]);
        dup2(p[1], 1);
        execlp("ls","ls", "-l", (char *)NULL);

    }
}
/*
$ ls -l | wc
     32     281    1502

$ ./a.out 
     32     281    1502
*/