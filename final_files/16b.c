#include <stdio.h>
/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

29. Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
*/

#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
struct flock lock;

// int log_reg(int fd, int cmd, int type, off_t offset, int whence, off_t len)
// {

//     lock.l_type = type;
//     lock.l_start = offset;
//     lock.l_whence = whence;
//     lock.l_len = len;
//     fcntl(fd, cmd, &lock);
// }
// int unlock(int fd, int cmd)
// {
//     lock.l_type = F_UNLCK;
//     fcntl(fd, cmd, &lock);
// }
// int print_pid()
// {
//     printf("the pid of process having lock on this file is %d\n", lock.l_pid);
// }

int main()
{
    printf("The pid of this Process :%d\n", getpid());
    int fd = open("file2.txt", O_WRONLY);
    // log_reg(fd, F_SETLKW, F_RDLCK, SEEK_SET, SEEK_SET, 0);
    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_start = SEEK_SET;
    lock.l_whence = SEEK_SET;
    lock.l_len = 0;
    fcntl(fd, F_SETLKW, &lock);
    printf("the pid of process having lock on this file is %d\n", lock.l_pid);

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    // print_pid();
    // unlock(fd, F_UNLCK);
}