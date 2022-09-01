/*===========================================================================================================================
	Name: Battula Jashwanth Sai
	Roll: MT2022029

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

char *tf = "path/to/file";

int isLocked(int fd);

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("expected 1 argument but got %d", argc - 1);
        exit(1);
    }

    int fd = open(tf, O_CREAT | O_WRONLY);

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

    lock.l_type = F_WRLCK;
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

    char const *ticketNumber = argv[1];

    ret = write(fd, ticketNumber, strlen(ticketNumber));

    if (ret == -1)
    {
        close(fd);
        perror("write");
        exit(1);
    }

    printf("Ticket number written successfully!\n");

    lock.l_type = F_UNLCK;
    ret = fcntl(fd, F_SETLK, &lock);

    if (ret == -1)
    {
        close(fd);
        perror("fcntl");
        exit(1);
    }

    close(fd);

    return 0;
}

int isLocked(int fd)
{
    struct flock l;

    l.l_type = F_WRLCK;
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
