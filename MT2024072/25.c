/*
Name: 25.c
Author: MT2024072
Description: Program to print a message queue's (use msqid_ds and ipc_perm structures)
Date: 20 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main() {
    int msqid;
    key_t key;
    struct msqid_ds buf;
    struct ipc_perm perm;

    // Get the message queue's key
    key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    // Get the message queue's ID
    msqid = msgget(key, 0666 | IPC_CREAT);
    if (msqid == -1) {
        perror("msgget");
        exit(EXIT_FAILURE);
    }

    // Get the message queue's status
    if (msgctl(msqid, IPC_STAT, &buf) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    // Get the message queue's permission structure
    perm = buf.msg_perm;

    // Print information about the message queue
    printf("Message queue information:\n");
    printf("    Queue size: %ld bytes\n", buf.msg_qbytes);
    printf("    Messages in queue: %ld\n", buf.msg_qnum);
    printf("    Last send time: %ld\n", buf.msg_stime);
    printf("    Last receive time: %ld\n", buf.msg_rtime);
    printf("    Last change time: %ld\n", buf.msg_ctime);
    printf("    Owner UID: %d\n", perm.uid);
    printf("    Owner GID: %d\n", perm.gid);
    printf("    Permissions: 0%o\n", perm.mode);
    printf("    Maximum number of bytes allowed: %lu\n", buf.msg_qbytes);
    printf("    pid of msgsnd and msgrcv: %d %d\n", buf.msg_lspid,buf.msg_lrpid);

    // Clean up
    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/*

(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 25.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Message queue information:
    Queue size: 2048 bytes
    Messages in queue: 0
    Last send time: 0
    Last receive time: 0
    Last change time: 1726893994
    Owner UID: 501
    Owner GID: 20
    Permissions: 0666
    Maximum number of bytes allowed: 2048
    pid of msgsnd and msgrcv: 0 0

*/