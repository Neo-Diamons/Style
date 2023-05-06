/*
** EPITECH PROJECT, 2023
** Style
** File description:
** strsplit.c
*/

#include <malloc.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

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

static bool strsplit_fill(char **tab, char *str, uint32_t len, uint32_t i)
{
    tab[i] = malloc(sizeof(char) * (len + 1));
    if (!tab[i])
        return false;
    strncpy(tab[i], str, len);
    tab[i][len] = '\0';
    return true;
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
        if (len == 0) {
            split_count--;
            continue;
        }
        if (!strsplit_fill(tab, str, len, i))
            return NULL;
        str += len + delim_len;
    }
    tab[split_count] = NULL;
    return tab;
}
