/*
Name: 
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
#include <unistd.h>
#include <fcntl.h>

int main(){
    key_t key = ftok(".", 'c');
    int semid = semget(key, 1, 0);

    struct sembuf buf;
    buf.sem_num = 0;
    buf.sem_op = -1;
    buf.sem_flg = SEM_UNDO;

    semop(semid, &buf, 1);
    printf("Inside semaphore\n");

    char data[50];
    int fd = open("32c.txt", O_RDONLY | O_CREAT, 0777);
    read(fd, data, sizeof(data));

    printf("Data - %s", data);
    buf.sem_op = 1;
    getchar();
    semop(semid, &buf, 1);
    return 0;
}