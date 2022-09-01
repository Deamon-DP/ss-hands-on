/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

27. Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp

*/

#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
int main(void)
{
    char *path = "/usr/bin/ls";
    char *arg1 = "-Rl";
    char *arg2 = ".";

    printf("===============  OUTPUT using EXECLE with  %s\t'%s'  as arguments   =================\n", arg1, arg2);
    execl(path, path, arg1, arg2, NULL, NULL);
    perror("execl:");
    return 0;
}