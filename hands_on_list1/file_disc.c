       #include <sys/types.h>
       #include <sys/stat.h>
       #include <fcntl.h>
       #include<stdio.h>
int main()
{
int fd=open("file.txt",O_RDWR,0777);
printf("%d",fd);
while(1);
}
