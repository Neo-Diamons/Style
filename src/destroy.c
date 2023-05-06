/*
** EPITECH PROJECT, 2023
** Style
** File description:
** destroy.c
*/

#include <malloc.h>
#include <stdint.h>

static void free_tab(char **tab)
{
    for (uint32_t i = 0; tab[i]; i++)
        free(tab[i]);
    free(tab);
}

void destroy(char *buffer, char ***tabs)
{
    free(buffer);
    for (uint32_t i = 0; tabs[i]; i++)
        free_tab(tabs[i]);
}
