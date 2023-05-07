/*
** EPITECH PROJECT, 2022
** Style
** File description:
** get_parser.c
*/

#include <malloc.h>

#include "style.h"

static ssize_t get_area_len(const char *line)
{
    ssize_t i = 0;

    for (; line[i] && line[i] != ':'; i++);
    return (line[i] == ':') ? i : -1;
}

static char *get_area(char *line, ssize_t *offset)
{
    ssize_t len = get_area_len(line + *offset);

    if (len == -1) {
        *offset = 0;
        return NULL;
    }
    *offset += len;
    line[(*offset)++] = '\0';
    return line + *offset - len - 1;
}

parser_t *get_parser(char *line)
{
    parser_t *parser = malloc(sizeof(parser_t));
    ssize_t offset = 0;

    if (!parser)
        return NULL;
    parser->file = get_area(line, &offset);
    parser->line = (offset) ? get_area(line, &offset) : NULL;
    parser->type = (offset) ? get_area(line, &offset) + 1 : NULL;
    parser->error = (offset) ? line + offset : NULL;
    return (offset) ? parser : NULL;
}
