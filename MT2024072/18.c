/*
Name: 18.c
Author: MT2024072
Description: Program to find out total number of directories on the pwd execute ls -l | grep ^d | wc Using only dup2.
Date: 18 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
    int fd1[2],fd2[2];
    pipe(fd1);
    pipe(fd2);
    
    if(!fork()){
        dup2(fd1[1],1);
        close(fd1[0]);
        close(fd2[1]);
        close(fd2[0]);
        execlp("ls","ls","-Rl",NULL);
    }
    else{
        if(!fork()){
            dup2(fd1[0],0);
            dup2(fd2[1],1);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep","grep","^d",NULL);
        }
        else{
            dup2(fd2[0],0);
            close(fd1[0]);
            close(fd2[1]);
            close(fd1[1]);
            execlp("wc","wc","-l",NULL);
        }
    }
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 18.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
       0
*/