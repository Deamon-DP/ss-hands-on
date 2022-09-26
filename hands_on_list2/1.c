/*
Name: Durga Prasad Reddy
Roll number : MT2022028

1. Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
a. ITIMER_REAL
b. ITIMER_VIRTUAL
c. ITIMER_PROF
*/
#include <sys/time.h>
#include <stdio.h>
int main()
{
       struct itimerval interval, ret;
       interval.it_interval.tv_sec = 10;
       interval.it_interval.tv_usec = 10;
       setitimer(ITIMER_REAL, &interval, 0);
       int time_status = getitimer(ITIMER_REAL, &ret);
       perror("g");
       printf("the new time interval is %ld", ret.it_interval.tv_sec);
}