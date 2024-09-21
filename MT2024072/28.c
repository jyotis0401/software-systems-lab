/*
Name: 
Author: MT2024072
Description: Program to change the exiting message queue permission. (use msqid_ds structure)
Date: 
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/stat.h>

int main()
{
    int msqid;
    key_t key;
    struct msqid_ds msq_info;

    // Get the key of the existing message queue
    key = ftok(".", 'a');
    if (key == -1) {
        perror("ftok");
        exit(1);
    }

    // Get the ID of the existing message queue
    msqid = msgget(key, IPC_CREAT | 0666);
    if (msqid == -1) {
        perror("msgget");
        exit(1);
    }

    // Get information about the existing message queue
    if (msgctl(msqid, IPC_STAT, &msq_info) == -1) {
        perror("msgctl IPC_STAT");
        exit(1);
    }
    printf("Permissions: 0%o\n", msq_info.msg_perm.mode);

    // Change the permission of the existing message queue
    msq_info.msg_perm.mode = S_IRUSR | S_IWUSR;
    //Read and write permission bit for the owner of the file 
    // Update the message queue with the new permission
    if (msgctl(msqid, IPC_SET, &msq_info) == -1) {
        perror("msgctl IPC_SET");
        exit(1);
    }

    printf("The permission of the message queue has been changed.\n");
    printf("New Permissions: 0%o\n", msq_info.msg_perm.mode);

    if (msgctl(msqid, IPC_RMID, NULL) == -1) {
        perror("msgctl");
        exit(EXIT_FAILURE);
    }
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 28.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Permissions: 0744
The permission of the message queue has been changed.
New Permissions: 0600

*/
