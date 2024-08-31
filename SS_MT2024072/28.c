/*
============================================================================
Name :28.c
Author : Jyoti Singh
Description :Write a program to get maximum and minimum real time priority.

Date: 30th Aug, 2024.
============================================================================
*/
/*SCHED_FIFO is a real-time scheduling policy in Linux that schedules processes in a first-in, first-out (FIFO) manner. 
In this policy, each process is assigned a priority value, and the CPU is always
given to the process with the highest priority. */
#include<unistd.h>
#include<stdio.h>
#include<sched.h>
#include<sys/types.h>
 
int main()
{
    printf("The Maximum real time priority FIFO = %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("The Minimum real time priority FIFO = %d\n", sched_get_priority_min(SCHED_FIFO));
    printf("The Maximum real time priority RR = %d\n", sched_get_priority_max(SCHED_RR));
    printf("The Minimum real time priority RR = %d\n", sched_get_priority_min(SCHED_RR));
    printf("The Maximum real time priority = %d\n", sched_get_priority_max(SCHED_OTHER));
    printf("The Minimum real time priority = %d\n", sched_get_priority_min(SCHED_OTHER));

 
    return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 28.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
The Maximum real time priority FIFO = 47
The Minimum real time priority FIFO = 15
The Maximum real time priority RR = 47
The Minimum real time priority RR = 15
The Maximum real time priority = 47
The Minimum real time priority = 15

*/