/*
** EPITECH PROJECT, 2022
** task2
** File description:
** counterkakashi
*/

#include <iostream>
#include <cstring>

int my_strlen(char const *str);

char *my_strncpy(char const *src, int n, int n2)
{
    int distance = n2 - n;
    char *dest = new char[distance + 1];
    int i = 0;
    while ( i < distance) {
        dest[i] = src[n];
        ++i;
        ++n;
    }
    dest[i] = '\0';
    return (dest);
}
