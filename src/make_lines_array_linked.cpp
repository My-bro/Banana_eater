/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** make_lines_array_linked
*/

#include "node.h"
#include <string.h>

node_t *add_node(node_t **head, node_t **tail, node_t **node);


node_t *make_lines_array_linked(char **linesArray)
{
    node_t *Head = nullptr;
    node_t *Tail = nullptr;
    node_t *Node = nullptr;

    for (unsigned int i = 0; linesArray[i] != nullptr; i += 1) {
        Node = new node_t;
        Node->str = strdup(linesArray[i]);
        Node->valid = true;
        add_node(&Head, &Tail, &Node);
        Node = Node->next;
    }
    return Head;
}
