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

    #define ALLOC_SIZE 4096

//
// Structs
//

static const char *ignore[] = {
    "C-O1",
    NULL
};

//
// Functions
//

bool style(char *filepath);

char *get_file(char *filename);

char **strsplit(char *str, char *delim);

void destroy(char *buffer, char **tab);

#endif /* !STYLE_STYLE_H */
