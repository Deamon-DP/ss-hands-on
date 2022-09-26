/*
Name: Durga Prasad Reddy
Roll number : MT2022028

30. Write a program to create a shared memory.
a. write some data to the shared memory
b. attach with O_RDONLY and check whether you are able to overwrite.
c. detach the shared memory
d. remove the shared memory
*/
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>

int main()
{
    int key= ftok("/home/dp/Desktop/Systemsoftware/hands_on_list2",2);
    int shmid= shmget(key,1024,IPC_CREAT | 0777);
    char * address=shmat(shmid,0,SHM_RDONLY);

    sprintf(address,"overwrite");
    perror("ksad");
    printf("%s",address);
    shmdt(&address);
    shmctl(shmid,IPC_RMID,NULL);
    return 0;
}