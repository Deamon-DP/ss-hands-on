/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.

*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int fd = open("file.txt", O_RDWR);
    char *integers = "1234567890";
    write(fd, integers, 10);
    lseek(fd, 10, SEEK_CUR);
    char *alphabets = "abcdefghij";
    write(fd, alphabets, 10);
    int pointer = lseek(fd, 0, SEEK_CUR);
    printf("The pointer now is at:%d\n", pointer);
    close(fd);
}
