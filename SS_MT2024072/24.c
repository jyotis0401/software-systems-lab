/*
============================================================================
Name : 24.c
Author : Jyoti Singh
Description : Write a program to create an orphan process.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
      pid_t pid = fork();  // Create a child process

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid > 0) {
        // This is the parent process
        printf("Parent process (PID: %d) is going to terminate.\n", getpid());
        sleep(2);  // Give the child process time to run before the parent exits
        printf("Parent process exiting...\n");
        exit(0);  // Parent process exits
    } else {
        // This is the child process
        sleep(5);  // Ensure that the parent process exits first
        printf("Child process (PID: %d) has become an orphan, adopted by init process (PID: %d).\n", getpid(), getppid());
    }

    return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
Parent process (PID: 78302) is going to terminate.
Parent process exiting...
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ Child process (PID: 78303) has become an orphan, adopted by init process (PID: 1).

*/