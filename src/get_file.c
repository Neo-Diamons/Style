/*
** EPITECH PROJECT, 2023
** Style
** File description:
** get_file.c
*/

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <sys/stat.h>

#include "style.h"

static char *get_filepath(char *filepath, char *filename)
{
    char pwd[ALLOC_SIZE] = {0};

    getcwd(pwd, ALLOC_SIZE);
    sprintf(filepath, "%s/%s", pwd, filename);
    return filepath;
}

char *get_content(char *filepath)
{
    FILE *file = fopen(filepath, "r");
    struct stat st;
    char *content;

    if (!file || stat(filepath, &st) || !S_ISREG(st.st_mode))
        return NULL;
    content = malloc(sizeof(char) * (st.st_size + 1));
    if (fread(content, sizeof(char), st.st_size, file) <= 1
        || fclose(file) || !content)
        return NULL;
    content[st.st_size] = '\0';
    return content;
}

char *get_file(char *filename)
{
    char filepath[ALLOC_SIZE];

    return get_content(get_filepath(filepath, filename));
}
