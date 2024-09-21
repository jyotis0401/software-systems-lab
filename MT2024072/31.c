/*
Name: 31.c
Author: MT2024072
Description: Program to create a semaphore and initialize value to the semaphore.
Date: 
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <errno.h>

// union semun {
//     int val;    
//     struct semid_ds *buf;    
//     unsigned short  *array;                          
// };

int main(){
    int ch;
    printf("Enter choice - 1 for binary, 2 for counting\n");
    scanf("%d", &ch);


    if (ch == 1){

        key_t key;
        int semid;
        key = ftok(".", 'a');
        semid = semget(key, 1, IPC_CREAT | 0666);


        if (semid == -1) {
            perror("Failed to create semaphore");
            return -1;
        }

        if (semctl(semid, 0, SETVAL, 1) != -1){
            printf("Binary semaphore created\n");

            int val;
            val = semctl(semid, 0, GETVAL);
            printf("Value of semaphore- %d\n", val);

            semctl(semid, 0, IPC_RMID);
        }else{
            perror("Error");
        }
        

    }else if (ch == 2){

        key_t key;
        int semid;

        key = ftok(".", 'a');
        semid = semget(key, 1, IPC_CREAT | 0666);


        if (semid == -1) {
            perror("Failed to create semaphore");
            return -1;
        }
        int val;
        
        printf("Enter the value of semaphore\n");
        scanf("%d", &val);


        if (semctl(semid, 0, SETVAL, val) != -1){
            
            printf("Counting semaphore created\n");
            int val;
            val = semctl(semid, 0, GETVAL);
            printf("Value of semaphore- %d\n", val);

            semctl(semid, 0, IPC_RMID);

        }else{
            perror("Error");
        }

    }else{
        printf("Invalid choice\n");
    }

    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 31.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Enter choice - 1 for binary, 2 for counting
2
Enter the value of semaphore
4
Counting semaphore created
Value of semaphore- 4
*/