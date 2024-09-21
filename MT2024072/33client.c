/*
Name: 
Author: MT2024072
Description: Program to communicate between two machines using socket
Date: 20 sep 2024
 */
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <errno.h>

int main(){
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd == -1){
        perror("Error: ");
        return -1;
    }

    struct sockaddr_in serv;
    
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5555);

    if (connect(sockfd, (struct sockaddr *)&serv, sizeof(serv)) == -1){
        perror("Error: ");
        return -1;
    }

    char buf[80];
    
    write(sockfd, "Hello Server\n", sizeof("Hello Server\n"));
    printf("Message sent\n");
    read(sockfd, buf, sizeof(buf));
    printf("Message from server: %s", buf);

    close(sockfd);
    
}
