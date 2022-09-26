/*
Name: Durga Prasad Reddy
Roll number : MT2022028


18. Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.

*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
     int fd1[2];
     int fd2[2];
     pipe(fd1);
     pipe(fd2);
     if (!fork())
     {
          char *path = "/usr/bin/ls";
          char *arg[] = {"/usr/bin/ls", "-l", ".", NULL};
          close(fd2[0]);
          close(fd2[1]);
          close(fd1[0]);
          dup2(fd1[1],1);
          execv(path, arg);
          perror("execv ls -l:");
     }
     else
     {
        if(!fork())
        {
            char *path = "/usr/bin/grep";
          char *arg[] = {"/usr/bin/grep", "^d", NULL};
          close(fd1[1]);
          close(fd2[0]);
          dup2(fd1[0],0);
          dup2(fd2[1],1);
          execv(path, arg);
          perror("execv grep:");
        }
        else
        {
          char *path = "/usr/bin/wc";
          char *arg[] = {"/usr/bin/wc",NULL};
          //close(0);
          close(fd2[1]);
          close(fd1[0]);
          close(fd1[1]);
          dup2(fd2[0],0);
          execv(path,arg);
          perror("Execv wc:");
        }
     }
}
