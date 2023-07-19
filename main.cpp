/*
** EPITECH PROJECT, 2023
** Banana eater
** File description:
** main
*/

#include <iostream>
#include <stdio.h>
#include "node.h"

char **file_opener(char **av);
node_t *make_patern_linked_list(char **linesArray, char *patern);

int main(int ac, char **av)
{
    char **linesArray = file_opener(av);
    node_t *inlude_linked = make_patern_linked_list(linesArray, strdup("#include "));
    while (inlude_linked != nullptr) {
        printf("%s\n",inlude_linked->str);
        inlude_linked = inlude_linked->next;
    }
    
    node_t *define_linked = make_patern_linked_list(linesArray, strdup("#define "));
    
    while (define_linked != nullptr) {
        printf("%s\n",define_linked->str);
        define_linked = define_linked->next;
    }
    return 0;
}
