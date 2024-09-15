/*
Ojas Hegde
MT2024105
20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main(){
    int fd;
    fd = open("myfifo1", O_WRONLY);
    printf("Enter a message: ");
    char msg[80];
    scanf("%s", msg);
    write(fd, msg, strlen(msg) + 1);
}
/*
$ ./a.out 
Enter a message: hello
*/