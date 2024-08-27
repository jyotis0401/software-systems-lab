#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main(){
    int a= open("fileopen5",O_RDWR|O_CREAT);
    // if(a==-1) printf("Error");
    // else{
        printf("The file descriptor: %d\n",a);
    // }
    int b= open("fileopen5",O_EXCL|O_CREAT);
    printf("The file already exists so we get %d \n", b);
    return 0;
}

/*(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 4.c -o 4
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./4
The file descriptor: 3
The file already exists so we get -1 */