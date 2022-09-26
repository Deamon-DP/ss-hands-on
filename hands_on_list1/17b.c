/*===========================================================================================================================
	Name:   B.Durga Prasad Reddy
Roll No:MT2022028

    Write a program to simulate online ticket reservation. Implement write lock
	Write a program to open a file, store a ticket number and exit. Write a separate program, to
	open the file, implement write lock, read the ticket number, increment the number and print
	the new ticket number then close the file.

============================================================================================================================*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *tf = "./ticket.txt";

int isLocked(int fd);

int main(int argc, char const *argv[])
{
    int fd = open(tf, O_RDONLY);

    if (fd == -1)
    {
        close(fd);
        perror("open");
        exit(1);
    }

    if (isLocked(fd))
    {
        printf("The file is already locked for reading or writing :(");
        exit(1);
    }

    struct flock lock;

    lock.l_type = F_RDLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int ret = fcntl(fd, F_SETLK, &lock);

    if (ret == -1)
    {
        close(fd);
        perror("fcntl");
        exit(1);
    }

    char buff[4];

    ret = read(fd, buff, 3);

    if (ret == -1)
    {
        close(fd);
        perror("read");
        exit(1);
    }

    buff[3] = '\0';
    int dp = atoi(buff);
    printf("ticket number before increment:%d\n",dp);
    dp++;


    printf("Ticket number after increment: %d\n", dp);
    close(fd);

    return 0;
}

int isLocked(int fd)
{
    struct flock l;

    l.l_type = F_RDLCK;
    l.l_whence = SEEK_SET;
    l.l_start = 0;
    l.l_len = 0;
    l.l_pid = getpid();

    int ret = fcntl(fd, F_GETLK, &l);

    if (ret == -1)
    {
        close(fd);
        perror("fcntl");
        exit(1);
    }

    if (l.l_type == F_RDLCK || l.l_type == F_WRLCK)
        return 1;

    return 0;
}

