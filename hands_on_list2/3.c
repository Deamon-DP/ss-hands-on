/*

Name: Durga Prasad Reddy
Roll number : MT2022028

3. Write a program to set (any one) system resource limit. Use setrlimit system call.

*/
#include <sys/time.h>
#include <sys/resource.h>
#include <stdio.h>
#include<stdlib.h>
int main()
{
    struct rlimit limit;
    getrlimit(RLIMIT_CPU, &limit);
    printf("system cpu soft limit is %ld\n", limit.rlim_cur);
    printf("system cpu hard limit is %ld\n", limit.rlim_max);
     getrlimit(RLIMIT_CPU, &limit);
    printf("system cpu soft limit is %ld\n", limit.rlim_cur);
    printf("system cpu hard limit is %ld\n", limit.rlim_max);

}