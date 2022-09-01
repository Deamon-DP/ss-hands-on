/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028



1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)




shell command for soft link:  "ln -s 30.c sftlnk"
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("A soft link is created for a file 30.c named sftlnk/n");
    symlink("30.c", "sftlnk2");
    perror("soft link :");
}
