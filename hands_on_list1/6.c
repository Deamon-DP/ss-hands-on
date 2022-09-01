
/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
*/



#include <unistd.h> 
#include <stdio.h>  

void main()
{
    char *buffer[100];
    int output_buffer, input_buffer;
    while (1)
    {
        input_buffer = read(STDIN_FILENO, buffer, 1);
    	output_buffer = write(STDOUT_FILENO, buffer, 1);

        if (input_buffer == -1 || output_buffer == -1)
        {
            perror("Error while reading from STDIN / writing to STDOUT");
            break;
        }
    }
}
