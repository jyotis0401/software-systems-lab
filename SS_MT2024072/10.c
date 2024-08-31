/*
============================================================================
Name :10.c 
Author : Jyoti Singh
Description : Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 26th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(){ 
    int filedes;
    filedes=open("Fileforten.txt", O_RDWR|O_CREAT);
    
    if(filedes==-1){
    	perror("Failed\n");
    }
    else{
    	printf("File opened\n");
    }
    //lseek(filedes, 0L, SEEK_SET);
    
    char buf[10]="Hello itter\n";
    int char_write = write(filedes, buf, 10);
    printf("write 1st 10 bytes : %d \n",char_write);
    
    int lseekreturn = lseek(filedes, 10, SEEK_CUR);
    printf("lseek return value: %d \n",lseekreturn);
    
    int char_write2 = write(filedes, buf, 10);
    printf("write 2nd 10 byte: %d \n",char_write2);


return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 10.c -o 10
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./10
File opened
write 1st 10 bytes : 10 
lseek return value: 20 
write 2nd 10 byte: 10 
*/