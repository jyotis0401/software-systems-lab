/*
============================================================================
Name : 9.c
Author : Jyoti Singh
Description : Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification j. time of last change
Date: 27th Aug, 2024.
============================================================================
*/


#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
int main(){
    int fd, inode;  
fd = open("6.c", O_RDONLY);

if (fd < 0) { 
    perror("error opening the file ");
}  
//struct stat is a system struct that is defined to store information about files.
/*

Field Name	  Description
st_mode	     The current permissions on the file.
st_ino	     The inode for the file (note that this number is unique to all files and directories on a Linux System.
st_dev	     The device that the file currently resides on.
st_uid	     The User ID for the file.
st_gid	     The Group ID for the file.
st_atime  	 The most recent time that the file was accessed.
st_ctime	 The most recent time that the file's permissions were changed.
st_mtime	 The most recent time that the file's contents were modified.
st_nlink	 The number of links that there are to this file.
st_size        file size in byte.

st_blocks  blocks allocated for file 
st_blksize; optimal file sys I/O ops blocksize
st_flags  user defined flags for file
st_gen;    file generation number 

         

*/
struct stat file_stat;  
int ret;  


/*
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
fstat is a system call that is used to determine information about a file based on its file descriptor.
int fstat(int fildes, struct stat *buf) //A structure where data about the file will be stored.

*/
ret = fstat (fd, &file_stat);  
if (ret < 0) {  
    printf("Error getting the file status");
} 

inode = file_stat.st_ino; 
printf("INODE number of the file is: %d \n", inode );

int links=file_stat.st_nlink;
printf("The number of links there are: %d \n", links);

int uid= file_stat.st_uid;
printf("The user id is: %d \n",uid);

int gid= file_stat.st_gid;
printf("The group id is: %d \n",gid);

int size= file_stat.st_size;
printf("The size is: %d \n",size);

int blocks= file_stat.st_blocks;
printf("Number of blocks : %d \n",blocks);

// BLOCK SIZE
int blksize= file_stat.st_blksize;
printf("The block size: %d \n",blksize);

int lstacc= file_stat.st_atime;
printf("last access: %d \n",lstacc);

int lstmod= file_stat.st_mtime;
printf("last modified: %d \n",lstmod);

int ctime= file_stat.st_ctime;
printf("last changed permission: %d \n",ctime);



printf("%d",ret);


    return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 9.c -o 9
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./9
INODE number of the file is: 7824528 
The number of links there are: 3 
The user id is: 501 
The group id is: 20 
The size is: 919 
Number of blocks : 8 
The block size: 4096 
last access: 1724906011 
last modified: 1724906010 
last changed permission: 1724908701 
*/

