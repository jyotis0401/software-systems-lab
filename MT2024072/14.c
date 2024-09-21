/*
Name: 14.c
Author: MT2024072
Description: Simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 16 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() {
  int pipefd[2];
  char buffer[25];
  pipe(pipefd);
  write(pipefd[1],"Hello!",6);
  read(pipefd[0],buffer,6);
  printf("%s\n",buffer);
  return 0;
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 14.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Hello!

*/