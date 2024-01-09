/*
============================================================================
Name : 4.c
Author : Ajay Gidd
Description :  Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 09th Sep, 2023.
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int fd_of_files[5];
    fd_of_files[0] = open("Ajay/Hands-On-List-1/P5/files/file1.txt", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[1] = open("Ajay/Hands-On-List-1/P5/files/file2.txt", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[2] = open("Ajay/Hands-On-List-1/P5/files/file3.txt", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[3] = open("Ajay/Hands-On-List-1/P5/files/file4.txt", O_RDWR | O_CREAT | O_EXCL);
    fd_of_files[4] = open("Ajay/Hands-On-List-1/P5/files/file5.txt", O_RDWR | O_CREAT | O_EXCL);
    int cnt = 4;
    while (cnt != -1)
    {
        if (fd_of_files[cnt] == -1) {
            perror("Error opening or creating file");
            return 1;
        }
        cnt--;
    }
    
    getchar();
    
    return 0;
}
