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
    //this program allows atmost 2 files to read the data in a file simultaneously
    key_t key = ftok(".", 'c');
    int semid = semget(key, 1, IPC_CREAT | 0666);

    semctl(semid, 0, SETVAL, 2);

    int fd = open("32c.txt", O_WRONLY | O_CREAT, 0777);
    write(fd, "Data in file\n", sizeof("Data in file\n"));
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Inside semaphore
Data - ???

(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 32c_readers.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Inside semaphore
Data - Data in file

(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ 
*/