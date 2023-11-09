/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** my_strncmp
*/

#include <string>
#include <cstring>

int my_strncmp(char const *s1, char const *s2, int i, int j)
{
    int one = strlen(s1);
    int two = strlen(s2);

    if (one != two) {
        return 0;
    }
    while (s1[i] != '\0') {
        if (s1[i] != s2[i]) {
            return (0);
        } else {
            ++i;
        }
    }
    return (1);
}