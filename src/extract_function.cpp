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

int len_double_array(char **linesArray)
{
    int len_linesArray = 0;
    for (unsigned int i = 0; linesArray[i] != nullptr ; i += 1) {
        len_linesArray += 1;
    }
    return len_linesArray;
}

func_t *extract_function(char **linesArray, int line, int len_linesArray)
{
    if (line > len_linesArray) {
        return nullptr;
    }

    if (linesArray[line][strlen(linesArray[line]) - 1] != ')') {
        std::cout << "cette ligne ne correspond pas au debut d'une fonction \
oprération annulée" << std::endl;
        return nullptr;
    }

    if (line + 1 > len_linesArray) {
        return nullptr;
    }

    func_t *function = new func_t;

    function->prototyp = strdup(linesArray[line]);
    function->prototyp = strconcat(function->prototyp,strdup(";"));

    node_t *HEAD = nullptr;
    node_t *TAIL = nullptr;
    node_t *NODE = nullptr;

    NODE = new node_t;
    NODE->str = strdup(linesArray[line]);
    add_node(&HEAD, &TAIL, &NODE);
    NODE = NODE->next;

    NODE = new node_t;
    NODE->str = strdup(linesArray[line + 1]);
    add_node(&HEAD, &TAIL, &NODE);
    NODE = NODE->next;

    int curly_brackets_count = 1;

    for (unsigned int i = line + 2; i < len_linesArray; i += 1) {

        NODE = new node_t;
        NODE->str = strdup(linesArray[i]);

        add_node(&HEAD, &TAIL, &NODE);
        NODE = NODE->next;
        curly_brackets_count -= how_many_char_inside(linesArray[i],'}');
        curly_brackets_count += how_many_char_inside(linesArray[i],'{');

        if (curly_brackets_count <= 0) {
            break;
        }
    }
    function->HEAD = HEAD;
    return function;
}
