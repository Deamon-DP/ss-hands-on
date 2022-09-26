/*
Name: Durga Prasad Reddy
Roll number : MT2022028



24. Write a program to create a message queue and print the key and message queue id.
*/

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
int main()
{
    int key=ftok("/home/dp/Desktop/Systemsoftware/hands_on_list2", 32);
    int msgid=msgget(key,IPC_CREAT|IPC_EXCL| 0777);
    if(msgid<0)
    {
        printf("msg queue with key value %d already exists",key);
        return 0;
    }
    printf("KEY:%d\nMESSAGE QUEUE ID:%d\n",key,msgid);
}
