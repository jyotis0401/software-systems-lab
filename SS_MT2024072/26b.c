/*
============================================================================
Name :26.c
Author : Jyoti Singh
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 30th Aug, 2024.
============================================================================
*/

//execl function, which replaces the current process image with a new process image specified by the given path and argument list.
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>

int main(){

    printf("BEFORE\n");
    execl("/bin/ls", "ls","-l",NULL); //long listing argument passed
    printf("AFTER\n"); //after not printed
return 0;
}\

/*
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ gcc 26b.c
(base) Jyotis-MacBook-Air:SystemsSoftware jyotisingh$ ./a.out
BEFORE
total 648
-rwxr-xr-x  1 jyotisingh  staff  8740 Aug 29 14:43 10
-rw-r--r--  1 jyotisingh  staff  1390 Aug 29 14:46 10.c
-rwxr-xr-x  1 jyotisingh  staff  8828 Aug 29 17:08 11
-rw-r--r--  1 jyotisingh  staff  1683 Aug 30 11:42 11.c
-rwxr-xr-x  1 jyotisingh  staff  8520 Aug 29 15:21 12
-rw-r--r--  1 jyotisingh  staff   955 Aug 30 11:43 12.c
-rwxr-xr-x  1 jyotisingh  staff  8584 Aug 29 16:10 13
-rw-r--r--  1 jyotisingh  staff  1004 Aug 30 11:44 13.c
-rwxr-xr-x  1 jyotisingh  staff  8496 Aug 29 16:31 14
-rw-r--r--  1 jyotisingh  staff  2438 Aug 30 11:44 14.c
-rw-r--r--  1 jyotisingh  staff  1827 Aug 29 18:48 15.c
-rw-r--r--  1 jyotisingh  staff  2467 Aug 30 12:18 16.c
-rw-r--r--  1 jyotisingh  staff  1478 Aug 30 23:14 17.c
-rw-r--r--  1 jyotisingh  staff   876 Aug 30 23:14 17ticket.c
-rw-r--r--  1 jyotisingh  staff  1908 Aug 30 23:15 18.c
-rw-r--r--  1 jyotisingh  staff   844 Aug 30 23:15 18ticket.c
-rw-r--r--  1 jyotisingh  staff  1245 Aug 30 22:09 19.c
-rw-r--r--  1 jyotisingh  staff  1365 Aug 29 09:56 1a.c
-rw-r--r--  1 jyotisingh  staff   210 Aug 22 16:50 1aSys.c
-rw-r--r--  1 jyotisingh  staff   864 Aug 29 09:58 1b.c
-rw-r--r--  1 jyotisingh  staff   491 Aug 24 15:49 1c.c
-rwxr-xr-x  1 jyotisingh  staff  4248 Aug 29 13:58 2
-rw-r--r--  1 jyotisingh  staff    66 Aug 29 13:57 2.c
-rw-r--r--  1 jyotisingh  staff  1343 Aug 30 22:14 20.c
-rw-r--r--  1 jyotisingh  staff  1571 Aug 30 22:39 21.c
-rw-r--r--  1 jyotisingh  staff  1585 Aug 30 23:18 22.c
-rw-r--r--  1 jyotisingh  staff  1151 Aug 30 23:17 23.c
-rw-r--r--  1 jyotisingh  staff  1324 Aug 30 23:22 24.c
-rw-r--r--  1 jyotisingh  staff  2772 Aug 30 23:34 25.c
-rw-r--r--  1 jyotisingh  staff  1442 Aug 31 10:42 26.c
-rw-r--r--  1 jyotisingh  staff  1441 Aug 31 10:43 26a.c
-rw-r--r--  1 jyotisingh  staff   822 Aug 31 10:45 26b.c
-rwxr-xr-x  1 jyotisingh  staff  8480 Aug 27 16:39 3
-rw-r--r--  1 jyotisingh  staff  1064 Aug 29 10:00 3.c
-rwxr--r--  1 jyotisingh  staff     0 Aug 27 16:39 31file
-rwxr--r--  1 jyotisingh  staff     0 Aug 27 16:39 32file
-rwxr--r--  1 jyotisingh  staff     0 Aug 27 16:39 33file
-rwxr--r--  1 jyotisingh  staff     0 Aug 27 16:39 3file
-rwxr-xr-x  1 jyotisingh  staff  8480 Aug 27 17:57 4
-rw-r--r--  1 jyotisingh  staff   846 Aug 29 10:03 4.c
-rw-r--r--  1 jyotisingh  staff     0 Aug 26 18:45 5.c
-rwxr-xr-x  1 jyotisingh  staff  8644 Aug 26 19:13 6
-rw-r--r--  3 jyotisingh  staff   919 Aug 29 10:03 6.c
-rwxr-xr-x  1 jyotisingh  staff  8828 Aug 27 19:32 7
-rw-r--r--  1 jyotisingh  staff     0 Aug 27 17:09 7.
-rw-r--r--  1 jyotisingh  staff  1672 Aug 29 10:03 7.c
----------  1 jyotisingh  staff   400 Aug 27 18:17 7write
-rwx------  1 jyotisingh  staff  1081 Aug 27 19:34 7writefile
-rwxr-xr-x  1 jyotisingh  staff  8860 Aug 29 10:30 8
-rw-r--r--  1 jyotisingh  staff  1810 Aug 29 10:30 8.c
-rwxr-xr-x  1 jyotisingh  staff  8584 Aug 29 11:16 9
-rw-r--r--  1 jyotisingh  staff  3126 Aug 29 11:17 9.c
--w-r-x---  1 jyotisingh  staff    30 Aug 29 14:39 Fileforten
-rwxrwxrwx  1 jyotisingh  staff    30 Aug 29 17:22 Fileforten.txt
-rwxr-xr-x  1 jyotisingh  staff  8480 Aug 31 10:45 a.out
-rwxrwxrwx  1 jyotisingh  staff   129 Aug 29 17:27 duplicatefd.txt
-rw-r--r--  1 jyotisingh  staff     0 Aug 22 12:28 f1cler
-rw-r--r--  2 jyotisingh  staff     0 Aug 22 12:21 f2
prw-r--r--  1 jyotisingh  staff     0 Aug 24 13:57 fifofile
-rw-r--r--@ 1 jyotisingh  staff   126 Aug 29 10:27 file
---xr-x---  1 jyotisingh  staff     0 Aug 26 18:35 fileopen1
--wx------  1 jyotisingh  staff     0 Aug 26 18:43 fileopen5
-rw-r--r--  1 jyotisingh  staff    37 Aug 30 22:43 fileoutput
p---------  1 jyotisingh  staff     0 Aug 24 15:46 namedpipe
lrwxr-xr-x  1 jyotisingh  staff     3 Aug 29 10:48 sofrfilelink.txt -> 6.c
-rw-r--r--  2 jyotisingh  staff     0 Aug 22 12:21 softf2.txt
-rw-r--r--  3 jyotisingh  staff   919 Aug 29 10:03 somelinkfile.txt
-rw-r--r--  3 jyotisingh  staff   919 Aug 29 10:03 somelinkfile2.txt
lrwxr-xr-x  1 jyotisingh  staff     2 Aug 22 16:50 symlinkf2 -> f2*/