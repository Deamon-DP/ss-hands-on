/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

21. Write a program, call fork and print the parent and child process id.
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    int i;
    if (i = fork())
    {
        printf("\nParent Process ID:%d\n", getpid());
    }
    else
    {
        printf("\nChild Process ID:%d\n", getpid());
    }
}