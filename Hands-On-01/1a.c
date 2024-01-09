/*
============================================================================
Name : 1a.c
Author : Ajay Gidd
Description :  Create the following types of a files using system call
a. soft link (symlink system call)
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(int argc, char *argv[])
{

    char *sourceFile;     
    char *softLinkPath; 

    int stat; 

    if (argc != 3)
        printf("Give required arguments\n");
    else
    {
        sourceFile = argv[1];
        softLinkPath = argv[2];

        stat = symlink(sourceFile, softLinkPath);

        if (status == -1)
            perror("Error while creating soft link!");
        else
            printf("Successfully created a soft link.\n");
    }
}
