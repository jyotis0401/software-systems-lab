/*
============================================================================
Name : 16.c
Author : Jyoti Singh
Description :  Write a program to perform mandatory locking. a. Implement write lock
b. Implement read lock
Date: 28th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){

    // /*
    // struct flock {
    //              off_t       l_start;    /* starting offset */
    //              off_t       l_len;      /* len = 0 means until end of file */
    //              pid_t       l_pid;      /* lock owner */
    //              short       l_type;     /* lock type: read/write, etc. */
    //              short       l_whence;   /* type of l_start */
    //          };
    // */
    struct flock lock;
	
	int fd=open("1aSys.c",O_RDWR);
	if(fd==-1){
		printf("file open erorr\n");
	}
	
	int inp;
	printf("Enter 1 to read lock and 2 to write lock\n");
	scanf("%d", &inp);

	if(inp==2){	
		lock.l_type = F_WRLCK;				//write lock type of lock
		printf("Implemented write lock\n");
	}
	else if(inp==1){
		lock.l_type = F_RDLCK;
		printf("Implemented read lock\n");
	}
	else {
		printf("Enter r or w\n");
		return 0;
	}
	
   	lock.l_whence = SEEK_SET;

	//start indicates the start of lock therefore it is zero. 
    //keeping len 0 means applying the lock on the entire file from start. 
	
   	lock.l_start = 0;
   	lock.l_len = 0;
	lock.l_pid = getpid();
	
	printf("Before locking\n");
	
	fcntl(fd,F_SETLKW,&lock);			//setlkw will wait for the lock to be released. his command is the same as F_SETLK except that if a shared or exclusive lock is blocked by other locks, the process
                                        //waits until the request can be satisfied.
	
	printf("File locked\n");
	
	printf("Enter to unlock\n");
	getchar();
    getchar();
	
	printf("unlocked the file\n");
	lock.l_type=F_UNLCK;
	
	//setlk will relase the lock if l_type is F_UNLCK and aquire the lock if type is F_RDLCK or F_WRLCK
	int fcntlr = fcntl(fd,F_SETLK,&lock);
	
	printf("%d\n",fcntlr);
	printf("done\n");
    return 0;
}

/*

(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 16.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
Enter 1 to read lock and 2 to write lock
2
Implemented write lock
Before locking
File locked
Enter to unlock

unlocked the file
0
done
*/

