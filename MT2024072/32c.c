/*
Name: 
Author: MT2024072
Description: 
Date: 
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
    //this program allows atmost 2 files to read the data in a file simultaneously
    key_t key = ftok(".", 'c');
    int semid = semget(key, 1, IPC_CREAT | 0666);

    semctl(semid, 0, SETVAL, 2);

    int fd = open("32c.txt", O_WRONLY | O_CREAT, 0777);
    write(fd, "Data in file\n", sizeof("Data in file\n"));
    return 0;
}