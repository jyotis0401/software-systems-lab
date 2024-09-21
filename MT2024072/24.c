/*
Name: 24.c
Author: MT2024072
Description: Program to create a message queue and print the key and message queue id.
Date: 19 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    key_t key;
    int msgqid;
    
    // Generate a key
    if ((key = ftok(".", 'a')) == -1) {
        perror("ftok");
        exit(1);
    }
    
    // Create a message queue with permissions 0666
    msgqid = msgget(key, 0666 | IPC_CREAT);
    
    // Print the key and message queue ID
    printf("Key: %d\nMessage queue ID: %d\n", key, msgqid);
    
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Key: 1627673832
Message queue ID: 65536
*/