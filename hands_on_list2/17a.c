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
          dup(fd[1]);
          execv(path, arg);
          perror("execv:");
     }
     else
     {
          char *path = "/usr/bin/wc";
          char *arg[] = {"/usr/bin/wc",NULL};
          close(0);
          close(fd[1]);
          dup(fd[0]);
          execv(path,arg);
          perror("execv:");
     }
}
