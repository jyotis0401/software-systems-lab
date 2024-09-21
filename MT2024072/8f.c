/*
Name: 8f.c
Author: MT2024072
Description: Program using signal system call to catch the (f) SIGVTALRM (use setitimer system call)
Date: 13 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/time.h>
void sigvtalrm_handler(int signum)
{
    printf("Caught SIGVTALRM signal\n");
    exit(0);
}

int main()
{
    struct itimerval timer;
    timer.it_interval.tv_sec = 1;        
    timer.it_interval.tv_usec = 1;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 1;
    if (setitimer(ITIMER_VIRTUAL, &timer, NULL) == -1){
        perror("setitimer");
        exit(1);
    }
    signal(SIGVTALRM,sigvtalrm_handler);
    while(1) {
    }

    return 0;
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8f.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Caught SIGVTALRM signal

*/