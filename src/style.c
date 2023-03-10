/*
** EPITECH PROJECT, 2023
** style
** File description:
** style.c
*/

#include <stdio.h>
#include <malloc.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/stat.h>

#include "style.h"
#include "ice/macro.h"
#include "ice/string.h"
#include "ice/printf.h"

char *get_filepath(char *filepath, char *filename)
{
    char pwd[1024] = {0};

    getcwd(pwd, 1024);
    ice_sprintf(filepath, "%s/%s", pwd, filename);

    return filepath;
}

char *get_file(char *filepath)
{
    ui_t len;
    FILE *file;
    char *buffer;
    struct stat st;

    ASSERT_RET(stat(filepath, &st) != -1, NULL);

    file = fopen(filepath, "r");
    ASSERT_RET(file != NULL, NULL);

    buffer = malloc(sizeof(char) * (st.st_size + 1));
    buffer[st.st_size] = '\0';

    len = fread(buffer, sizeof(char), st.st_size, file);
    ASSERT_RET(len == st.st_size, NULL);

    return buffer;
}

bool is_ignore(char *error)
{
    for (ui_t i = 0 ; ignore[i] ; i++)
        if (ice_strstr(error, ignore[i]))
            return true;

    return false;
}

void parse_line(char **lines, char *element, int color)
{
    char *c;
    char *k;
    char *error;
    for (ui_t i = 0 ; lines[i] ; i++) {
        error = ice_strstr(lines[i], element);

        if (error == NULL) continue;
        if (is_ignore(lines[i])) continue;

        c = ice_strchr(lines[i], ':');
        *c = '\0';
        k = ice_strchr(++c, ':');
        *k = '\0';
        ice_printf("\e[%im[%-10s] \e[36m[Lines:%3s]\e[0m %s\n",
            color, error, c, lines[i]);
        lines[i][0] = '\0';
    }
}

int main(int ac, char **av)
{
    char *buffer;
    char **lines;
    char filepath[1024] = {0};

    ASSERT_RET(ac == 2, 84);

    get_filepath(filepath, av[1]);
    buffer = get_file(filepath);

    lines = ice_strsplit(buffer, "\n");
    parse_line(lines, "MAJOR", 31);
    parse_line(lines, "MINOR", 93);
    parse_line(lines, "INFO", 34);

    for (ui_t i = 0 ; lines[i] ; i++)
        free(lines[i]);
    free(lines);
    free(buffer);

    return 0;
}
