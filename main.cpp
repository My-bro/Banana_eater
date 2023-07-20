/*
** EPITECH PROJECT, 2023
** Banana eater
** File description:
** main
*/

#include <iostream>
#include <stdio.h>
#include <cstring>
#include "node.h"
#include "function.h"

char **file_opener(char **av);
node_t *make_patern_linked_list(char **linesArray, char *patern);
func_t *extract_function(node_t *linesArray_linked, int line, int len_linesArray);
int len_linked_list(node_t *head);
node_t *make_lines_array_linked(char **linesArray);

int main(int ac, char **av)
{
    if (error_hand(ac, av) == 84)
        return 84;
    char **linesArray = file_opener(av);
    node_t *linesArray_linked = make_lines_array_linked(linesArray);
    node_t *inlude_linked = make_patern_linked_list(linesArray, strdup("#include "));
    node_t *define_linked = make_patern_linked_list(linesArray, strdup("#define "));

    while (inlude_linked != nullptr) {
        printf("%s\n",inlude_linked->str);    //print la linked d'include
        inlude_linked = inlude_linked->next;
    }
    while (define_linked != nullptr) {
        printf("%s\n",define_linked->str);   //print la linked de define
        define_linked = define_linked->next;
    }

    func_t *function = new func_t;
    function = extract_function(linesArray_linked, 6, len_linked_list(linesArray_linked));

    while (function->HEAD != nullptr) {
        printf("%s\n",function->HEAD->str);    //print le contenu d'une fonction extract
        function->HEAD = function->HEAD->next;
    }

    while (linesArray_linked != nullptr) {
        if (linesArray_linked->valid == true) {
            printf("%s\n",linesArray_linked->str); //print la fonction sans la fonction extraite précedement
        }
        linesArray_linked = linesArray_linked->next;
    }

    return 0;
}
