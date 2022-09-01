
/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

25. Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

*/

#include <unistd.h>  
#include <sys/types.h> 
#include <sys/wait.h>  
#include <stdio.h>    

void main()
{
    pid_t child1, child2, child3;

    if ((child1 = fork()))
    {  
        if ((child2 = fork()) )
        {
             if ((child3 = fork()))
            {
                

                int wstatus;
                  int   w = waitpid(child3, &wstatus, WUNTRACED | WCONTINUED);
                   if (w == -1) {
                       perror("waitpid");
                   }

                   if (WIFEXITED(wstatus)) {
                       printf("exited, status=%d\n", WEXITSTATUS(wstatus));
                   } else if (WIFSIGNALED(wstatus)) {
                       printf("killed by signal %d\n", WTERMSIG(wstatus));
                   } else if (WIFSTOPPED(wstatus)) {
                       printf("stopped by signal %d\n", WSTOPSIG(wstatus));
                   } else if (WIFCONTINUED(wstatus)) {
                       printf("continued\n");
                   }
               
            }
            else
            {
                printf("Child 3 created...\n");
                printf("Putting child 3 to sleep for 15 sec\n");
                sleep(15);
                printf("Child 3 is now awake!\n");
                _exit(0);
            }
           
        }
        else
        { 
            printf("Child 2 created...\n");
            printf("Putting child 2 to sleep for 10 sec\n");
            sleep(10);
            printf("Child 2 is now awake!\n");
            _exit(0);

           
        }
       
    }
    else
    {
        printf("Child 1 created...\n");
        printf("Putting child 1 to sleep for 5 sec\n");
        sleep(5);
        printf("Child 1 is now awake!\n");
        _exit(0);
      
    }
}