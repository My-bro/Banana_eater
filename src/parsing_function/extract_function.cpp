/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** extract_function
*/

#include "node.h"
#include "function.h"
#include <string.h>
#include <iostream>

char *strconcat(char *src, char *ext);
node_t *add_node(node_t **head, node_t **tail, node_t **node);
int how_many_char_inside(char *str, char c);

int len_linked_list(node_t *head)
{
    int len_linesArray = 0;
    while (head != nullptr) {
        head = head->next;
        len_linesArray += 1;
    }
    return len_linesArray;
}

char *str_linked_lst_of_i(node_t *linesArray_linked, int i)
{
    while (i > 0) {
        linesArray_linked = linesArray_linked->next;
        i -= 1;
    }
    return linesArray_linked->str;
}

void ban_str_linked_lst(node_t *linesArray_linked, int i) // This function let us know wich line have been extracted
{
    while (i > 0) {
        linesArray_linked = linesArray_linked->next;
        i -= 1;
    }
    linesArray_linked->valid = false;
}

func_t *extract_function(node_t *linesArray_linked, int line, int len_linesArray)
{
    if (line > len_linesArray || line + 1 > len_linesArray) {   // check over flow if line go too far
        return nullptr;
    }

    char *frst_function_line = str_linked_lst_of_i(linesArray_linked, line);

    if (frst_function_line[strlen(frst_function_line) - 1] != ')') {
        std::cout << "cette ligne ne correspond pas au debut d'une fonction \
oprération annulée" << std::endl;
        std::cout << frst_function_line << std::endl;
        exit(84);
        //return nullptr;
    }

    func_t *function = new func_t;

    function->prototyp = strdup(frst_function_line);
    function->prototyp = strconcat(function->prototyp,strdup(";"));

    node_t *HEAD = nullptr;
    node_t *TAIL = nullptr;
    node_t *NODE = nullptr;

    NODE = new node_t;
    NODE->str = strdup(str_linked_lst_of_i(linesArray_linked, line));
    ban_str_linked_lst(linesArray_linked, line);
    add_node(&HEAD, &TAIL, &NODE);
    NODE = NODE->next;

    NODE = new node_t;
    NODE->str = strdup(str_linked_lst_of_i(linesArray_linked, line + 1));
    ban_str_linked_lst(linesArray_linked, line + 1);
    add_node(&HEAD, &TAIL, &NODE);
    NODE = NODE->next;

    int curly_brackets_count = 1;

    for (unsigned int i = line + 2; i < len_linesArray; i += 1) {

        char *current_str = str_linked_lst_of_i(linesArray_linked, i);

        NODE = new node_t;
        NODE->str = strdup(current_str);
        ban_str_linked_lst(linesArray_linked, i);
        add_node(&HEAD, &TAIL, &NODE);
        NODE = NODE->next;
        curly_brackets_count -= how_many_char_inside(current_str,'}');
        curly_brackets_count += how_many_char_inside(current_str,'{');

        if (curly_brackets_count <= 0) {
            break;
        }
    }
    function->HEAD = HEAD;
    return function;
}
