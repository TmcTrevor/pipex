#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
   close (3);
    int fd = open("tricky.txt",O_RDWR | O_CREAT);
    int fd2 = open("tricky4.txt",O_RDWR | O_CREAT);
    printf("fd = %d\n fd2 = %d",fd,fd2);
    dup2(fd,4);
    write(4,"test",4);
    write(4,"test1",4);
    close (fd);
    close(fd2);
}