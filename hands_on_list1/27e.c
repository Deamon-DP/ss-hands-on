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
    char *arg[] = {"/usr/bin/ls", "-Rl", ".", NULL};

    printf("===============  OUTPUT using EXECVP with  %s\t'%s'    as arguments   =================\n", arg[1], arg[2]);
    execv(path, arg);
    perror("execvp:");
    return 0;
}