
/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

5. Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
*/
#include <sys/types.h> 
#include <sys/stat.h>  
#include <fcntl.h>  
#include<stdio.h>   

void main()
{
    printf("files are created in 'files' folder\n");
    while (1)
    {
        creat("./files/file_1", O_CREAT);
        creat("./files/file_2", O_CREAT);
        creat("./files/file_3", O_CREAT);
        creat("./files/file_4", O_CREAT);
        creat("./files/file_5", O_CREAT);
    }
}