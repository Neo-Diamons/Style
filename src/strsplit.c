/*
** EPITECH PROJECT, 2023
** Style
** File description:
** strsplit.c
*/

#include <malloc.h>
#include <stdint.h>
#include <string.h>

void free_tab(char **tab)
{
    for (uint32_t i = 0 ; tab[i] ; i++)
        free(tab[i]);
    free(tab);
}

static uint32_t strsplit_count(char *str, char *delim, uint32_t delim_len)
{
    uint32_t i = 0;
    uint32_t count = 0;

    for (; str[i] ; i++)
        if (!strncmp(str + i, delim, delim_len)) {
            i += delim_len - 1;
            count++;
        }
    return ++count;
}

static uint32_t strsplit_len(char *str, char *delim, uint32_t delim_len)
{
    uint32_t i = 0;

    for (; str[i] ; i++)
        if (!strncmp(str + i, delim, delim_len))
            return i;
    return i;
}

char **strsplit(char *str, char *delim)
{
    uint32_t len;
    uint32_t split_count = strsplit_count(str, delim, strlen(delim));
    uint32_t delim_len = strlen(delim);
    char **tab = malloc(sizeof(char *) * (split_count + 1));

    if (!tab)
        return NULL;
    for (uint32_t i = 0; i < split_count; i++) {
        len = strsplit_len(str, delim, delim_len);
        tab[i] = malloc(sizeof(char) * (len + 1));
        if (!tab[i])
            return NULL;
        strncpy(tab[i], str, len);
        tab[i][len] = '\0';
        str += len + delim_len;
    }
    tab[split_count] = NULL;
    return tab;
}
