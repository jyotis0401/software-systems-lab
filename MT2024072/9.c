/*
Name: 9.c
Author: MT2024072
Description: Program to ignore a SIGINT signal then reset the default action of the SIGINT signal using signal system call.
Date: 14 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void ignore_handler(int signum)
{
    printf("Ignoring SIGINT signal.\n");
}

void default_handler(int signum)
{
    printf("Resetting default action for SIGINT signal.\n");
    signal(SIGINT, SIG_DFL);
}

int main()
{
    // Set up the signal handler to ignore SIGINT
    signal(SIGINT, ignore_handler);

    // Wait for 5 seconds to simulate some activity
    printf("Waiting for 5 seconds...\n");
    sleep(5);

    // Reset the signal handler to the default action for SIGINT
    signal(SIGINT, default_handler);

    // Wait for another 5 seconds to see the default handler in action
    printf("Waiting for 5 seconds...\n");
    sleep(5);

    return 0;
}
//Press CtrlC after every waiting for 5 seconds