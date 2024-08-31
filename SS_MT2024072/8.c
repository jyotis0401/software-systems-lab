/*
============================================================================
Name : 8.c
Author : Jyoti Singh
Description : Write a program to open a file in read only mode, read line by line and 
display each line as it is read. Close the file when end of file is reached.
Date: 26th Aug, 2024.
============================================================================
*/



#include<stdio.h>
#include<errno.h>
#include<stdlib.h>

#include<unistd.h>
const char EOL ='\n';

int main(){
FILE *fd = fopen("file","r"); //opening the file
if(fd == NULL){ // checking if file opened successfully
 perror("program");
 exit(0);
}
int c=fgetc(fd); //reading a character
char buffer[1024]; //initializing a buffer
int k=0; //setting pointer
while(c!=EOF){ // loop for end of file
 while(c!=EOL){ // loop to store till end of file
  buffer[k]=c; // storing character into the buffer
  if(k<1024) k++; // increment buffer
  c=fgetc(fd); //get the next character
}
if(k<1024){
buffer[k]='\n'; // adding end of line at the end of line
k++;}
write(1,buffer,k); // writting each line to the stdout
char str[]="this is to check line by line writing \n ";
write(1,str,sizeof(str));



buffer[0]='\0'; 
c=fgetc(fd); //read next character otherwise it will keep waiting
k=0; // starting from first in the buffer
}
fclose(fd); // closing the file
return 0;
}


/*
Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 8.c -o 8
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./8
HI i am herre. 
this is to check line by line writing 
 /n This is next line i dont know it is working or not
this is to check line by line writing 
 I gave wrong new line. \n
this is to check line by line writing 
  this is the correct new line
this is to check line by line writing 
 (base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ 
*/