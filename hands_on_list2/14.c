/*
Name: Durga Prasad Reddy
Roll number : MT2022028

14. Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor.

*/
#include <unistd.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    int temp, fd[2];
    temp = pipe(fd);
    printf("pipe system call returns:%d\n", temp);
    char *stri = "Water is passing through the pipe",buf[80];
    int msg = write(fd[1], stri, strlen(stri));

    read(fd[0], buf, msg);
    printf("msg entered and read from pipe is :::%s\n", buf);
}