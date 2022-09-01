/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028



12. Write a program to find out the opening mode of a file. Use fcntl.
*/


#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("file.txt", O_RDWR, 0777);
    int val = fcntl(fd, F_GETFL, 0);

    switch (val & O_ACCMODE)
    {
    case O_RDONLY:
        printf("read only");
        break;
    case O_WRONLY:
        printf("write only");
        break;
    case O_RDWR:
        printf("read write");
        break;
    default:
        printf("unknown access mode");
        break;
    }
}
