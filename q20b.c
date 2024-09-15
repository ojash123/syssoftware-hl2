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
    fd = open("myfifo1", O_RDONLY);
    char msg[80];
    read(fd, msg, sizeof(msg));
    printf("Received : %s\n", msg);
}
/*
$ ./a.out 
Received : hello
*/