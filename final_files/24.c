/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028
24. Write a program to create an orphan process.
*/
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>
void main()
{

    if(fork()==0)
    {
        printf("parent process id of child:%d \n",(int)getppid());
        printf("send child to sleep for 5 sec\n");
        sleep(5);
        printf("parent process id of child:%d  \n",(int)getppid());
    }    
    else 
    {
        printf("process id of the parent%d\n",(int)getpid());
        printf("exit from parent process\n");
        exit(0);
    }
}
