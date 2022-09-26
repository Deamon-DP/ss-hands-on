/*
Name: Durga Prasad Reddy
Roll number : MT2022028



23. Write a program to print the maximum number of files can be opened within a process and
size of a pipe (circular buffer).
*/
#include<stdio.h>
#include<unistd.h>
int main()
{
    long max_files,max_pipe_size;
    max_pipe_size=pathconf(".",_PC_PIPE_BUF);
    max_files=sysconf(_SC_OPEN_MAX);
printf("Maximum number of files can be opened within a process at any point of time:%ld\n Size of the pipe is %ld\n  ",max_files,max_pipe_size);

}