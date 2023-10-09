/*
============================================================================
Name : Q27.c
Author : Sharvari Mishra
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp
Date: 9th Sep, 2023.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
	/*
    execl("/bin/ls", "ls", "-Rl", NULL);
    perror("execl"); 

   
    execlp("ls", "ls", "-Rl", NULL);
    perror("execlp");

    char* envp[] = { "PATH=/bin", NULL };
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    perror("execle");
    return 1;
    
    char *cmd[]={"ls","-RL",NULL};
    execv("/bin/ls",cmd);
    perror("execv");
    return(EXIT_FAILURE);*/

    char *cmd[]={"ls","-RL",NULL};
    execvp("ls",cmd);
    perror("execvp");
    return(EXIT_FAILURE);



}

