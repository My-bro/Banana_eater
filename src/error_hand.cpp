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

    int count = 0;

    for (unsigned int i = 0; argv[i] != nullptr; i += 1) {
        if (strcmp(argv[i],"-o") == 1) {
            flag.flag_o = true;
        }
        if (strcmp(argv[i],"-c") == 1) {
            flag.flag_c = true;
        }
        if (strcmp(argv[i],"-i") == 1) {
            flag.flag_i = true;
            count++;
        }
        if (strcmp(argv[i],"-m") == 1) {
            flag.flag_m = true;
            count++;
        }
        if (strcmp(argv[i],"-do") == 1) {
            flag.flag_do = true;
            count++;
        }
        if (strcmp(argv[i],"-dc") == 1) {
            flag.flag_dc = true;
            count++;
        }
    }

    if (flag.flag_o == true && flag.flag_c == true)
        return 84;
    
    if (flag.flag_o == false && flag.flag_c == false)
        return 84;

    if (count != 1)
        return 84;
    
    return 0;
}