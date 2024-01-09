/*
============================================================================
Name : 3.c
Author : Ajay Gidd
Description :  Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc, char *argv[])
{

    char *sourceFile;
    int fd; 

    if (argc != 2)
        printf("Source File Name\n");
    else
    {
        sourceFile = argv[1];

        fd = creat(sourceFile, S_IRWXU);

        if (fd == -1)
            perror("Error while creating the file!");
        else
            printf("file created successfully with the file descriptor : %dn", fd);
    }
}

