/*
 * File: 102-zombie.c
 * Auth: Mathew Kipronoh
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * infinite_while - Run an infinite while loop.
 *
 * Return: Always 0.
 */
int infinite_while(void)
{
    while (1)
    {
        sleep(1); /* Sleep for one second, creating a 
        loop that runs indefinitely. */
    }
    return (0);
}

/**
 * main - Creates five zombie processes.
 *
 * Return: Always 0.
 */
int main(void)
{
    pid_t pid;
    char count = 0;

    while (count < 5)
    {
        pid = fork(); /* Create a child process using the fork system call. */
        if (pid > 0)
        {
            /* Parent process branch. */
            printf("Zombie process created, PID: %d\n", pid); /* Print a message with the 
            PID of the child process. */
            sleep(1); /* Sleep for one second before creating 
            the next child process. */
            count++; /* Increment the count of child processes created. */
        }
        else
        {
            /* Child process branch. */
            exit(0); /* The child process exits, becoming a zombie. 
            (Exit status not collected by the parent.) */
        }
    }

    infinite_while(); /* Enter an infinite loop to keep the program running. */

    return (EXIT_SUCCESS); /* Return success status. */
}
