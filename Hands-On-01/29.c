/*
============================================================================
Name : 29.c
Author : Ajay Gidd
Description :  Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 09th Sep, 2023.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

int main() {
    // Get the current scheduling policy 
    int policy = sched_getscheduler(0);
    struct sched_param param;
    sched_getparam(0, &param);

    printf("Current Scheduling Policy: ");
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown (%d)\n", policy);
    }

    printf("Current Priority: %d\n", param.sched_priority);

    // Change the scheduling policy
    int new_policy = SCHED_FIFO; 
    param.sched_priority = 99;   

    if (sched_setscheduler(0, new_policy, &param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    
    policy = sched_getscheduler(0);
    sched_getparam(0, &param);

    printf("New Scheduling Policy: ");
    switch (policy) {
        case SCHED_FIFO:
            printf("SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("SCHED_OTHER\n");
            break;
        default:
            printf("Unknown (%d)\n", policy);
    }

    printf("New Priority: %d\n", param.sched_priority);

    return 0;
}
