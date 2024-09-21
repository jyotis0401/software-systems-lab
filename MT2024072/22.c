/*
Name: 22.c
Author: MT2024072
Description: Program to wait for data to be written into FIFO within 10 seconds, use select system call with FIFO.
Date: 19 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
int main(){
    struct timeval t;
    fd_set readfds;
    int fd = open("myfifo",O_RDWR|O_CREAT);

    const int msg_size = 100;
    char msg[msg_size];
    fflush(stdout);

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);
    t.tv_sec = 10;
    t.tv_usec = 0;

    if(!select(fd+1, &readfds, NULL, NULL, &t)){
        printf("User didn't enter anything!\n");
    }
    else{
        read(fd,msg,msg_size);
        printf("Message: %s",msg);
    }
    return (0);
}
//Run this program, then within ten seconds on another terminal run the command -echo "Hello, world!" > myfifo and check the output of this program