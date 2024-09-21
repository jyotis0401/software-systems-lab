/*
Name: 11.c
Author: MT2024072
Description: Program to ignore a SIGINT signal then reset the default action of the SIGINT signal - using sigaction system call.
Date: 15 sep 2024
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signo) {
  printf("Received SIGINT signal\n");
}

int main() {
  struct sigaction sa;
  sa.sa_handler = sigint_handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;

  // Ignore the SIGINT signal the first time it is received
  sigaction(SIGINT, &sa, NULL);
  printf("Ignoring SIGINT signal...\n");
  sleep(5);

  // Reset the default action for the SIGINT signal
  sa.sa_handler=SIG_DFL;
  sigaction(SIGINT, &sa,NULL);
  printf("Set to default...\n");
  sleep(5);

  return 0;
}
//CtrlC twice
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ open 11.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 11.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Ignoring SIGINT signal...
^CReceived SIGINT signal
Set to default...
^C
*/