/*
Name: 7.c
Author: MT2024072
Description: Simple program to print the created thread ids.
Date: 12 sep 2024
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
void *thread_function()
{
    printf("Thread ID: %llu\n", pthread_self());
}
int main(){
    pthread_t thread1, thread2, thread3;
    pthread_create(&thread1, NULL, thread_function, NULL);
    pthread_create(&thread2, NULL, thread_function, NULL);
    pthread_create(&thread3, NULL, thread_function, NULL);
    pthread_join(thread1, NULL);        // wait for all threads to finish
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    printf("All threads have completed.\n");
}
//Compile with command gcc -pthread 7.c