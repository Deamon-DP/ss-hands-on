/*
Name: Durga Prasad Reddy
Roll number : MT2022028



20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include<stdio.h>
int main()
{
        printf("Enter The msg to be sent ::: ");
   char buffer[80];
    scanf("%[^\n]",buffer);
    mknod("fifo20",S_IFIFO | 0777,0);
    int fd=open("fifo20",O_WRONLY);
 

    write(fd,buffer,sizeof(buffer));
    printf("%d",fd);
    perror("write");
    close(fd);


}
