/*
** EPITECH PROJECT, 2023
** error hand
** File description:
** error_hand
*/

#include <string.h>
#include "flag.h"
#include "string.h"

int error_hand(int ac, char **argv)
{
    flag_t flag = {false,false,false,false,false,false};

    for (unsigned int i = 0; argv[i] != nullptr) {
        if (strcmp(argv[i],"-o") == 1) {
            flag.flag_o = true;
        }
    }

    if (ac != 3)
        return 84;
    if ((strcmp(argv[2], "-o") != 0) || (strcmp(argv[2], "-c")) || (strcmp(argv[2], "-i") != 0) ||
    (strcmp(argv[2], "-m") != 0) || (strcmp(argv[2], "-do") != 0) || (strcmp(argv[2], "-dc") != 0))
        return 84;
    return 0;
}