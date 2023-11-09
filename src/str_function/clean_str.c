/*
** EPITECH PROJECT, 2023
** B-SYN-200-PAR-2-1-sbmlparser-axel.londas
** File description:
** clean_str
*/

#include <stdlib.h>

static int is_inside(char c, char *banned)
{
    int i = 0;
    if (c == '\0') {
        return (1);
    }
    while (banned[i] != '\0') {
        if (c == banned[i]) {
            return (1);
        }
        i += 1;
    }
    return (0);
}

char *clean_str(char *str, char *banned)
{
    int len = 0;
    int k = 0;
    int l = 0;

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (is_inside(str[i],banned) == 0) {
            len += 1;
        }
    }
    char *cleaned = malloc(sizeof(char) * len + 1);
    while (str[k] != '\0') {
        if (is_inside(str[k],banned) == 0) {
            cleaned[l] = str[k];
            l += 1;
        }
        k += 1;
    }
    cleaned[l] = '\0';
    return cleaned;
}
