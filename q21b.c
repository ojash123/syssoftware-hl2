/*
Ojas Hegde
MT2024105
21. Write two programs so that both can communicate by FIFO -Use two way communications.
*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(){
    int p1, p2;
    p1 = open("myfifo1", O_RDONLY);
    
    char msg[80];
    read(p1, msg, sizeof(msg));
    printf("Received : %s\n", msg);
    close(p1);
    p2 = open("myfifo2", O_RDONLY);
    scanf("%s", msg);
    write(p2, msg, strlen(msg) + 1);
    close(p2);
}