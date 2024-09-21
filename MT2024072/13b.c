/*
Name: 
Author: MT2024072
Description: the second program will send the signal (using kill system call). Find out whether the first program is able to catch the signal or not.
Date: 
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
int main(){
    pid_t pid;
    scanf("%d",&pid);
    kill(pid,SIGSTOP);
}