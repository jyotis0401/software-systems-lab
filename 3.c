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
