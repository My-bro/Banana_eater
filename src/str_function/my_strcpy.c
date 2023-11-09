/*
** EPITECH PROJECT, 2022
** task1
** File description:
** kakashi
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char *src)
{
    int len = my_strlen(src);
    dest = new char[len + 1];
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        ++i;
    }
    dest[i] = '\0';
    return dest;
}
