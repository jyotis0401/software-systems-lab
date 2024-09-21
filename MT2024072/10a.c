/*
Name: 10a.c
Author: MT2024072
Description: Separate program using sigaction system call to catch the signal (a) SIGSEV
Date: 14 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler(int signum, siginfo_t *info, void *context)
{
    printf("Received SIGSEGV signal.\n");
    exit(1);
}

int main()
{
    struct sigaction sa;

    // Set up the signal handler for SIGSEGV
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGSEGV, &sa, NULL);

    // Dereference a null pointer to trigger a SIGSEGV signal
    int *ptr = NULL;
    *ptr = 42;

    return 0;
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 10a.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Received SIGSEGV signal.
*/