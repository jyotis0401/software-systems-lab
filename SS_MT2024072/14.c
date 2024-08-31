/*
============================================================================
Name : 14.c
Author : Jyoti Singh
Description : Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 26th Aug, 2024.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main(int argc, char *argv[]){
if(argc!=2){
		printf("Enter one argument\n");
	}


    struct stat info;

	stat(argv[1],&info);
	//we have to do and operation to get the mode
	int stat_info=info.st_mode & S_IFMT; 

    /*
    The status information word st_mode has the following bits:

    //  #define S_IFMT 0170000           //* type of file */
    //  #define        S_IFIFO  0010000  //* named pipe (fifo) */
    //  #define        S_IFCHR  0020000  //* character special */
    //  #define        S_IFDIR  0040000  //* directory */
    //  #define        S_IFBLK  0060000  //* block special */
    //  #define        S_IFREG  0100000  //* regular */
    //  #define        S_IFLNK  0120000  //* symbolic link */
    //  #define        S_IFSOCK 0140000  //* socket */
    //  #define        S_IFWHT  0160000  //* whiteout */
    //  #define S_ISUID 0004000  //* set user id on execution */
    //  //#define S_ISGID 0002000  ///* set group id on execution */
    //  //#define S_ISVTX 0001000  ///* save swapped text even after use */
    //  //#define S_IRUSR 0000400  ///* read permission, owner */
    //  //#define S_IWUSR 0000200  ///* write permission, owner */
    //  //#define S_IXUSR 0000100  //execute/search permission, owner 
    // */
    
	

	switch(stat_info) {
		case S_IFBLK:
			printf("Block file\n");
			break;
		case S_IFCHR:
			printf("Character device\n");
			break;
		case S_IFDIR:
			printf("Directory\n");
			break;
		case S_IFIFO:
			printf("FIFO\n");
			break;
		case S_IFLNK:
			printf("Symlink\n");
			break;
		case S_IFREG:
			printf("Regular\n");
			break;
		case S_IFSOCK:
			printf("Socket\n");
			break;
		default:
			printf("Unknow\n");
			break;
	}


 return 0;
}

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 14.c -o 14
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./14 1a.c
Regular
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./14 ../Gate_new_CS.pdf
Regular

*/