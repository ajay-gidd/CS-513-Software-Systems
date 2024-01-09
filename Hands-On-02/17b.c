/*
============================================================================
Name : 17b.c
Author : Ajay Gidd
Description : Write a program to execute ls -l | wc.
    b. use dup2
Date: 17th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    int fd[2];
    int status = pipe(fd);
    if(status < 0){
        printf("Error while creating pipe.\n");
        return -1;
    }
    int pid = fork();
    if(pid == 0){
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        execl("/usr/bin/ls", "ls -l", "-l", NULL);
    }
    else{
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        execl("/usr/bin/wc", "wc", NULL);
    }
    return 0;
}
