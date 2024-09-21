/*
Name: 
Author: MT2024072
Description: Program to receive messages from the message queue (b) with IPC_NOWAIT as a flag
Date: 
 */
#include <stdio.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<unistd.h>
#include<string.h>

struct msgbuf
{
    long int mytype;
    char mytext[80];
};

int main()
{
    int id, size;
    key_t key;
    key = ftok(".",'a');
    id = msgget(key, 0);
    struct msgbuf mymsg;
    printf("Enter the message type: ");
    scanf("%ld", &mymsg.mytype);
    msgrcv(id, &mymsg, sizeof(mymsg), mymsg.mytype, IPC_NOWAIT);
    printf("Message type: %ld \n",mymsg.mytype);
    printf("Message: %s",mymsg.mytext);
    return 0;
}
//If message not found prints garbage value...show by commenting msgsnd

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Enter the message type: IPC_NOWAIT
Message type: 140734749362832 
*/