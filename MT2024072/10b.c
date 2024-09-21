/*
Name: 10b.c
Author: MT2024072
Description: Separate program using sigaction system call to catch the signal (b) SIGINT
Date: 14 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum, siginfo_t *info, void *context)
{
    printf("Received SIGINT signal.\n");
}

int main()
{
    struct sigaction sa;

    // Set up the signal handler for SIGSEGV
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGINT, &sa, NULL);

    while(1){
        sleep(10);
    }

    return 0;
}
//Press CtrlC while running
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 10b.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
^Z
[2]+  Stopped                 ./a.out
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ 
*/