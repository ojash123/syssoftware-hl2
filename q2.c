/*
Ojas Hegde
MT2024105
2. Write a program to print the system resource limits. Use getrlimit system call.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>

// Function to print the resource limits
void print_limit(int resource, const char *name) {
    struct rlimit limit;
    
    // Get the resource limit
    if (getrlimit(resource, &limit) == 0) {
        printf("%s Soft limit: ", name);
        if (limit.rlim_cur == RLIM_INFINITY) {
            printf("Unlimited");
        } else {
            printf("%ld", (long) limit.rlim_cur);
        }
        
        printf(" | Hard limit: ");
        if (limit.rlim_max == RLIM_INFINITY) {
            printf("Unlimited\n");
        } else {
            printf("%ld\n", (long) limit.rlim_max);
        }
    } else {
        perror("getrlimit error");
    }
}

int main() {
    print_limit(RLIMIT_CPU, "CPU time");
    print_limit(RLIMIT_FSIZE, "File size");
    print_limit(RLIMIT_DATA, "Data segment size");
    print_limit(RLIMIT_STACK, "Stack size");
    print_limit(RLIMIT_CORE, "Core file size");
    print_limit(RLIMIT_RSS, "Resident set size");
    print_limit(RLIMIT_NOFILE, "Open files");
    print_limit(RLIMIT_AS, "Address space");
    print_limit(RLIMIT_NPROC, "Processes");
    print_limit(RLIMIT_MEMLOCK, "Locked memory");
    print_limit(RLIMIT_LOCKS, "File locks");
    print_limit(RLIMIT_SIGPENDING, "Pending signals");
    print_limit(RLIMIT_MSGQUEUE, "Message queue size");
    print_limit(RLIMIT_NICE, "Nice value");
    print_limit(RLIMIT_RTPRIO, "Real-time priority");
    print_limit(RLIMIT_RTTIME, "Real-time timeout");

    return 0;
}

/*
$ ./a.out 
CPU time Soft limit: Unlimited | Hard limit: Unlimited
File size Soft limit: Unlimited | Hard limit: Unlimited
Data segment size Soft limit: Unlimited | Hard limit: Unlimited
Stack size Soft limit: 8388608 | Hard limit: Unlimited
Core file size Soft limit: 0 | Hard limit: Unlimited
Resident set size Soft limit: Unlimited | Hard limit: Unlimited
Open files Soft limit: 1048576 | Hard limit: 1048576
Address space Soft limit: Unlimited | Hard limit: Unlimited
Processes Soft limit: 30676 | Hard limit: 30676
Locked memory Soft limit: 1014304768 | Hard limit: 1014304768
File locks Soft limit: Unlimited | Hard limit: Unlimited
Pending signals Soft limit: 30676 | Hard limit: 30676
Message queue size Soft limit: 819200 | Hard limit: 819200
Nice value Soft limit: 0 | Hard limit: 0
Real-time priority Soft limit: 0 | Hard limit: 0
Real-time timeout Soft limit: Unlimited | Hard limit: Unlimited
*/