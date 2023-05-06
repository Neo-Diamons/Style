/*
** EPITECH PROJECT, 2023
** Style
** File description:
** style.c
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#include "style.h"

static bool is_ignore(char *error)
{
    for (uint8_t i = 0; ignore[i]; i++)
        if (strstr(error, ignore[i]))
            return true;
    return false;
}

static void parse_line(char **lines, char *element, int color)
{
    char *c;
    char *error;

    for (uint32_t i = 0; lines[i]; i++) {
        error = strstr(lines[i], element);
        if (!error || is_ignore(lines[i]))
            continue;
        c = strchr(lines[i], ':');
        *c = '\0';
        *strchr(++c, ':') = '\0';
        printf("\033[%im[%-10s] \033[36m[Lines:%3s]\033[0m %s\n",
            color, error, c, lines[i]);
        lines[i][0] = '\0';
    }
}

bool style(char *filepath)
{
    char *content = get_file(filepath);
    char **lines = (content) ? strsplit(content, "\n") : NULL;

    if (!lines)
        return false;
    parse_line(lines, "MAJOR", 31);
    parse_line(lines, "MINOR", 93);
    parse_line(lines, "INFO", 34);
    destroy(content, lines);
    return true;
}
