/*
** EPITECH PROJECT, 2023
** B-PSU-200-LIL-2-1-minishell2-ulysse.zumbrunn
** File description:
** personnal_fonction_2
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

int my_strcmp(char const *z1,char const *z2)
{
    int j = 0;

    while (z2[j] != '\0' && z1[j] != '\0' && z2[j] == z1[j])
        j++;
            if (z2[j] < z1[j])
        return 1;
    else if (z2[j] > z1[j])
        return -1;
    else
        return 0;
}

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

void my_putchar(char c)
{
    write(1, &c, 1);
}

char *my_strcat(char *first, char *second)
{
    char *ptr = first;
    while (*ptr != '\0') {
        ptr++;
    }
    while (*second != '\0') {
        *ptr++ = *second++;
    }
    *ptr = '\0';
    return first;
}

char *my_strcpy(char *dest, const char *src)
{
    size_t i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
