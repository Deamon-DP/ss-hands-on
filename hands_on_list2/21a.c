/*
Name: Durga Prasad Reddy
Roll number : MT2022028


21. Write two programs so that both can communicate by FIFO -Use two way communications.

*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Enter The msg to be sent from process 21a ::: ");
    char buffer1[80],buffer2[80];
    scanf("%[^\n]", buffer1);

    int fd1= open("fifo21a", O_WRONLY);
    write(fd1, buffer1, sizeof(buffer1));
    perror("write");
    
    int fd2=open("fifo21b",O_RDONLY);
        printf("waiting for process 21b to send msg......\n");

    read(fd2,buffer2,sizeof(buffer2));
    printf("msg received from process 21b is :: %s\n", buffer2);

    close(fd1);
    close(fd2);
}