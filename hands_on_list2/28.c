/*
Name: Durga Prasad Reddy
Roll number : MT2022028

28. Write a program to change the exiting message queue permission. (use msqid_ds structure)

*/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<stdio.h>
int main()
{
    struct msqid_ds *msg_ds;
    struct ipc_perm msg_per;
    int key=ftok("/home/dp/Desktop/Systemsoftware/hands_on_list2", 98);
    int msgid=msgget(key,IPC_CREAT|IPC_EXCL| 0777);
    if(msgid<0)
    {
        msgid=msgget(key,0);
    }
    msgctl(msgid,IPC_STAT,msg_ds);
    msg_per=msg_ds->msg_perm;
    printf("MSG UID of owner ::%d\nMSG GID of owner::%d\nMSG UID of creator::%d\nMSG GID of creator::%d\nMSG mode::%d\nMSG sequence number::%d\n",msg_per.uid,msg_per.gid,msg_per.cuid,msg_per.gid,msg_per.mode,msg_per.__seq);
    printf("Time of last sent msg:: %ld\nTime of last received msg::%ld\n",msg_ds->msg_stime,msg_ds->msg_rtime);
    printf("Time of last change in the MSG_QUEUE::%ld\n",msg_ds->msg_ctime);
    printf("MSG_QUEUE size::%ld",msg_ds->__msg_cbytes);
    printf("Number of msgs  in MSG_QUEUE::%ld",msg_ds->msg_qnum);
    printf("Maximum number of bytes allowed in this MSG_QUEUE::%ld\n",msg_ds->msg_qbytes);
    printf("PID of last msgsnd()::%d\nPID of last msgrcv():%d",msg_ds->msg_lspid,msg_ds->msg_lrpid);


}