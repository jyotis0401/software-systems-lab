/*
Name: 
Author: MT2024072
Description: Program using signal system call to catch the (c) SIGFPE
Date: 12 sep 2024
 */
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigfpe_handler(int sig) {
    printf("Caught SIGFPE signal (%d)\n", sig);
    exit(1);
}

int main() {
    signal(SIGFPE, sigfpe_handler);
    int a = 10;
    int b = 0;
    float c = a / b; // This will generate a floating point exception (SIGFPE)
    // printf("%f",&c);
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8c.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Caught SIGFPE signal (8)
*/