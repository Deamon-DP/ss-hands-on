/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028



1. Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)




shell command for hard link:  "ln 30.c hrd"
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    printf("A hard link is created for a file 30.c named hrd/n");
    link("30.c", "hrd");
    perror("hrd link :");
}
