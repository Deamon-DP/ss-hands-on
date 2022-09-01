/*
Name:   B.Durga Prasad Reddy
Roll No:MT2022028

13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).

*/


#include <sys/select.h>
#include <stdio.h>
int main()
{
    struct timeval temp;
    temp.tv_sec = 10;
    fd_set read_fds;
    FD_ZERO(&read_fds);
    FD_SET(0, &read_fds);
    //struct timeval *var = &temp;

    if(select(1, &read_fds, NULL, NULL, &temp)!=-1)
    {if(FD_ISSET(0,&read_fds)){
			printf("input available on stdin\n");

		}
		else{
			printf("no input on stdin after %d secs.\n",10);
			
		}
	}
	else{
		printf("select call error!\n");
	}

    
}