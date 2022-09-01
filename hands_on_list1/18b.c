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
    int fd = open(RECORD_FILE, O_RDONLY);

    if (fd == -1)
    {
        close(fd);
        perror("open");
        exit(1);
    }

    size_t length = sizeof(struct record);

    struct flock lock;
    struct record rec;
    int ret;

    for (int i = 0; i < 3; i++)
    {
        lock.l_type = F_RDLCK;
        lock.l_whence = SEEK_SET;
        lock.l_start = SEEK_CUR;
        lock.l_len = length;
        lock.l_pid = getpid();

        ret = fcntl(fd, F_SETLKW, &lock);

        if (ret == -1)
        {
            close(fd);
            perror("fcntl");
            exit(1);
        }

        ret = read(fd, &rec, length);

        printf("Record number: %d\n", rec.record_num);
        printf("Data: %d\n", rec.data);

        lock.l_type = F_UNLCK;
        ret = fcntl(fd, F_SETLK, &lock);

        if (ret == -1)
        {
            close(fd);
            perror("fcntl");
            exit(1);
        }
    }

    close(fd);

    return 0;
}
