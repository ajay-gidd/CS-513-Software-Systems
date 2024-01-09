/*
============================================================================
Name : 19c.c
Author : Ajay Gidd
Description: Create a FIFO file by
 c. use strace command to find out, which command (mknod or mkfifo) is better.
Date: 19/10/2023
============================================================================
*/
/*
    strace -c mknod myfifo p 
    strace -c mkfifo myfifo2

    For creating a FIFO, using mkfifo is generally more convenient and commonly used, as it abstracts away some of the lower-level details that mknod requires. However, if efficiency and performance are critical concerns, using mknod directly might be the better option
*/
