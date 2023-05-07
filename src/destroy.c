/*
** EPITECH PROJECT, 2023
** Style
** File description:
** destroy.c
*/

#include <malloc.h>

#include "style.h"

void destroy_tab(char **tab)
{
    for (uint32_t i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void destroy_errors(errors_t *errors)
{
    list_destroy_node(MAJOR, free);
    list_destroy_node(MINOR, free);
    list_destroy_node(INFO, free);
    destroy_tab(LINES);
    free(errors);
}
