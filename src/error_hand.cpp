/*
** EPITECH PROJECT, 2023
** error hand
** File description:
** error_hand
*/

#include <string.h>
#include <stdio.h>
#include "flag.h"
#include "string.h"

void helper(void)
{
    printf("\nUsage: ./banana_eater src.(c/cpp) dest.(c/cpp) [SRC_FALG] [DEST_FLAG] [OPT_FALGS] [LINE(S) ...].\n\n\t\
[SRC_FALG]  [ -o  | -c  ].\n\t\
[DEST_FLAG] [ -do | -dc ].\n\t\
[OPT_FALGS] [ -m  | -h  | -i ].\n\n\
Info: -Every flags betwen [] can be insert in the way you want.\n\n      \
-You can also tap ./banana_eater -man to know in detail what flag does.\n");
}

void manual(void)
{
    printf("\n\t\t\t|| MANUAL ||\n\n\t\
-o  [ORIGINAL] Source file gonna be modified directly.\n\n\t\
-c  [COPY] Source file gonna be modified on a copie this option is advice.\n\n\t\
-do [DEST ORIGINAL] Destination file gonna be modified directly.\n\n\t\
-dc [DEST COPY] Destination file gonna be modified on a copie this option is to advice.\n\n\t\
-m  [MAKEFILE] If a new file have to be create the program gonna add the path on the makefile.\n\n\t\
-h  [HEADER] If a new file have to be create the program gonna add epitech header.\n\n\t\
-i  [INCLUDE] The program will export his own include on the destination file.\n");
}


int error_hand(int ac, char **av)
{
    if (ac == 2) {
        if (strcmp(av[1],"-h") == 0) {
            helper();
            return 1;
        } else if (strcmp(av[1],"-man") == 0) {
            manual();
            return 1;
        }
        return 84;
    }
    flag_t flag = {false,false,false,false,false,false};

    int count_src = 0;
    int count_dest = 0;

    for (unsigned int i = 0; av[i] != nullptr; i += 1) {
        if (strcmp(av[i],"-o") == 0) {
            count_src += 1;
            flag.flag_o = true;
        }
        if (strcmp(av[i],"-c") == 0) {
            count_src += 1;
            flag.flag_c = true;
        }
        if (strcmp(av[i],"-i") == 0) {
            flag.flag_i = true;
        }
        if (strcmp(av[i],"-m") == 0) {
            flag.flag_m = true;
        }
        if (strcmp(av[i],"-do") == 0) {
            count_dest += 1;
            flag.flag_do = true;
        }
        if (strcmp(av[i],"-dc") == 0) {
            count_dest += 1;
            flag.flag_dc = true;
        }
    }

    if (flag.flag_o == true && flag.flag_c == true) {
        printf("flag -o and -c are incompatible.\n");
        return 84;
    }
    if (flag.flag_do == true && flag.flag_dc == true) {
        printf("flag -do and -dc are incompatible.\n");
        return 84;
    }
    if (flag.flag_o == false && flag.flag_c == false) {
        printf("You have to chose one of this flags [ -o | -c ].\n");
        return 84;
    }
    if (flag.flag_do == false && flag.flag_dc == false) {
        printf("You have to chose one of this flags [ -do | -dc ].\n");
        return 84;
    }
    return 0;
}