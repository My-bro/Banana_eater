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
node_t *make_include_linked_list(char **linesArray);

int main(int ac, char **av)
{
    char **linesArray = file_opener(av);
    node_t *inlude_linked = make_include_linked_list(linesArray);
    while (inlude_linked != nullptr) {
        printf("%s\n",inlude_linked->str);
        inlude_linked = inlude_linked->next;
    }
    return 0;
}
