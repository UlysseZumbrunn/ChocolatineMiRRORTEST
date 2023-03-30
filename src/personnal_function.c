/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell1-ulysse.zumbrunn
** File description:
** personnal_function
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

int my_putstr(char const *str)
{
    for (int u = 0; str[u] != '\0'; u++)
        my_putchar(str[u]);
}

char *my_strdup(char const *src)
{
    char *dest = NULL;
    int i = 0;

    if (src == NULL)
        return (NULL);
    dest = malloc(sizeof(char) * (my_strlen(src) + 1));
    if (dest == NULL) {
        my_putstr("Error : malloc fail");
        return (NULL);
    }
    for (; dest && src[i]; i++) {
        dest[i] = src[i];
        dest[i + 1] = '\0';
    }
    return (dest);
}
