/*
Ojas Hegde
MT2024105
22. Write a program to wait for data to be written into FIFO within 10 seconds, use select
system call with FIFO.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/select.h>
#include <sys/time.h>
#include <sys/types.h>
#include <errno.h>

int main(){
    int fd;
    char buffer[80];
    fd_set read_fds;
    struct timeval timeout;
    fd = open("myfifo", O_RDONLY );
    FD_ZERO(&read_fds);  // Clear all entries from the set
    FD_SET(fd, &read_fds);  // Add the FIFO file descriptor to the set

    // Set timeout to 10 seconds
    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int retval = select(fd + 1, &read_fds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select()");
        close(fd);
        exit(EXIT_FAILURE);
    } else if (retval) {
        // Data is available; read from the FIFO
        int num_bytes = read(fd, buffer, sizeof(buffer));
        if (num_bytes > 0) {
            buffer[num_bytes] = '\0';  
            printf("Received data: %s\n", buffer);
        } else {
            perror("Error reading from FIFO");
        }
    } else {
        // Timeout reached
        printf("No data written to FIFO within 10 seconds.\n");
    }

    // Close the FIFO
    close(fd);
}
/*
 echo "hello" > myfifo

$ ./a.out 
Received data: hello
*/