/*
Name: 32d.c
Author: MT2024072
Description: Program to implement semaphore to protect any critical section.
Date: 20 sep 2024
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdio.h>
#include <errno.h>

int main(){
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, 0);

    key_t key_sem;
    int semid;
    key_sem = ftok(".", 'z');
    semid = semget(key_sem, 1, 0);

    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    printf("Resource and semaphore deleted\n");
    return 0;
}
/*
Resource and semaphore deleted
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ /*
-bash: /Applications: is a directory
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$
*/

