/*
Name: Durga Prasad Reddy
Roll number : MT2022028



20. Write two programs so that both can communicate by FIFO -Use one way communication.
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int fd = open("fifo20", O_RDONLY);
    if (fd < 0)
    {
        perror("open");
        return 0;
    }
    char buffer[80];
    printf("%d", fd);
    read(fd, buffer, sizeof(buffer));
    close(fd);
    printf("msg received is :: %s", buffer);
}