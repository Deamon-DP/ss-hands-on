/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

11. Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd = open("file.txt", O_RDWR);
    int new_fd = dup2(fd, 10);
    char *c = "abcdefgh";
    write(fd, c, 8);
    write(new_fd, c, 8);
    close(fd);
    close(new_fd);
}
