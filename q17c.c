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
#include <fcntl.h>
int main(){
    int p[2];
    pipe(p);
    if(!fork()){
        close(p[1]);
        close(0);
        fcntl(p[0], F_DUPFD, 0);
        execlp("wc","wc",  (char *)NULL);
    }else{
        close(p[0]);
        close(1);
        fcntl(p[1], F_DUPFD, 0);
        execlp("ls","ls", "-l", (char *)NULL);

    }
}
/*
$ ls -l | wc
     33     290    1551
     
$ ./a.out 
     33     290    1551
*/