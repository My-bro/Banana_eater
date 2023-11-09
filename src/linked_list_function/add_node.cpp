/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** add_node
*/

#include "node.h"
#include <iostream>

node_t *add_node(node_t **head, node_t **tail, node_t **node)
{
    if (*head == nullptr) {
        *head = *node;
        *tail = *node;
    } else {
        (*tail)->next = *node;
        *tail = *node;
        (*tail)->next = nullptr;
    }
    return *head;
}
