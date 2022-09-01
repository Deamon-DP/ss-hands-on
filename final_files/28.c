/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028


28. Write a program to get maximum and minimum real time priority.
*/
#include <sched.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("The maximum real time priority for RR scheduling  is %d\n", sched_get_priority_max(SCHED_RR));
    printf("The minimum real time priority for RR Sscheduling is %d\n", sched_get_priority_min(SCHED_RR));
    printf("The maximum real time priority for FIFO scheduling  is %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("The minimum real time priority for FIFO Sscheduling is %d\n", sched_get_priority_min(SCHED_FIFO));
}