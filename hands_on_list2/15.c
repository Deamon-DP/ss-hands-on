/*
Name: Durga Prasad Reddy
Roll number : MT2022028

15. Write a simple program to send some data from parent to the child process.

*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    char buffer[4096];
    int ipc, fd[2];
    ipc = pipe(fd);
    if (!fork())
    {
        close(fd[1]);
        read(fd[0], buffer, sizeof(buffer));
        printf("Msg received by child ::: %s\n", buffer);
    }
    else
    {
        close(fd[0]);
        printf("Enter the msg to send:");
        scanf("%[^\n]", buffer);
        write(fd[1], buffer, sizeof(buffer));
    }
    // wait(0);
}
