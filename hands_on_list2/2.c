/*
Name: Durga Prasad Reddy
Roll number : MT2022028

2. Write a program to print the system resource limits. Use getrlimit system call.
*/
#include <sys/time.h>
#include <sys/resource.h>
#include<stdio.h>
int main()
{
       struct rlimit limit;
    getrlimit(RLIMIT_NOFILE, &limit);
    printf("Maximum file descriptor number that can be opened by this process soft limit is %ld\n", limit.rlim_cur);
    printf("Maximum file descriptor number that can be opened by this process qhard limit is %ld\n", limit.rlim_max);


}