/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** gest_process step 3
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "shell.h"
#include "my.h"
#include "constant.h"

void exit_cmd(int status, char *buf, int *n)
{
    if (status >= 10) {
        exit_cmd(status / 10, buf, n);
    }
    buf[(*n)++] = (status % 10) + '0';
}

int my_cmd_execute(char **argv, int status)
{
    pid_t pid;
    pid = fork();
    switch (pid) {
        case -1:
            perror("fork");
            return EXIT_FAILURE;
        case 0:
            if (execve(argv[0], argv, NULL) == -1) {
                perror("execve");
                exit(EXIT_FAILURE);
            }
            break;
        default:
            if (waitpid(pid, &status, 0) == -1) {
                perror("waitpid");
                return EXIT_FAILURE;
            }
            break;
    }
    return EXIT_SUCCESS;
}
