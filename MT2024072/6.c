/*
Name: 6.c
Author: MT2024072
Description: Simple program to create three threads.
Date: 12 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <pthread.h>
void *thread_function(void *arg)
{
    char *message;
    message = (char*) arg;
    printf("%s\n", message);
    pthread_exit(NULL);
}
int main(){
    pthread_t thread1, thread2, thread3;
    char *m1 = "Thread 1";
    char *m2 = "Thread 2";
    char *m3 = "Thread 3";
    pthread_create(&thread1, NULL, thread_function, (void*) m1);// linked the threads with the function created above
    pthread_create(&thread2, NULL, thread_function, (void*) m2);// now runs all the function with the corresponding commands
    pthread_create(&thread3, NULL, thread_function, (void*) m3);
    pthread_join(thread1, NULL);        // wait for all threads to finish
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    printf("All threads have completed.\n");
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Thread 1
Thread 2
Thread 3
All threads have completed.
*/