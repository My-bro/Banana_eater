/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** make_include_linked_list
*/

#include <string.h>
#include "node.h"

int is_inside(char *str, char *banned);
int patern_is_inside(char *str, char *patern);
node_t *add_node(node_t **head, node_t **tail, node_t **node);

int find_include_line(char *line)
{
    if (is_inside(line,strdup("#")) == 0) {
        return 0;
    }
    if (patern_is_inside(line,strdup("#include ")) != -1) {
        return 1;
    }
    return 0;
}

node_t *make_include_linked_list(char **linesArray)
{
    node_t *Head = nullptr;
    node_t *Tail = nullptr;
    node_t *Node = nullptr;

    for (size_t i = 0; linesArray[i] != nullptr; ++i) {
        if (find_include_line(linesArray[i]) == 1) {
            Node = new node_t;
            Node->str = strdup(linesArray[i]);
            add_node(&Head, &Tail, &Node);
            Node = Node->next;
        }
    }
    return Head;
}