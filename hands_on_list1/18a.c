/*=======================================================================================================================
	Name:   B.Durga Prasad Reddy
Roll No:MT2022028

   Write a program to perform Record locking.
     a. Implement write lock
     b. Implement read lock

  Create three records in a file. Whenever you access a particular record, first lock it then modify/access
  to avoid race condition.
========================================================================================================================*/

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include "./18_record.h"

int main(void)
{
    int fd = open(RECORD_FILE, O_CREAT | O_WRONLY);

    if (fd == -1)
    {
        close(fd);
        perror("open");
        exit(1);
    }

    struct flock lock;

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    int ret = fcntl(fd, F_SETLKW, &lock);

    if (ret == -1)
    {
        close(fd);
        perror("fcntl");
        exit(1);
    }

    struct record records[3];

    for (int i = 0; i < 3; i++)
    {
        records[i].record_num = i + 1;
        records[i].data = i * i;
    }

    ret = write(fd, records, sizeof(struct record) * 3);

    if (ret == -1)
    {
        close(fd);
        perror("write");
        exit(1);
    }

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
