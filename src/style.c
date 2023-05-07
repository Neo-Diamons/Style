/*
** EPITECH PROJECT, 2023
** Style
** File description:
** style.c
*/

#include <stdio.h>

#include "style.h"

static bool print_nb_errors(errors_t *errors)
{
    return printf("\033[%imMAJOR\033[0m: %3lu "
        "| \033[%imMINOR\033[0m: %3lu | \033[%imINFO\033[0m: %3lu\n",
        COLOR_RED, MAJOR->size,
        COLOR_ORANGE, MINOR->size,
        COLOR_BLUE, INFO->size) > 0;
}

static bool print_majors(parser_t *parser)
{
    return PRINT_ERROR(COLOR_RED) > 0;
}

static bool print_minors(parser_t *parser)
{
    return PRINT_ERROR(COLOR_ORANGE) > 0;
}

static bool print_infos(parser_t *parser)
{
    return PRINT_ERROR(COLOR_BLUE) > 0;
}

bool style(char *filepath)
{
    errors_t *errors = get_errors(filepath);

    if (!errors)
        return false;
    if (!errors->major->head && !errors->minor->head && !errors->info->head)
        return printf("\033[32mNo errors found.\033[0m\n") > 0;
    return print_nb_errors(errors)
        && list_func(MAJOR, (bool (*)(void *))print_majors)
        && list_func(MINOR, (bool (*)(void *))print_minors)
        && list_func(INFO, (bool (*)(void *))print_infos);
}
