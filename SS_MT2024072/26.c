/*
============================================================================
Name :26.c
Author : Jyoti Singh
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/

//execl function, which replaces the current process image with a new process image specified by the given path and argument list.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>

int main(){
    printf("BEFORE\n");
    execl("/bin/ls", "ls",NULL);
    printf("AFTER\n"); //after not printed
    return 0;
}

/*

(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 26a.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
BEFORE
10			20.c			8
10.c			21.c			8.c
11			22.c			9
11.c			23.c			9.c
12			24.c			Fileforten
12.c			25.c			Fileforten.txt
13			26a.c			a.out
13.c			3			duplicatefd.txt
14			3.c			f1cler
14.c			31file			f2
15.c			32file			fifofile
16.c			33file			file
17.c			3file			fileopen1
17ticket.c		4			fileopen5
18.c			4.c			fileoutput
18ticket.c		5.c			namedpipe
19.c			6			sofrfilelink.txt
1a.c			6.c			softf2.txt
1aSys.c			7			somelinkfile.txt
1b.c			7.			somelinkfile2.txt
1c.c			7.c			symlinkf2
2			7write
2.c			7writefile
*/