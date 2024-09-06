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

    if (setitimer(ITIMER_REAL, &itv, NULL) == -1)
    {
        perror("set itimer error");
    }
    printf("Sleeping for 15 secs\n");
    sleep(15);
}

/*
$ ./a.out
Sleeping for 15 secs
Alarm clock
*/