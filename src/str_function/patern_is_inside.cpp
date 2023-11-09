/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** patern_is_inside
*/

#include <string.h>
#include <stdio.h>

char *my_strncpy(char const *src, int n, int n2);
int my_strcmp(char const *s1, char const *s2);

int patern_is_inside(char *str, char *patern)   //prend en arg une str et un patern return -1
{                                               //si n'exist pas else return i dans lequel
    int len_str = strlen(str);                  //le premier char du patern apparait dans la string
    int len_ptrn = strlen(patern);
    if (len_str < len_ptrn) {
        return -1;
    }
    for (unsigned int i = 0; (i + len_ptrn) < len_str; i += 1) {
        char *test = my_strncpy(str,i,len_ptrn);
        if (my_strcmp(patern,test) == 1) {
            return i;
        }
    }
    return (-1);
}