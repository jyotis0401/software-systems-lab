/*
Name: 
Author: MT2024072
Description: First program is waiting to catch SIGSTOP signal
Date: 15 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include<unistd.h>
void sigstop_handler(int signal)
{
    printf("Caught SIGSTOP signal\n");
    exit(1);
}
int main(){
    printf("%d\n",getpid());
    signal(SIGSTOP,sigstop_handler);
    
    while(1){

    };
}
//Run both this on one terminal and 13b on another terminal and put the pid printed as the input of 13b.13a will stop. 
//Hence sigstop can't be caught.
//Run this program, ctrlZ then get pid by ps and then fg, other terminal run 13b.c and give input the pid, 13a.c will get paused, hence signal is not handles. To kill the process again fg and then ctrlC