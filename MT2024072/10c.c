/*
Name: 10c.c
Author: MT2024072
Description: Separate program using sigaction system call to catch the signal (c) SIGFPE
Date: 14 seep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int signum, siginfo_t *info, void *context)
{
    printf("Received SIGFPE signal.\n");
    exit(1);
}

int main()
{
    struct sigaction sa;

    // Set up the signal handler for SIGSEGV
    sa.sa_sigaction = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGFPE, &sa, NULL);
    int a = 1;
    int b = 0;
    int c = a / b; // This will generate a floating point exception (SIGFPE)
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 10c.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Received SIGFPE signal.
*/
