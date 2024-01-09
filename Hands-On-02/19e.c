/*
============================================================================
Name : 19e.c
Author : Ajay Gidd
Description: Create a FIFO file by
 e. mkfifo library function
Date: 19/10/2023
============================================================================
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>

int main() {
    if (mkfifo("./myfifo", 0666) == -1) {
        printf("Error creating FIFO: %s\n", strerror(errno));
        return 1;
    } else {
        printf("FIFO 'myfifo' created successfully.\n");
    }

    return 0;
}

