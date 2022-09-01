/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028
26. Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)


*/
#include <unistd.h>    
#include <sys/types.h> 
#include <stdio.h>     


int main(void) {
  char *path = "./9";
  char *arg1 = "./9.c";
  char *arg2 =NULL;
   printf("executing  9th program using exec with  %s as argument\n",arg1); 
  execl(path, path, arg1, arg2, NULL);
 perror("ececl:");
  return 0;
}
