/*
Name: 8b.c
Author: MT2024072
Description: Description: Program using signal system call to catch the (b) SIGINT
Date: 12 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
void handle_sigint(int sig) {
    printf("Caught SIGINT signal (%d)\n", sig);
}
int main(){
    signal(SIGINT,handle_sigint);   //Interrupt
    while (1) {             // Infinite loop to keep the program running
        sleep(1);
    }
    return 0;
}
//Press CtrlC while the program is running
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 8b.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
^CCaught SIGINT signal (2)
*/