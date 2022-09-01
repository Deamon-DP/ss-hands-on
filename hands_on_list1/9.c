

/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change


*/


#include <sys/types.h> 
#include <sys/stat.h>  
#include <unistd.h>    
#include <stdio.h>     
#include <time.h>      

void main(int argc, char *argv[])
{
    char *filename;
    int fd;

    struct stat buffer;
    if (argc != 2)
        printf("Pass the file name as the argument!\n");
    else
    {
        filename = argv[1];
        fd = stat(filename, &buffer);

        if (fd == -1)
            perror("Error while executing the file!");
        else
        {
            printf("Inode number -> %ld\n", buffer.st_ino);
            printf("Number of hardlinks -> %ld\n", buffer.st_nlink);
            printf("UID -> %d\n", buffer.st_uid);
            printf("GID -> %d\n", buffer.st_gid);
            printf("Size -> %ld\n", buffer.st_size);
            printf("Block Size -> %ld\n", buffer.st_blksize);
            printf("Number of Blocks -> %ld\n", buffer.st_blocks);
            printf("Time of last access -> %s", ctime(&buffer.st_atim.tv_sec));
            printf("Time of last modification -> %s", ctime(&buffer.st_mtim.tv_sec));
            printf("Time of last change -> %s", ctime(&buffer.st_ctim.tv_sec));
        }
    }
}
