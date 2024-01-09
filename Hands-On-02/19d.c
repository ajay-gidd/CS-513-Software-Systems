/*
============================================================================
Name : 19d.c
Author : Ajay Gidd
Description: Create a FIFO file by
d. mknod system call
Date: 19/10/2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdio.h>

int main() {
    if (mknod("./fifo1", S_IFIFO | 0666, 0) == -1) {
        perror("mknod");
        return 1;
    } else {
        printf("FIFO 'fifo1' created successfully.\n");
    }

    return 0;
}

