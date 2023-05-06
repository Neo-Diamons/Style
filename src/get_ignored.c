/*
** EPITECH PROJECT, 2022
** Style
** File description:
** get_ignored.c
*/

#include <malloc.h>

#include "style.h"

char **get_ignored(void)
{
    char *content = get_file(".styleignore");
    char **lines = (content) ? strsplit(content, "\n") : NULL;

    if (!lines)
        return NULL;
    free(content);
    return lines;
}
