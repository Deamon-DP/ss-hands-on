/*
Name: Durga Prasad Reddy
Roll number : MT2022028


5. Write a program to print the system limitation of
a. maximum length of the arguments to the exec family of functions.
b. maximum number of simultaneous process per user id.
c. number of clock ticks (jiffy) per second.
d. maximum number of open files
e. size of a page
f. total number of pages in the physical memory
g. number of currently available pages in the physical memory.


*/

#include <unistd.h>
#include <stdio.h>
#include <limits.h>
int main()
{
    long result;
    printf("a. maximum length of the arguments to the exec family of functions.::%ld\n",sysconf(_SC_ARG_MAX));
    printf("b. maximum number of simultaneous process per user id::%ld\n",sysconf(_SC_CHILD_MAX));
    printf("c. number of clock ticks (jiffy) per second::%ld\n",sysconf(_SC_CLK_TCK));
    printf("d. maximum number of open files::%ld\n",sysconf(_SC_OPEN_MAX));
    printf("e. size of a page::%ld\n",sysconf(_SC_PAGE_SIZE));
    printf("f. total number of pages in the physical memory::%ld\n",sysconf(_SC_PHYS_PAGES));
    printf("g. number of currently available pages in the physical memory::%ld\n",sysconf(_SC_AVPHYS_PAGES));

}