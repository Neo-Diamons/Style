/*
** EPITECH PROJECT, 2023
** Style
** File description:
** style.h
*/

#ifndef STYLE_STYLE_H
    #define STYLE_STYLE_H

    #include <stddef.h>
    #include <stdbool.h>

    #define ALLOC_SIZE      4096

    #define COLOR_RED       31
    #define COLOR_ORANGE    93
    #define COLOR_BLUE      34

//
// Functions
//

bool style(char *filepath);

char *get_file(char *filename);

char **strsplit(char *str, char *delim);

char **get_ignored(void);

void destroy(char *buffer, char ***tabs);

#endif /* !STYLE_STYLE_H */
