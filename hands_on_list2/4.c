/*
Name: Durga Prasad Reddy
Roll number : MT2022028

4. Write a program to measure how much time is taken to execute 100 getppid ( )
system call. Use time stamp counter.

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
    int i=0;
    while(i<100)
    {
        int id = getppid();
        i++;
    }
    end = rdtsc();

    printf("The time required to execute the getppid 100 times is::%llu\n", end-start);
}