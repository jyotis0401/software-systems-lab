/*
Name: 21b.c
Author: MT2024072
Description: Two programs so that both can communicate by FIFO -Use two way communication. (i)
Date: 19 sep 2024
 */
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd1;
    mkfifo("21fifo", 0666);

    char str1[80], str2[80];
    while (1)
    {
        // First open in read only and read
        fd1 = open("21fifo",O_RDONLY);
        read(fd1, str1, 80);

        // Print the read string and close
        printf("User1: %s\n", str1);
        close(fd1);

        // Now open in write mode and write
        // string taken from user.
        fd1 = open("21fifo",O_WRONLY);
        fgets(str2, 80, stdin);
        write(fd1, str2, strlen(str2)+1);
        close(fd1);
    }
    return 0;
}