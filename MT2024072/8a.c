/*
Name: 8a.c
Author: MT2024072
Description: Write a separate program using signal system call to catch the following signals. a. SIGSEGV
Date: 12 sep 2024
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
void sigsegv_handler(int signal)
{
    printf("Caught SIGSEGV signal\n");
    exit(1);
}
int main(){
    signal(SIGSEGV,sigsegv_handler);    //occur when a program tries to access memory that hasn't been allocated.
    int *x=NULL;
    *x=42;
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8a.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Caught SIGSEGV signal
*/

