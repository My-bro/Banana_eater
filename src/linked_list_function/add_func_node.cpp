/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** add_func_node
*/

#include "function.h"
#include <iostream>

func_node_t *add_func_node(func_node_t **head, func_node_t **tail, func_node_t **node)
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
