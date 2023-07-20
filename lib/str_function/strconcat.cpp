/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-axel.londas
** File description:
** strconcat
*/

#include <stdlib.h>
#include <string.h>

int my_strlen(char const *str);

char *strconcat(char *src, char *ext)
{
    int len_src = strlen(src);
    int len_ext = strlen(ext);
    int len = len_ext + len_src;
    char *str = new char[len + 1];
    int i = 0;
    int j = 0;
    while (i < len_src) {
        str[i] = src[i];
        ++i;
    }
    while (j < len_ext) {
        str[i] = ext[j];
        ++i;
        ++j;
    }
    str[i] = '\0';
    return str;

}
