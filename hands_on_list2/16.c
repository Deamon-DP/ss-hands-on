/*
Name: Durga Prasad Reddy
Roll number : MT2022028

16. Write a program to send and receive data from parent to child vice versa. Use two way
communication.
*/
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);
    char buffer1[4096], buffer2[4096];
    if (fork())
    {
        // parent writes to fd1 pipe and reads from fd2 pipe.
        close(fd1[0]);
        close(fd2[1]);

        printf("Enter the Msg which should be sent by parent:::");
        scanf("%[^\n]", buffer1);
        write(fd1[1], buffer1, sizeof(buffer1));
        //sleep(30);
        read(fd2[0], buffer2, sizeof(buffer2));
        printf("Msg received by Parent process::: %s\n", buffer2);
    }
    else
    {
        // child writes to fd2 pipe and reads from fd1 pipe.
        close(fd1[1]);
        //sleep(20);
        read(fd1[0], buffer1, sizeof(buffer1));
        printf("Msg received by Child process::: %s\n", buffer1);
        close(fd2[0]);
        sleep(1);
        printf("Enter the Msg which should be sent by Child:::");

        scanf("%[^\n]", buffer2);
        write(fd2[1], buffer2, sizeof(buffer2));
    }

    return 0;
}
