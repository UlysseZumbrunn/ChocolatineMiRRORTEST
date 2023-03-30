/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** my_fonction
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "struct.h"
#include "shell.h"
#include "my.h"
#include "constant.h"

int my_builtin_cd(char **args)
{
    if (args[1] == NULL) {
        chdir(my_getenv("HOME"));
    } else if (chdir(args[1]) == -1) {
        perror("cd");
        return 1;
    }
    return 0;
}

int my_builtin_exit(char **args)
{
    exit(0);
}

int my_builtin_cmd(char **args)
{
    const struct builtin *builtin = builtins;

    while (builtin->name != NULL) {
        if (my_strcmp(args[0], builtin->name) == 0) {
            return builtin->func(args);
        }
        builtin++;
    }

    return 0;
}

void recurexecute(char **args)
{
    if (chdir(args[1]) != 0) {
        const char* error_msg = "cd: ";
        const char* error_suffix = ": No such file or directory\n";
        write(STDERR_FILENO, error_msg, my_strlen(error_msg));
        write(STDERR_FILENO, args[1], my_strlen(args[1]));
        write(STDERR_FILENO, error_suffix, my_strlen(error_suffix));
    }
}

char* my_getenv(const char* path)
{
    extern char** environ;
    size_t file = my_strlen(path);
    char** i = environ;
    while (*i != NULL) {
        if (my_strncmp(*i, path, file) == 0 && (*i)[file] == '=') {
            return &((*i)[file + 1]);
        }
        ++i;
    }
    return NULL;
}
