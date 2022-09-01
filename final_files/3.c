/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

3. Write a program to create a file and print the file descriptor value. Use creat ( ) system call
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<unistd.h>
#include <stdio.h>
int main()
{
      int file_discriptor;
      file_discriptor = open("file.txt", O_CREAT);
      printf("file discriptor value is %d", file_discriptor);
      close(file_discriptor);
}
