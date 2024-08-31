/*
============================================================================
Name : 23.c
Author : Jyoti Singh
Description : Write a program to create a Zombie state of the running program.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int main(){
	
	int cpid = fork();
	
	//fork returns zero to child process and pid of child to parent process. 
	//If will run for child process.
	
	if(!cpid){
		printf("I am child, PID: %d\n", getpid());
	}
	
	else{
		printf("This is a parent process: %d\n", getpid());

		//sleep is written to make the parent wait 
		//so that child will complete its execution 
		//and become a zombie process
		sleep(50);
		
		
	}
	
	//do \"ps <child_pid>\" in terminal to check the status of the program. 
	//if status is Z, it is zombie process	
	return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 23.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
This is a parent process: 75439
I am child, PID: 75440
^Z
[19]+  Stopped                 ./a.out

*/