/*
Name: 
Author: MT2024072
Description: Program to remove the message queue.
Date: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/msg.h>

int main() {
    int msgid;

    // Create a message queue with key 1234
    msgid = msgget(1234, 0666 | IPC_CREAT);
    if (msgid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Remove the message queue
    if (msgctl(msgid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    printf("Message queue removed successfully.\n");
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 29.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Message queue removed successfully.
*/