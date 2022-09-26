/*
Name: Durga Prasad Reddy
Roll number : MT2022028

27. Write a program to receive messages from the message queue.
a. with 0 as a flag
b. with IPC_NOWAIT as a flag

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
    long type;
    printf("enter the msg type::");
    scanf("%ld",&type);
    



    int key=ftok("/home/dp/Desktop/Systemsoftware/hands_on_list2", 18);
      int  msgid=msgget(key,0);
    
    msgrcv(msgid,&dpmsg,sizeof(dpmsg.message),type,0);
    printf("MSG recived :: %s",dpmsg.message);

}