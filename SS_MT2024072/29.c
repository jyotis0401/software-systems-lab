/*
============================================================================
Name :29.c
Author : Jyoti Singh
Description :Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO, SCHED_RR).
Date: 30th Aug, 2024.
============================================================================
*/

#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<stdlib.h>
#include<stdio.h>
#include <sched.h>

int main()
{
    int pid = getpid();
    int policy  = sched_getscheduler(pid);
    if(policy == SCHED_FIFO)
        printf("A first-in first-out policy.\n");
    else if(policy == SCHED_RR)
        printf("A round-robin policy.\n");
    else
        printf("Others.\n");

    struct sched_param sp;
    sp.sched_priority = 40;
    sched_setscheduler(pid, SCHED_FIFO, &sp);

    int mod_policy = sched_getscheduler(pid);
    if(mod_policy == SCHED_FIFO)
        printf("A first-in first-out policy.\n");
    else if(mod_policy == SCHED_RR)
        printf("A round-robin policy.\n");
    else
        printf("Others.\n");


}