/*
Name: Durga Prasad Reddy
Roll number : MT2022028

6. Write a simple program to create three threads.
*/

#include<stdio.h>
#include<pthread.h>

void *  thread_routine()
{
    printf("A new thread is created with id::%lu\n",pthread_self());

}

int main()
{
    pthread_t one,two,three;
    pthread_create(&one,NULL,thread_routine,NULL);
    pthread_create(&two,NULL,thread_routine,NULL);
    pthread_create(&three,NULL,thread_routine,NULL);

    pthread_exit(NULL);
}
