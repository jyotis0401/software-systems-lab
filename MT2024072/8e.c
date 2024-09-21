/*
Name: 8e.c
Author: MT2024072
Description: Program using signal system call to catch the (e) SIGALRM (use setitimer system call)
Date: 14 sep 2024
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>

void sigalrm_handler(int sig) {
    printf("Caught SIGALRM signal (%d)\n", sig);
    exit(1);
}

int main() {
    struct itimerval timer;
    timer.it_interval.tv_sec = 1;        
    timer.it_interval.tv_usec = 1;
    timer.it_value.tv_sec = 1;
    timer.it_value.tv_usec = 1;
    signal(SIGALRM, sigalrm_handler);
    if (setitimer(ITIMER_REAL, &timer, NULL) == -1){
        perror("setitimer");
        exit(1);
    }
    while(1){
        sleep(1);
    }
    return 0;
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ open 8e.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8e.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Caught SIGALRM signal (14)
*/