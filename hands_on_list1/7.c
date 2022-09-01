/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

7. Write a program to copy file1 into file2 ($cp file1 file2).                                                                       
*/

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFF 4096
int main()

{
       int fd1 = open("file.txt", O_RDONLY, 0777);
       int fd2 = open("file2.txt", O_WRONLY, 0777);
       int buff[BUFF];
       int n;
       while ((n = read(fd1, buff, BUFF)) > 0)
              write(fd2, buff, n);
       close(fd1);
       close(fd2);
       return 0;
}
