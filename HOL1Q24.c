/*
============================================================================
Name : Q24.c
Author : Sharvari Mishra
Description : Write a program to create an orphan process.
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include<stdio.h>

int main(){
        pid_t p;
        p=fork();
        if (p==0){
                sleep(30);
                printf("I am child having PID: %d\n", getpid());
                printf("My parent PID is %d\n",getppid());
               // exit(0);

        }
        else{
                printf("I am parent having PID:%d\n",getpid());
                printf("My child PID is %d\n",p);
                exit(0);

        }
        return 0;
}

