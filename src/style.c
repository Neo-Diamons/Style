/*
** EPITECH PROJECT, 2023
** Style
** File description:
** style.c
*/

#include <stdio.h>

#include "style.h"

static void print_majors(parser_t *parser)
{
    printf("\033[%im[%-5s:%s] \033[36m[Lines:%3s]\033[0m %s\n",
        COLOR_RED, parser->type, parser->error, parser->line, parser->file);
}

static void print_minors(parser_t *parser)
{
    printf("\033[%im[%-5s:%s] \033[36m[Lines:%3s]\033[0m %s\n",
        COLOR_ORANGE, parser->type, parser->error, parser->line, parser->file);
}

static void print_infos(parser_t *parser)
{
    printf("\033[%im[%-5s:%s] \033[36m[Lines:%3s]\033[0m %s\n",
        COLOR_BLUE, parser->type, parser->error, parser->line, parser->file);
}

bool style(char *filepath)
{
    errors_t *errors = get_errors(filepath);

    if (!errors)
        return false;
    if (!errors->major->head && !errors->minor->head && !errors->info->head)
        return printf("\033[32mNo errors found.\033[0m\n") > 0;
    for (list_node_t *major = errors->major->head; major; major = major->next)
        print_majors((parser_t *)major->value);
    for (list_node_t *minor = errors->minor->head; minor; minor = minor->next)
        print_minors((parser_t *)minor->value);
    for (list_node_t *info = errors->info->head; info; info = info->next)
        print_infos((parser_t *)info->value);
    return true;
}
