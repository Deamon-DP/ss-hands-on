/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028


4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include<unistd.h>
int main()
{
       int file_discriptor;
       file_discriptor = open("file.txt", O_EXCL, S_IRUSR | S_IWUSR);
       printf("file discriptor value is %d", file_discriptor);
       close(file_discriptor);

}
