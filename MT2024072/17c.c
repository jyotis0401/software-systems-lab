/*
Name: 17c.c
Author: MT2024072
Description: Program to execute ls -l | wc using (c) fcntl
Date: 17 sep 2024
 */
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){

    int fd[2];
    pipe(fd);

    if (!fork()){
        close(1);
        fcntl(fd[1],F_DUPFD,1);
        close(fd[0]);
        execlp("ls","ls","-l",NULL);
    }

    else{
        close(0);
        fcntl(fd[0],F_DUPFD,0);
        close(fd[1]);
        execlp("wc","wc",NULL);

    }

    return 0;

}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 17c.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
      32     281    1748
*/