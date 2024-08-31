
/*
============================================================================
Name : 22.c
Author : Jyoti Singh
Description : Write a program, open a file, call fork,
 and then write to the file by both the child as well as the parent processes. Check output of the file.
Date: 28th Aug, 2024.
============================================================================
*/


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

	if (argc!=2){
		printf("enter 1 arguments");
		return 0;
	}

	//open file
	int fd = open(argv[1], O_RDWR);

	if(fd==-1)
		printf("errorrrr opening file");

	//open write
	int char_written = write(fd, "Hello I am parent\n", 19);

	//fork
	int cpid=fork();
	//only child will enter this if block
	if(!cpid){
		int child_write = write(fd, "Hello I am child\n", 18);
	}

	//closing the fd
	int fd_close = close(fd);

	
	if(fd_close==-1)
	        printf("errorrr closing file");

    return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 22.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
enter 1 arguments(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out filewrite
errorrrr opening fileerrorrr closing fileerrorrrr opening fileerrorrr closing file(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ touch fileoutput
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out fileoutput
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ cat fileoutput
Hello I am parent
Hello I am child
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ 
*/