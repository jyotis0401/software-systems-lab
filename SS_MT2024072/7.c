

/*
============================================================================
Name : 7.c
Author : Jyoti Singh
Description : Write a program to copy file1 into file2 ($cp file1 file2).
Date: 26th Aug, 2024.
============================================================================
*/

#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
//int main(){
    // int a=open("1a.c",O_RDWR);
    // // printf("%d",a);
    // int buff[100];
    // int b= read(a,buff,sizeof(buff));
    // int c=open("7write",O_RDWR|O_CREAT);

    //  int d=write(c,buff,b);
    //  printf("Done copying");



 //   return 0;
//}

int main(int argc, char *argv[]){
    int fileopen1=open(argv[1],O_RDONLY);
    if(fileopen1<0){
        perror("status");
        exit(0);
    }
    int fileopen2=open(argv[2],O_WRONLY|O_EXCL|O_CREAT, 0700);
    if(fileopen2<0){
        perror("staus");
        exit(0);
    }
    int buff[1024];
    int size;
    // int size=read(fileopen1,buff,sizeof(buff));
    //because our buffer size can be small than th efile size so we need a while loop to overwrite
    while((size=read(fileopen1,buff,sizeof(buff))) > 0){
        write(fileopen2,buff,size);
    }
    
    printf("File descriptor of fileopen1 is: %d\t", fileopen1);
	printf("File descriptor of fileopen2 is: %d\t", fileopen2);
	close(fileopen1);
	close(fileopen2);
	return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 7.c -o 7
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./7
status: Bad address
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./7 1a.c 7writefile
File descriptor of fileopen1 is: 3	File descriptor of fileopen2 is: 4
*/
