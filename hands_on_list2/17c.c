/*
Name: Durga Prasad Reddy
Roll number : MT2022028

17. Write a program to execute ls -l | wc.
a. use dup
b. use dup2
c. use fcntl
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main()
{
    int fd[2];
    pipe(fd);
    if (!fork())
    {
        char *path = "/usr/bin/ls";
        char *arg[] = {"/usr/bin/ls", "-l", ".", NULL};
        close(1);
        close(fd[0]);
        fcntl(fd[1], F_DUPFD, 1);

        execv(path, arg);
        perror("execv ls -l:");
    }
    else
    {
        char *path = "/usr/bin/wc";
        char *arg[] = {"/usr/bin/wc", NULL};
        close(0);
        close(fd[1]);
        fcntl(fd[0], F_DUPFD, 0);
        execv(path, arg);
        perror("Execv wc:");
    }
}