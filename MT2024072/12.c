/*
Name: 12.c
Author: MT2024072
Description: Program to create an orphan process. Use kill system call to send SIGKILL signal to the parent process from the child process.
Date: 15 sep 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sigkill_handler(int signum)
{
    printf("Received SIGKILL signal.\n");
}

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) 
    {
        // Child process
        sleep(5);
        printf("Child process sending SIGKILL signal to parent process with pid %d :\n",getppid());
        kill(getppid(), SIGKILL);
        sleep(5);
        printf("Child pid : %d Parent pid after orphan : %d\n", getpid(), getppid());
    } 
    else
    {
        // Parent process
        printf("Parent process started with PID: %d\n", getpid());
        signal(SIGKILL, sigkill_handler);
        while(1) {
            printf("Parent process running...\n");
            sleep(1);
        }
        printf("Parent process completed.\n");
    }

    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Parent process started with PID: 17582
Parent process running...
Parent process running...
Parent process running...
Parent process running...
Parent process running...
Child process sending SIGKILL signal to parent process with pid 17582 :
Killed: 9
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ Child pid : 17583 Parent pid after orphan : 1
*/