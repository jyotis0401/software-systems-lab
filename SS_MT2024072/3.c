/*
============================================================================
Name : 3.c
Author : Jyoti Singh
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 26th Aug, 2024.
============================================================================
*/

#include <fcntl.h>
#include<stdio.h>
#include<libc.h>
#include<unistd.h>

int main(){
    int a=creat("31file",0744);
    if(a==-1) printf("Error");
    else printf("File Descriptor: %d\n", a);
     a=creat("32file",0744);
    if(a==-1) printf("Error");
    else printf("File Descriptor: %d\n", a);
     a=creat("3file",0744);
    if(a==-1) printf("Error");
    else printf("File Descriptor: %d\n", a);
     a=creat("33file",0744);
    if(a==-1) printf("Error");
    else printf("File Descriptor: %d\n", a);
    return 0;
}

/*
Output
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 3.c -o 3
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./3
File Descriptor: 3
File Descriptor: 4
File Descriptor: 5
File Descriptor: 6
*/
