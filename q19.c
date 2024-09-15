/*
Ojas Hegde
MT2024105
19. Create a FIFO file by
a. mknod command
b. mkfifo command
c. use strace command to find out, which command (mknod or mkfifo) is better.
c. mknod system call
d. mkfifo library function
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(){
    mknod("myfifo1", S_IFIFO | 0600, 0);
    mkfifo("myfifo2", 0600);
}

/*
mkfifo is slower
mknodat(AT_FDCWD, "myfifo1", S_IFIFO|0600) = 0 <0.000140>
mknodat(AT_FDCWD, "myfifo2", S_IFIFO|0600) = 0 <0.000185>
*/