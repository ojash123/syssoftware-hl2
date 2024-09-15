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
    p1 = open("myfifo1", O_WRONLY);
    
    printf("Enter a message: ");
    char msg[80];
    scanf("%s", msg);
    write(p1, msg, strlen(msg) + 1);
    close(p1);
    p2 = open("myfifo2", O_RDONLY);
    read(p2, msg, sizeof(msg));
    printf("Received : %s\n", msg);
    close(p2);
}
/*
$ ./a.out 
Enter a message: hello
*/