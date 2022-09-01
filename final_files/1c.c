/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028



1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)




shell command for FIFO:  "mkfifo fifo1"
*/

#include <sys/types.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    mknod("fifo1", S_IRUSR | S_IWUSR | S_IFIFO, 0);
    perror("fifo:");
    return 0;
}
