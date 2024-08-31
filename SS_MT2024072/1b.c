
/*
============================================================================
Name : 1b.c
Author : Jyoti Singh
Description : 1b. creating hard link usin command shell and using System call

Date: 28th Aug, 2024.
============================================================================
*/


//hard link (link system call)

/*1b. creating hard link usin command shell

(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ln f1 f2
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ls -il
total 0
7800074 -rw-r--r--  2 jyotisingh  staff  0 Aug 22 12:21 f1
7800074 -rw-r--r--  2 jyotisingh  staff  0 Aug 22 12:21 f2*/

// link using System call

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
//int symlink(const char *f2, const char *symlinkf2);
int catch=symlink("f2","symlinkf2");
// per÷ror("error");
return 0;
}