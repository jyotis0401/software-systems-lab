/*
Name: 8g.c
Author: MT2024072
Description: Program using signal system call to catch the (g) SIGPROF (use setitimer system call)
Date: 14 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>
void sigprof_handler(int signum)
{
    printf("Caught SIGPROF signal.\n");
    exit(0);
}

int main()
{
    struct itimerval timer;
    timer.it_interval.tv_sec = 1;        
    timer.it_interval.tv_usec = 1;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 1;
    if (setitimer(ITIMER_PROF, &timer, NULL) == -1){
        perror("setitimer");
        exit(1);
    }
    signal(SIGPROF,sigprof_handler);
    while(1) {
    }

    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8g.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Caught SIGPROF signal.
*/