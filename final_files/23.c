/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028
23. Write a program to create a Zombie state of the running program.

*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/wait.h>
int main()
{
    if (!fork())
    {
        printf("In child - PID = %d\n", getpid());
    }
    else
    {
        printf("This is parent process %d\n", getpid());
        sleep(30);
        wait(0);
    }
}