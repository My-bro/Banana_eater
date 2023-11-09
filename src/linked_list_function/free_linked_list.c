/*
** EPITECH PROJECT, 2023
** PREPROG
** File description:
** free_linked_list
*/

#include "node.h"
#include <stdlib.h>

void free_linked_list(node_t* head)
{
    node_t* current = head;
    node_t* temp =  NULL;
    while (current != NULL) {
        temp = current;
        current = current->next;
        free(temp);
    }
}
