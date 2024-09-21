/*
Name: 17a.c
Author: MT2024072
Description: Program to execute ls -l | wc using (a) dup
Date: 17 sep 2024
 */
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int main()
{
    int pfd[2];
    pid_t pid;

    if (pipe(pfd) == -1) {
        perror("pipe");
        exit(1);
    }

    if ((pid = fork()) == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        close(STDOUT_FILENO);
        dup(pfd[1]);
        close(pfd[0]);
        close(pfd[1]);
        execlp("ls", "ls", "-l", NULL);
    } else {
        close(STDIN_FILENO);
        dup(pfd[0]);
        close(pfd[0]);
        close(pfd[1]);
        execlp("wc", "wc", NULL);
    }

    return 0;
}
/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 17a.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
      32     281    1748

*/