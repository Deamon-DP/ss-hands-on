/*
Name: Durga Prasad Reddy
Roll number : MT2022028

26. Write a program to send messages to the message queue. Check $ipcs -q
*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
int main()
{
    struct stmsg{
        long  mtype;
        char message[512];
    }dpmsg;


    printf("Enter the message type::");
    scanf("%ld",&dpmsg.mtype);


    printf("Enter the MSG to be sent::");
    scanf("%s",dpmsg.message);


    int key=ftok("/home/dp/Desktop/Systemsoftware/hands_on_list2", 18);
    int msgid=msgget(key,IPC_CREAT|IPC_EXCL| 0777);
    if(msgid<0)
    {
        msgid=msgget(key,0);
    }
    msgsnd(msgid,&dpmsg,sizeof(dpmsg.message),0);
}
