/*
Name: 20b.c
Author: MT2024072
Description: Two programs so that both can communicate by FIFO -Use one way communication. (ii)
Date: 19  sep 2024
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    int fd=open("20fifo",O_RDONLY);
    char buff[10];
    read(fd,buff,sizeof(buff));
    printf("%s\n",buff);
    close(fd);
    return 0;
}