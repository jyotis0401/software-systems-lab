/*
Name: 4.c
Author: MT2024072
Description: Program to measure how much time is taken to execute 100 getppid ( ) system call using time stamp counter.
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
unsigned long long int rdtsc(void){
   unsigned long long int val;
   asm volatile ("mrs %0, cntvct_el0" : "=r" (val));
   return val;
}

int main()
{
    int i;
    unsigned long long t1, t2, cycles = 0;
    for (i = 0; i < 100; i++) {
        t1 = rdtsc();
        getppid();
        t2 = rdtsc();
        cycles += (t2 - t1);
    }
    printf("Total cycles to execute 100 getppid(): %llu\n", cycles);
    return 0;
}
/*

*/