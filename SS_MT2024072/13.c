/*
============================================================================
Name : 13.c
Author : Jyoti Singh
Description : Write a program to wait for a STDIN for 10 seconds using select. 
Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).

Date: 27th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
	
int main() {
    //select(int nfds, fd_set *restrict readfds, fd_set *restrict writefds, fd_set *restrict errorfds, struct timeval *restrict timeout);
	
    fd_set stdin_set; 
	struct timeval tlimit;
	

    //fd_zero initializes a null set of fd 

	FD_ZERO(&stdin_set);
	FD_SET(0, &stdin_set); // set adds a fd to the set
	
	tlimit.tv_sec = 10;
		
	int out = select(1, &stdin_set, NULL, NULL, &tlimit);
	if(out) {
		printf("Data is available\n");
	}
	else {
		printf("No data available\n");
	}
	getchar();
	return 0;
}

