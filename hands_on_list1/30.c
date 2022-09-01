/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028
30. Write a program to run a script at a specific time using a Daemon process.
*/
#include <time.h>      
#include <stdio.h>     
#include <stdlib.h>    
#include <sys/types.h> 
#include <unistd.h>    
#include <sys/stat.h>  


void main(int argc, char *argv[])
{

    time_t currentTime, givenTime; 
    struct tm *deadline;

    int child;

    if (argc < 2)
        printf("Pass at least one argument\n");
    else
    {
        time(&currentTime); 
        deadline = localtime(&currentTime);

        deadline->tm_hour = atoi(argv[1]);
        deadline->tm_min = argv[2] == NULL ? 0 : atoi(argv[2]);
        deadline->tm_sec = argv[3] == NULL ? 0 : atoi(argv[3]);

        givenTime = mktime(deadline); 
        if ((child = fork()) == 0)
        {
            setsid();
            chdir("/");
            umask(0);
            do
            {
                time(&currentTime);

            } while (difftime(givenTime, currentTime) > 0);
            
            printf("DONE\n");
            exit(0);
        }
        exit(0);
    }
}
