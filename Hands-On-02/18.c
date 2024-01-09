/*
============================================================================
Name : 18.c
Author : Ajay Gidd
Description : Write a program to find out total number of directories on 
    the pwd. Execute ls -l | grep ^d | wc ? Use only dup2.
Date: 17th Oct, 2023.
============================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
int main(){
    int pipe1_fd[2], pipe2_fd[2];
    int status = pipe(pipe1_fd);
    if(status < 0){
        printf("Error while creating pipe.\n");
        return -1;
    }
    status = pipe(pipe2_fd);
    if(status < 0){
        printf("Error while creating pipe.\n");
        return -1;
    }
    int pid = fork();
    if(pid == 0){
        int pid2 = fork();
        if(pid2 == 0){
            close(pipe1_fd[0]);
            close(pipe2_fd[0]);
            close(pipe2_fd[1]);
            dup2(pipe1_fd[1], STDOUT_FILENO);
            execl("/usr/bin/ls", "ls -l", "-l", NULL);
        }
        else{
            close(pipe1_fd[1]);
            close(pipe2_fd[0]);
            dup2(pipe1_fd[0], STDIN_FILENO);
            dup2(pipe2_fd[1], STDOUT_FILENO);
            execl("/usr/bin/grep", "grep ^d", "^d", NULL);
        }
    }
    else{
        close(pipe2_fd[1]);
        close(pipe1_fd[0]);
        close(pipe1_fd[1]);
        dup2(pipe2_fd[0], STDIN_FILENO);
        execl("/usr/bin/wc", "wc", NULL);
    }
    return 0;
}
