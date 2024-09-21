/*
Name: 20a.c
Author: MT2024072
Description: Two programs so that both can communicate by FIFO -Use one way communication. (i)
Date: 17 sep 2024
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
int main(){
    int status;
    status = mkfifo("20fifo",0666);
    int fd=open("20fifo",O_WRONLY);
    write(fd,"Hello!",sizeof("Hello!"));
    close(fd);
    return 0;
    //First run 20b.c on one terminal and then run 20a.c on other, only then 20a.c will work because it needs some reader to be active.
}