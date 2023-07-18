/*
** EPITECH PROJECT, 2023
** B-PSU-200-PAR-2-1-minishell1-axel.londas
** File description:
** nb_str
*/

#include <stdio.h>

void nb_str(char **db, int *nb_arg)
{

    while (db[*nb_arg] != NULL) {
        ++*nb_arg;
    }
}
