#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

int main(void){
    int fd;
    fd = open("ticket.txt", O_RDWR | O_CREAT, 0744);
    int tno = 10;
    write(fd, &tno, sizeof(tno));
    printf("Written %d to ticket.txt\n", tno);
    close(fd);
}