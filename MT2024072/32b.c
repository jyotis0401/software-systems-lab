/*
Name: 32b.c
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

    int * data = shmat(shmid, (void *)0, 0);

    key_t key_sem;
    int semid;
    key_sem = ftok(".", 'z');
    semid = semget(key_sem, 1, 0);

    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;

    printf("Before semaphore\n");

    semop(semid, &buf, 1);
    int val = *data;
    printf("Tickets - %d\n", val);
    printf("Incrementing\n");

    val+=1;
    *data = val;

    getchar();
    printf("Releasing\n");
    buf.sem_op = 1;
    semop(semid, &buf, 1);

    shmdt(data);
    printf("Exiting\n");

    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 32b.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Before semaphore
Tickets - 4
Incrementing

Releasing
Exiting
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Before semaphore
Tickets - 5
Incrementing

Releasing
Exiting

*/