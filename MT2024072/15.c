/*
Name: 
Author: MT2024072
Description: Simple program to send some data from parent to the child process.
Date: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 25

int main()
{
    int pipefd[2];
    pid_t pid;
    char buffer[BUFFER_SIZE];

    // create the pipe
    if (pipe(pipefd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    // fork a child process
    pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        // child process - read from the pipe
        close(pipefd[1]); // close the write end of the pipe
        read(pipefd[0], buffer, BUFFER_SIZE);
        printf("Child received message: %s\n", buffer);
        close(pipefd[0]); // close the read end of the pipe
    } else {
        // parent process - write to the pipe
        close(pipefd[0]); // close the read end of the pipe
        sprintf(buffer, "Hello, child!");
        write(pipefd[1], buffer, BUFFER_SIZE);
        close(pipefd[1]); // close the write end of the pipe
    }

    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 15.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Child received message: Hello, child!
*/