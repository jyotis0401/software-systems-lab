/*
Name: 
Author: MT2024072
Description: Program to implement semaphore to protect any critical section
Date: 
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <sys/sem.h>
#include <errno.h>

int main(){
    key_t key = ftok(".", 'a');
    int shmid = shmget(key, 1024, IPC_CREAT | 0666);

    int * data = shmat(shmid, (void *)0, 0);
    printf("Enter no of tickets -\n");
    scanf("%d", data);

    printf("Write successful\n");
    shmdt(data);

    key_t key_sem;
    int semid;
    key_sem = ftok(".", 'z');
    semid = semget(key_sem, 1, IPC_CREAT | 0666);


    if (semid == -1) {
        perror("Failed to create semaphore");
        return -1;
    }

    semctl(semid, 0, SETVAL, 1);

    printf("Binary semaphore created\n");
    
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Enter no of tickets -
4
Write successful
Binary semaphore created
*/