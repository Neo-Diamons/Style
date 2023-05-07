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

    #include "list.h"

    #define ALLOC_SIZE      4096

    #define COLOR_RED       31
    #define COLOR_ORANGE    93
    #define COLOR_BLUE      34

//
// Structs
//

typedef struct parser_s {
    char *file;
    char *line;
    char *type;
    char *error;
} parser_t;

    #define PFILE    parser->file
    #define PLINE    parser->line
    #define PTYPE    parser->type
    #define PERROR   parser->error

    #define FORMAT  "\033[%im[%-5s:%s] \033[36m[Lines:%3s]\033[0m %s\n"
    #define PRINT_ERROR(color) \
        printf(FORMAT, color, PTYPE, PERROR, PLINE, PFILE)

typedef struct errors_s {
    list_t *major;
    list_t *minor;
    list_t *info;
    char **lines;
} errors_t;

    #define MAJOR   errors->major
    #define MINOR   errors->minor
    #define INFO    errors->info

    #define LINES   errors->lines

//
// Functions
//

bool style(char *filepath);

char *get_file(char *filename);

char **strsplit(char *str, char *delim);

char **get_ignored(void);

errors_t *get_errors(char *filepath);

parser_t *get_parser(char *line);

void destroy_tab(char **tab);

void destroy_errors(errors_t *errors);

#endif /* !STYLE_STYLE_H */
