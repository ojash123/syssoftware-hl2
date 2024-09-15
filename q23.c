/*
Ojas Hegde
MT2024105
23 Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <errno.h>

int main() {
    struct rlimit limit;
    
    // Get the maximum number of open files
    if (getrlimit(RLIMIT_NOFILE, &limit) == -1) {
        perror("Error getting maximum number of open files");
        exit(EXIT_FAILURE);
    }
    printf("Maximum number of files that can be opened within a process: %ld\n", limit.rlim_cur);

    int pipefd[2];
    if (pipe(pipefd) == -1) {
        perror("Error creating pipe");
        exit(EXIT_FAILURE);
    }
    int pipe_size = fcntl(pipefd[0], F_GETPIPE_SZ);
    

    printf("Size of the pipe (circular buffer): %d bytes\n", pipe_size);
    close(pipefd[0]);
    close(pipefd[1]);

    return 0;
}
/*
$ ./a.out 
Maximum number of files that can be opened within a process: 1048576
Size of the pipe (circular buffer): 65536 bytes
*/