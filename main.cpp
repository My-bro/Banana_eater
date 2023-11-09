/*
** EPITECH PROJECT, 2023
** Banana eater
** File description:
** main
*/

#include <iostream>
#include <fstream>
#include <stdio.h>
#include "node.h"
#include "function.h"
#include "flag.h"

char **file_opener(char **av);
node_t *make_patern_linked_list(char **linesArray, char *patern);
node_t *make_lines_array_linked(char **linesArray);
int error_hand(int ac, char **av, flag_t *flag);
void file_writting(int ac, char **av, func_info_t func_info);
func_node_t *make_function_linked_list(int ac, char **av, node_t *linesArray_linked);

int main(int ac, char **av)
{
    flag_t flag;

    if (error_hand(ac, av, &flag) == 84) {
        return 84;
    }

    char **linesArray = file_opener(av);
    node_t *linesArray_linked = make_lines_array_linked(linesArray);
    node_t *inlude_linked = make_patern_linked_list(linesArray, strdup("#include "));
    node_t *define_linked = make_patern_linked_list(linesArray, strdup("#define "));

    // while (inlude_linked != nullptr) {
    //     printf("%s\n",inlude_linked->str);    //print la linked d'include
    //     inlude_linked = inlude_linked->next;
    // }
    // while (define_linked != nullptr) {
    //     printf("%s\n",define_linked->str);   //print la linked de define
    //     define_linked = define_linked->next;
    // }

    // func_t *function = new func_t;
    // function = extract_function(linesArray_linked, 6, len_linked_list(linesArray_linked));

    func_node_t *function_list = make_function_linked_list(ac, av, linesArray_linked);
    func_info_t func_info = {function_list,
        linesArray_linked,
        inlude_linked,
        define_linked,
        flag};
    file_writting(ac, av, func_info);

    // while (function->HEAD != nullptr) {
    //     printf("%s\n",function->HEAD->str);    //print the content of the exctract function that came from line 6
    //     function->HEAD = function->HEAD->next;
    // }

    // while (linesArray_linked != nullptr) {
    //     if (linesArray_linked->valid == true) {
    //         printf("%s\n",linesArray_linked->str); //print the function extracted previously
    //     }
    //     linesArray_linked = linesArray_linked->next;
    // }

    return 0;
}
