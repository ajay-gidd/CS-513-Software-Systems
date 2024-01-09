/*
============================================================================
Name : 4.c
Author : Ajay Gidd
Description :  Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 09th Sep, 2023.
============================================================================
*/
#include<stdio.h>
//#include<fildes.h>
#include<fcntl.h>

void main(int argc, char *argv[])
{

    char *fileName;
    int fd; 

    if (argc != 2)
        printf("Pass the file to be opened as the argument\n");
    else
    {
        fileName = argv[1];

        fd = open(fileName, O_RDWR);

        if (fd == -1)
            perror("Error opening the file");
        else
            printf("file created successfully  with the file descriptor : %dn", fd);
    }
}

