/*
Name: Durga Prasad Reddy
Roll number : MT2022028

29. Write a program to remove the message queue.

*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
int main()
{
    struct msqid_ds *msg_ds;
    int msgid;
    printf("Enter ID of  MSG_QUEUE you want remove:: ");
    scanf("%d",&msgid);
    int ret ;
    ret = msgctl(msgid,IPC_RMID,msg_ds);
    
    if(ret == 0)
    {
        printf("MSG_QUEUE with ID %d is removed",msgid);
    }
    else
    {
        printf("There is no MSG_QUEUE with ID %d,Therefore please enter a valid ID",msgid);
    }

}