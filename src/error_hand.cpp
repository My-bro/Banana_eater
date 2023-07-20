/*
** EPITECH PROJECT, 2023
** error hand
** File description:
** error_hand
*/

#include <string.h>

int error_hand(int ac, char **argv)
{
    if (ac != 3)
        return 84;
    if ((strcmp(argv[2], "-o") != 0) || (strcmp(argv[2], "-c")) || (strcmp(argv[2], "-i") != 0) ||
    (strcmp(argv[2], "-m") != 0) || (strcmp(argv[2], "-do") != 0) || (strcmp(argv[2], "-dc") != 0))
        return 84;
    return 0;
}