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
            bool valid;
            struct node_s *next;
        } node_t;
#endif /* !NODE_H_ */
