	/*
============================================================================
Name : 19.c
Author : Jyoti Singh
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 29th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

// Function to read the time stamp counter usind rdtsc instead of using system clock 
//tsc will count the each cpu cycle .
unsigned long long rdtsc() {
    unsigned int lo, hi;
    asm volatile ("rdtsc" : "=a" (lo), "=d" (hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long start, end;
    
    // Get the starting TSC value
    start = rdtsc();
    
    // Execute the getpid() system call
    getpid();
    
    // Get the ending TSC value
    end = rdtsc();
    
    // Calculate and print the elapsed time
    printf("Time taken by %d in clock cycles: %llu\n",getpid(), end - start);
 return 0;
}


/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 19.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
Time taken by 67202 in clock cycles: 18948
*/