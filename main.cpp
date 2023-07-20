/*
** EPITECH PROJECT, 2023
** Banana eater
** File description:
** main
*/

#include <iostream>
#include <stdio.h>
#include "node.h"
#include "function.h"

char **file_opener(char **av);
node_t *make_patern_linked_list(char **linesArray, char *patern);
func_t *extract_function(char **linesArray, int line, int len_linesArray);
int len_double_array(char **linesArray);


int main(int ac, char **av)
{
    char **linesArray = file_opener(av);
    node_t *inlude_linked = make_patern_linked_list(linesArray, strdup("#include "));
    node_t *define_linked = make_patern_linked_list(linesArray, strdup("#define "));
    while (inlude_linked != nullptr) {
        printf("%s\n",inlude_linked->str);
        inlude_linked = inlude_linked->next;
    }
    while (define_linked != nullptr) {
        printf("%s\n",define_linked->str);
        define_linked = define_linked->next;
    }

    func_t *function = new func_t;
    function = extract_function(linesArray, 6, len_double_array(linesArray));

    while (function->HEAD != nullptr) {
        printf("%s\n",function->HEAD->str);
        function->HEAD = function->HEAD->next;
    }

    return 0;
}
