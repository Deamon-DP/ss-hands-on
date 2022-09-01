/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

15. Write a program to display the environmental variable of the user (use environ).
*/

#include <unistd.h>
#include <stdio.h>

int main()
{
    printf("\t\t\t\t\t===== PRINT ALL ENVIRONMENT VARIABLES ======\n\n");

    int i = 0;
    while (__environ[i] != NULL)
    {
        char *ptr = __environ[i];
        printf("%s\n", ptr);
        i++;
    }
}