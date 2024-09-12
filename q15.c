/*
Ojas Hegde
MT2024105
15. Write a simple program to send some data from parent to the child process.
*/
#include <stdio.h>
#include <unistd.h>

int main(){
    int p[2];
    pipe(p);
    if(!fork()){
        close(p[1]);
        char buf[80];
        read(p[0], buf, sizeof(buf));
        printf("Read '%s' in child\n", buf);
        close(p[0]);
    }else{
        close(p[0]);
        printf("Enter a message: ");
        char buf[80];
        scanf("%s", buf);
        write(p[1], buf, sizeof(buf));
        close(p[1]);

    }
}
/*
$ ./a.out 
Enter a message: hello
Read 'hello' in child
*/