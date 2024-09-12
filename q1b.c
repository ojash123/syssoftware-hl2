/*
MT2024105
Ojas Hegde
1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>

int main(){
    struct timeval tv_value, tv_interval;
    tv_value.tv_sec = 10;
    tv_value.tv_usec = 10;
    tv_interval.tv_sec = 0;
    tv_interval.tv_usec = 0;
    struct itimerval itv;
    itv.it_value = tv_value;
    itv.it_interval = tv_interval;

    if (setitimer(ITIMER_VIRTUAL, &itv, NULL) == -1)
    {
        perror("set itimer error");
    }
    printf("Sleeping for 15 secs\n");
    sleep(15);
    getitimer(ITIMER_VIRTUAL, &itv);
    printf("%ld secs and %ld usecs left\nEntering infinite loop\n", itv.it_value.tv_sec, itv.it_value.tv_usec);
    while(1); // could use wait instead

}

/* Doesn't wake up during sleep as virtual clock only ticks down while process is executing
$ ./a.out 
Sleeping for 15 secs
10 secs and 1010 usecs left
Entering infinite loop 
Virtual timer expired
*/