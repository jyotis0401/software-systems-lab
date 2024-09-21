/*
Name: 16.c
Author: MT2024072
Description: Program to send and receive data from parent to child vice versa. Using two way communication.
Date: 16 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define BUFFER_SIZE 25 

int main(){
    int fd1[2],fd2[2];
    pid_t pid;
    char buffer1[BUFFER_SIZE];
    char buffer2[BUFFER_SIZE];
    pipe(fd1);
    pipe(fd2);
    pid=fork();
    if(pid==0){
        //Child process
        close(fd2[0]);
        close(fd1[1]);
        sprintf(buffer2, "Hello, parent!");
        write(fd2[1], buffer2, BUFFER_SIZE);
        read(fd1[0], buffer1, BUFFER_SIZE);
        printf("Child received message: %s\n", buffer1);
        close(fd2[1]);
        close(fd1[0]);
    }
    else{
        close(fd2[1]);
        close(fd1[0]);
        sprintf(buffer1, "Hello, child!");
        write(fd1[1], buffer1, BUFFER_SIZE);
        read(fd2[0], buffer2, BUFFER_SIZE);
        printf("Parent received message: %s\n", buffer2);
        close(fd2[0]);
        close(fd1[1]);
    }
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 16.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Child received message: Hello, child!
Parent received message: Hello, parent!
*/