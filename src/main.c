/*
** EPITECH PROJECT, 2023
** Style
** File description:
** main.c
*/

#include "style.h"

int main(int ac, char **av)
{
    return (ac == 3 && style(av[1], av[2])) ? 0 : 84;
}
