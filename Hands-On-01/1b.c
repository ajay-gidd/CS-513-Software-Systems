/*
============================================================================
Name : 1b.c
Author : Ajay Gidd
Description :  Create the following types of a files using system call
b. hard link (link system call)
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(int argc, char *argv[])
{

    char *sourceFile;     
    char *hardLinkPath; 

    int stat; 

    if (argc != 3)
        printf("Enter the required arguments\n");
    else
    {
        sourceFile = argv[1];
        softLinkPath = argv[2];

        status = symlink(sourceFile, hardLinkPath);

        if (stat == -1)
            perror("Error while creating hard link");
        else
            printf("Successfully created a hard link.\n");
    }
}

