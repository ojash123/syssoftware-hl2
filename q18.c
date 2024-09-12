/*
Ojas Hegde
MT2024105
18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
*/
#include <stdio.h>
#include <unistd.h>
int main(){
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);
    if(fork() > 0){
        close(p1[0]);
        //printf("Child\n");
        dup2(p1[1], 1);
        execlp("ls", "ls", "-l", NULL);
    }else{
        if(fork() > 0){
            close(p1[1]);
            close(p2[0]);
            dup2(p1[0], 0);
            //printf("Child 1\n");
            dup2(p2[1], 1);
            
            execlp("grep", "grep", "^d", NULL);

        }else{
            close(p2[1]);
            dup2(p2[0], 0);
            //printf("Child 2\n");
            execlp("wc", "wc", NULL);
        }
    }
}