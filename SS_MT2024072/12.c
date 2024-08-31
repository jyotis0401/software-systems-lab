/*
============================================================================
Name : 12.c
Author : Jyoti Singh
Description : Write a program to find out the opening mode of a file. Use fcntl.
Date: 27th Aug, 2024.
============================================================================
*/

//fcntl() performs one of the operations described below on the open file descriptor fd. The operation is determined by cmd.

// how to know which number means what mode--- GOt it
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(){
    int fd = open("1a.c",O_RDWR);
    if(fd<0) printf("Error opening the file");
    int mode=fcntl(fd,F_GETFL);
    printf("the mode i am getting is : %d", mode);
    return 0;
}

/*

Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 12.c -o 12
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./12
the mode i am getting is : 2(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ 

*/