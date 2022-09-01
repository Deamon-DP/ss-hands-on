
/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

22. Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.


*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
int main(void)
{
    int fd = open("file.txt", O_RDWR );
    if (fork())
    {
        char * par="This msg is written by Parent Process\n";
        write(fd,par,strlen(par));

    }
    else
    {
        char * par="This msg is written by Child Process";
        write(fd,par,strlen(par));

    }
}