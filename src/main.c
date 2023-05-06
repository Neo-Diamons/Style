/*
** EPITECH PROJECT, 2023
** Style
** File description:
** style.c
*/

#include "style.h"

int main(int ac, char **av)
{
    return (ac == 2 && style(av[1])) ? 0 : 84;
}
