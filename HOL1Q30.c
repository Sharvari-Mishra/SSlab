/*
============================================================================
Name : Q30.c
Author : Sharvari Mishra
Description : Write a program to run a script at a specific time using a Daemon process.
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define SCRIPT_PATH "/home/sharvari/sslab/Q30Demo.sh" 

void executeScript() {
    pid_t child_pid;

    child_pid = fork();

    if (child_pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (child_pid == 0) {
        execl("/bin/sh", "sh", SCRIPT_PATH, (char *)NULL);
        perror("execl");
        exit(EXIT_FAILURE);
    } else{
        wait(NULL);  
    }
}

int main() {

    pid_t pid, sid;
    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);  
    sid = setsid(); 

    if (sid < 0) {
        perror("setsid");
        exit(EXIT_FAILURE);
    }

  
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

   
    struct tm target_time = {0};
    target_time.tm_hour = 10;  
    target_time.tm_min =22;   

    while (1) {
        time_t current_time = time(NULL);
        struct tm *local_time = localtime(&current_time);

        if (local_time->tm_hour == target_time.tm_hour &&
            local_time->tm_min == target_time.tm_min){ 
            executeScript();
        }

       
        sleep(60);
    }

    return 0;
}

