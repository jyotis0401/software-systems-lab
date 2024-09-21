/*
Name: 26.c
Author: MT2024072
Description: Program to send messages to the message queue. Check $ipcs -q
Date: 20 sep 2024
 */
#include <stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

struct msgbuf
{
    long int mtype;
    char mtext[100];
};

int main()
{
    int id, size;
    key_t key;
    key = ftok(".",'a');
    id = msgget(key, IPC_CREAT|0744);
    
    struct msgbuf mymsg;
    
    printf("Enter the message type: ");
    scanf("%ld",&mymsg.mtype);

    printf("Enter the message: ");
    scanf("%s", mymsg.mtext);

    msgsnd(id, &mymsg,strlen(mymsg.mtext), 0);
    return 0;
}

/*

*/