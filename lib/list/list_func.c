/*
** EPITECH PROJECT, 2022
** style
** File description:
** list_func.c
*/

#include "list.h"

bool list_func(list_t *list, bool (*func)(void *))
{
    for (list_node_t *node = list->head; node; node = node->next)
        if (!func(node->value))
            return false;
    return true;
}
