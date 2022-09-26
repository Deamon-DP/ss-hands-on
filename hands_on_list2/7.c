/*
Name: Durga Prasad Reddy
Roll number : MT2022028

7. Write a simple program to print the created thread ids.
*/

#include<stdio.h>
#include<pthread.h>

void *  thread_routine()
{
    printf("A new thread is created with id::%lu\n",pthread_self());

}

int main()
{
    pthread_t one;
    pthread_create(&one,NULL,thread_routine,NULL);


    pthread_exit(NULL);
}
