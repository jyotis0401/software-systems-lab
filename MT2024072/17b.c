/*
Name: 17b.c
Author: MT2024072
Description: Program to execute ls -l | wc using (b) dup2
Date: 17 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){
    int fd1[2];
    pipe(fd1);
    
    if(!fork()){
        dup2(fd1[1],1);
        close(fd1[0]);
        execlp("ls","ls","-l",NULL);
    }
    else{
            dup2(fd1[0],0);
            close(fd1[1]);
            execlp("wc","wc",NULL);
    }
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 17b.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
      32     281    1748

*/