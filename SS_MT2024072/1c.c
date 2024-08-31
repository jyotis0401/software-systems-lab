//c. FIFO (mkfifo Library Function or mknod system call)

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
int main(){
    int m=mkfifo("fifofile",0666);
    if(m==0) printf("Library");
    int c=mknod("namedpipe",S_IFIFO,0);
    if(c==0) printf("pipe using system call");

    return 0;
}

//output]
//7813402 prw-r--r--  1 jyotisingh  staff     0 Aug 24 13:57 fifofile
//7813891 p---------  1 jyotisingh  staff     0 Aug 24 15:46 namedpipe
