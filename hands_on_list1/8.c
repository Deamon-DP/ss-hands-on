/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028


8. Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.

*/



#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFF 1
int main()

{
       int fd1 = open("8.c", O_RDONLY, 0777);
       int fd2 = open("file8.txt", O_WRONLY, 0777);
       int buff[BUFF];
       int n;
       while ((n = read(fd1, buff, BUFF)) > 0)
              write(fd2, buff, n);
        close(fd1);
        close(fd2);
       return 0;
}