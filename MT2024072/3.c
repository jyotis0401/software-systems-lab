/*
Name: 3.c
Author: MT2024072
Description: program to set (any one) system resource limit using setrlimit system call.
Date: 11 sep 2024
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/resource.h>
int main() {
    struct rlimit limits;

    // Get the current resource limit for file size
    if (getrlimit(RLIMIT_FSIZE, &limits) == -1) {                       //RLIMIT_FSIZE is the maximum size in bytes of files that the process may create. 
        perror("Error getting resource limit for file size");
        return 1;
    }

    printf("Current soft limit for file size: %llu\n", limits.rlim_cur);
    printf("Current hard limit for file size: %llu\n", limits.rlim_max);

    // Set a new soft limit for file size
    limits.rlim_cur = 100 * 100; 
    limits.rlim_max=1024*1024; //1MB

    if (setrlimit(RLIMIT_FSIZE, &limits) == -1) {
        perror("Error setting resource limit for file size");
        return 1;
    }

    printf("New soft limit for file size: %llu\n", limits.rlim_cur);
    printf("New hard limit for file size: %llu\n", limits.rlim_max);
    
    return 0;
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 3.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Current soft limit for file size: 9223372036854775807
Current hard limit for file size: 9223372036854775807
New soft limit for file size: 10000
New hard limit for file size: 1048576
*/