/* Name: 1a.c
Register Number: MT2024072
Date: 10 sep 2024
Description: A separate program (for each time domain) to set a interval timer in 10sec and 10micro second (a) ITIMER_REAL */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include<sys/time.h>
int main(){
    struct itimerval timer;
    timer.it_interval.tv_sec = 10;
    timer.it_interval.tv_usec = 10;
    timer.it_value.tv_sec = 10;
    timer.it_value.tv_usec = 10;
    if(setitimer(ITIMER_REAL,&timer,NULL)==-1){
        perror("Timer not set");
        exit(EXIT_FAILURE);
    }
    while(1){
        
    }
    return 0;
}

/*
Name: 
Author: MT2024072
Description: 
Date: 
 */