/*
============================================================================
Name : 11.c
Author : Jyoti Singh
Description : Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not.
a. use dup b. use dup2 c. use fcntl
Date: 26th Aug, 2024.
============================================================================
*/

//fcntl() performs one of the operations described below on the open file descriptor fd. The operation is determined by cmd.
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){

    int org_fd=open("duplicatefd.txt",O_RDWR|O_CREAT);
    if(org_fd<0) printf("Error opening the file");
    int dup_fd=dup(org_fd);  //duplicating fd using dup
    // int dup_fd1 = dup2(org_fd, 6);
    //int dup_fd2 = fcntl(og_fd, F_DUPFD);


    if(dup_fd<0) printf("Error duplicating the file descriptor");

    char *org_buff = "original file content is here writing through buffer instead of anohter file\n";
	int org_write = write(org_fd, org_buff, strlen(org_buff));
	// printf("Reading after writing through original filedescriptor\n");	
	// readfile(duplicatefd.txt); //should work but not working
	// printf("\n");


    char *dup_buff="writing to the file using duplicate file descriptor\n";
    int dup_write=write(dup_fd,dup_buff,strlen(dup_buff));

    printf("Reading after wrting through duplicate file descriptor\n");
    // readfile(duplicatefd.txt);
    // printf("\n");

    char buff[1024];
    int a=read(org_fd,buff,1024);
    write(1,buff,a);
    close(org_fd);
    close(dup_fd);


    return 0;
}