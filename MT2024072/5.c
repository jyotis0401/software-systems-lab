/*
Name: 5.c
Author: MT2024072
Description: Program to print the system limitation of following
Date: 11.c
 */
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <limits.h>

int main(){
   printf("Maximum length of the arguments to the exec family of functions: %d\n",_SC_ARG_MAX);
   printf("Maximum number of simultaneous process per user id: %d\n",_SC_CHILD_MAX);
   printf("Number of clock ticks (jiffy) per second: %d\n",_SC_CLK_TCK);
   printf("Maximum number of open files: %d\n",_SC_OPEN_MAX);
   printf("Size of a page: %d\n",_SC_PAGE_SIZE);
   printf("Total number of pages in the physical memory: %d\n",_SC_PHYS_PAGES);
   // printf("Number of currently available pages in the physical memory: %d\n",_SC_AVPHYS_PAGES);
}

/*
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ gcc 5.c
(base) Jyotis-MacBook-Air:HandsOn2 jyotisingh$ ./a.out
Maximum length of the arguments to the exec family of functions: 1
Maximum number of simultaneous process per user id: 2
Number of clock ticks (jiffy) per second: 3
Maximum number of open files: 5
Size of a page: 29
Total number of pages in the physical memory: 200

*/