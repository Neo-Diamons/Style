/*
** EPITECH PROJECT, 2022
** style
** File description:
** get_errors.c
*/

#include <malloc.h>
#include <string.h>

#include "style.h"

static errors_t *get_struct(void)
{
    errors_t *errors = malloc(sizeof(errors_t));

    if (!errors)
        return NULL;
    errors->major = list_create();
    errors->minor = list_create();
    errors->info = list_create();
    return (errors->major && errors->minor && errors->info) ? errors : NULL;
}

static bool is_ignore(char **ignore, char *line)
{
    for (uint8_t i = 0; ignore[i]; i++)
        if (strstr(line, ignore[i]))
            return true;
    return false;
}

static bool add_errors(errors_t *errors, char *line)
{
    parser_t *parser = get_parser(line);

    if (!parser)
        return false;
    if (!strcmp(parser->type, "MAJOR"))
        return list_add(MAJOR, parser);
    if (!strcmp(parser->type, "MINOR"))
        return list_add(MINOR, parser);
    if (!strcmp(parser->type, "INFO"))
        return list_add(INFO, parser);
    return true;
}

static bool search_errors(errors_t *errors, char **lines, char **ignore)
{
    for (uint32_t i = 0; lines[i]; i++) {
        if (is_ignore(ignore, lines[i]))
            continue;
        if (!add_errors(errors, lines[i]))
            return false;
    }
    return true;
}

errors_t *get_errors(char *filepath)
{
    char *content = get_file(filepath);
    char **lines = (content) ? strsplit(content, "\n") : NULL;
    char **ignore = (lines) ? get_ignored() : NULL;
    errors_t *errors = (ignore) ? get_struct() : NULL;

    return (errors && search_errors(errors, lines, ignore)) ? errors : NULL;
}
