/*
Name: 23.c
Author: MT2024072
Description: Program to print the maximum number of files can be opened within a process and size of a pipe (circular buffer).
Date: 19 sep 2024
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    // Print the maximum number of files that can be opened within a process
    printf("Maximum number of files that can be opened within a process: %ld\n", sysconf(_SC_OPEN_MAX));
    
    printf("Size of a pipe (circular buffer): %d bytes\n",PIPE_BUF);
    
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 23.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Maximum number of files that can be opened within a process: 256
Size of a pipe (circular buffer): 512 bytes
*/