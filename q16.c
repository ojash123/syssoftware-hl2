/*
Ojas Hegde
MT2024105
16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
*/
#include <stdio.h>
#include <unistd.h>

int main(){
    int p1[2], p2[2];
    pipe(p1);
    pipe(p2);
    if(!fork()){
        close(p1[1]);
        close(p2[0]);
        char buf[80];
        read(p1[0], buf, sizeof(buf));
        printf("Read '%s' in child\n", buf);
        close(p1[0]);
        printf("Enter a message: ");
        char buf2[80];
        scanf("%s", buf2);
        write(p2[1], buf2, sizeof(buf));
        close(p1[0]);
        close(p2[1]);
    }else{
        close(p1[0]);
        close(p2[1]);
        printf("Enter a message: ");
        char buf[80];
        scanf("%s", buf);
        write(p1[1], buf, sizeof(buf));
        char buf2[80];
        read(p2[0], buf2, sizeof(buf2));
        printf("Read '%s' in parent\n", buf2);
        close(p2[0]);
        close(p1[1]);

    }
}
/*
$ ./a.out 
Enter a message: hello
Read 'hello' in child
Enter a message: hi
Read 'hi' in parent
*/