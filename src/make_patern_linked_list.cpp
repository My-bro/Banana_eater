/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** make_include_linked_list
*/

#include <string.h>
#include "node.h"
#include <stdio.h>

int is_inside(char *str, char *banned);
int patern_is_inside(char *str, char *patern);
node_t *add_node(node_t **head, node_t **tail, node_t **node);

int find_patern_line(char *line, char *patern)
{
    char *frst_char_patrn = new char[2];
    frst_char_patrn[0] = patern[0];
    frst_char_patrn[1] = '\0';

    if (is_inside(line, frst_char_patrn) == 0) {
        return 0;
    }
    if (patern_is_inside(line,patern) != -1) {
        return 1;
    }
    return 0;
}

node_t *make_patern_linked_list(char **linesArray, char *patern)
{
    node_t *Head = nullptr;
    node_t *Tail = nullptr;
    node_t *Node = nullptr;

    for (size_t i = 0; linesArray[i] != nullptr; ++i) {
        if (find_patern_line(linesArray[i], patern) == 1) {
            Node = new node_t;
            Node->str = strdup(linesArray[i]);
            add_node(&Head, &Tail, &Node);
            Node = Node->next;
        }
    }
    return Head;
}