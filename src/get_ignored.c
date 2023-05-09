/*
** EPITECH PROJECT, 2022
** Style
** File description:
** get_ignored.c
*/

#include <malloc.h>

#include "style.h"

char **get_ignored(char *path)
{
    char filepath[ALLOC_SIZE];
    char *content;
    char **lines;

    snprintf(filepath, ALLOC_SIZE, "%s/.styleignore", path);
    content = get_file(filepath);
    lines = (content) ? strsplit(content, "\n") : NULL;
    if (!lines)
        return NULL;
    free(content);
    return lines;
}
