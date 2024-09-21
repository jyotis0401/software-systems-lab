/*
Name: 34fork.c
Author: MT2024072
Description: Program to create a concurrent server using fork.
Date: 21 sep 2024
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

    struct sockaddr_in serv, cli;
    
    serv.sin_family = AF_INET;
    serv.sin_addr.s_addr = INADDR_ANY;
    serv.sin_port = htons(5555);

    int opt = 1;
    if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))){
        perror("Error: ");
        return -1;
    }

    if (bind(sockfd, (struct sockaddr *)&serv, sizeof(serv)) == -1){
        perror("Error: ");
        return -1;
    }

    if (listen(sockfd, 5) == -1){
        perror("Error: ");
        return -1;
    }

    int size = sizeof(cli);

    char buf[80];
    while (1){

        int new_fd = accept(sockfd, (struct sockaddr *)&cli, &size);
        if (new_fd == -1){
            perror("Error: ");
            return -1;
        }

        if (!fork()){
            
            close(sockfd);
            read(new_fd, buf, sizeof(buf));
            printf("Message from client: %s", buf);
            write(new_fd, "ACK\n", sizeof("ACK\n"));
            getchar();
            close(new_fd);

        }else{
            close(new_fd);
        }
        
    }

}