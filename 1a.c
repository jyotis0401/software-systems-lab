


//a. soft link (symlink system call)

/*
CREATING SOFT LINK USING SHELL COMMAND 
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ touch 1b.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ln -s f1 sfile
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ls -il
total 16
7800132 -rw-r--r--  1 jyotisingh  staff  325 Aug 22 12:26 1a.c
7800276 -rw-r--r--  1 jyotisingh  staff    0 Aug 22 12:26 1b.c
7800074 -rw-r--r--  2 jyotisingh  staff    0 Aug 22 12:21 f1
7800074 -rw-r--r--  2 jyotisingh  staff    0 Aug 22 12:21 f2
7800288 lrwxr-xr-x  1 jyotisingh  staff    2 Aug 22 12:26 sfile -> f1
*/

// USING SYSTEM CALL
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(){
    // creating soft link using link system call 
    int a=link("f2","softf2.txt");
    if(a<0){
        perror("failed");
    }
    if(a==0){
        printf("Soft Link created");
    }
    return 0;
}

//7800074 -rw-r--r--  2 jyotisingh  staff     0 Aug 22 12:21 f2
//7800074 -rw-r--r--  2 jyotisingh  staff     0 Aug 22 12:21 softf2.txt