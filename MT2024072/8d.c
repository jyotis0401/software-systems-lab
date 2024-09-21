/*
Name: 8d.c
Author: MT2024072
Description: Program using signal system call to catch the (d) SIGALRM (use alarm system call)
Date: 13 sep 2024
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
void sigalrm_handler(int sig) {
    printf("Caught SIGALRM signal (%d)\n", sig);
    exit(1);
}

int main() {
    signal(SIGALRM, sigalrm_handler);
    alarm(2);
    while(1){
        sleep(1);
    }
    return 0;
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8d.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Caught SIGALRM signal (14)
*/