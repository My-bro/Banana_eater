/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** make_func_linked
*/

#include "node.h"
#include "function.h"
#include <iostream>
#include <cstdlib>

func_node_t *add_func_node(func_node_t **head, func_node_t **tail, func_node_t **node);
func_t *extract_function(node_t *linesArray_linked, int line, int len_linesArray);
int len_linked_list(node_t *head);

func_node_t *make_function_linked_list(int ac, char **av, node_t *linesArray_linked) // This function can't extract a function at lign 0
{
    func_node_t *HEAD = nullptr;
    func_node_t *TAIL = nullptr;
    func_node_t *NODE = nullptr;

    for (unsigned int i = 5; i < ac; i += 1) {
        int nb = atoi(av[i]);
        nb -= 1;
        if (nb == 0) {
            continue;
        }
        NODE = new func_node_t;
        func_t *function = extract_function(linesArray_linked, nb, len_linked_list(linesArray_linked));
        add_func_node(&HEAD, &TAIL, &NODE);
        NODE = NODE->next;
    }
    return HEAD;
}
