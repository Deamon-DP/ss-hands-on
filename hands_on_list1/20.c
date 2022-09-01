/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028


20. Find out the priority of your running program. Modify the priority with nice command.
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include<sys/resource.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(void)
{
    int pid=getpid();
    printf("pid=%d\n", pid);
    int prior=getpriority(PRIO_PROCESS,pid);
    printf("The priority of the process is %d\n",prior);

    chdir("/");
    umask(0);
    nice(-20);
    perror("nice");
    int prio=getpriority(PRIO_PROCESS,pid);
    printf("The priority of the process after modification is %d\n",prio);

    getchar();
}