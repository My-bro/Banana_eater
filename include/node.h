/*
** EPITECH PROJECT, 2023
** PREPROG
** File description:
** node
*/

#ifndef NODE_H_
    #define NODE_H_
        typedef struct node_s {
            char *str;
            struct node_s *next;
        } node_t;
        typedef struct node_package_s {
            node_t *HEAD;
            node_t *TAIL;
            node_t *NODE;
        } node_package_t;
#endif /* !NODE_H_ */
