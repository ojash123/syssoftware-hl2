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
        close(0);
        dup(p[0]);
        execlp("wc","wc",  (char *)NULL);
    }else{
        close(p[0]);
        close(1);
        dup(p[1]);
        execlp("ls","ls", "-l", (char *)NULL);

    }
}
/*
$ ls -l | wc
     31     272    1453

$ ./a.out 
     31     272    1453
*/