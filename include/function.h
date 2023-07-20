/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** funcion
*/

#ifndef FUNCTION_H_
    #include "node.h"
    #define FUNCTION_H_
        typedef struct func_node_s {
            struct func_s *function;
        } func_node_t;
        typedef struct func_s {
            node_t *HEAD;
            char *prototyp;
            char *return_values;
        } func_t;
#endif /* !FUNCION_H_ */
