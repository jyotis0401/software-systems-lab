/*
============================================================================
Name : 6.c
Author : Jyoti Singh
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 25th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
int main(){
    // int a= open("2.c",O_RDONLY,);
    //standard value
    // stdin fd 0 
    //stout fd 1;
    int buff[100];
    int a=read(0,buff,sizeof(buff));
    int b=write(1,buff,a);
    printf("THe ouput of write : %d",b);

    return 0;
}


/* OUTPUT

(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 6.c -o 6
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./6
THis is the input given to read and write
THis is the input given to read and write
THe ouput of write : 42

*/