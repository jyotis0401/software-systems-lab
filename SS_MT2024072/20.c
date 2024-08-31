	/*
============================================================================
Name : 20.c
Author : Jyoti Singh
Description : Find out the priority of your running program. Modify the priority with nice command. 
Date: 29th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){
    //first parameter is for process, if we want group process priority use PRIO_PGRP. 
	//But we want the prioirty for process, hence PRIO_PROCESS
	//second parameter is 0 because we want the priority for the current process
		
	int priority = getpriority(PRIO_PROCESS,0);
	
	printf("Current priority is: %d\n",priority);
	
	printf("Enter the nice value to change the priority: ");
	int inp;
	
	scanf("%d",&inp);
	
	//nice changes the priority for the current process and returns the updated process priority.
	//priority range is from -20 to 19
	int pr = nice(inp);
	
	printf("Current prioirty is: %d\n",pr);
	return 0;

    
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 20.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
Current priority is: 0
Enter the nice value to change the priority: 12
Current prioirty is: 12
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ 
*/