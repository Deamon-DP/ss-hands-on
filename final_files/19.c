/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

19. Write a program to find out time taken to execute getpid system call. Use time stamp counter.
*/

#include <sys/time.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

unsigned long long rdtsc()
{
    unsigned long long dst;
    __asm__ __volatile__("rdtsc"
                         : "=A"(dst));

    return dst;
}
int main(void)
{
    long long int start, end;
    start = rdtsc();
    int id = getpid();
    end = rdtsc();

    printf("The time required to execute the getpid:%llu\n", end-start);
}