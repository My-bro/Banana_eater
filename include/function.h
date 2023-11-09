/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** funcion
*/

#ifndef FUNCTION_H_
    #include "node.h"
    #include "flag.h"
    #define FUNCTION_H_

        typedef struct func_node_s {
            struct func_s *function;
            func_node_s *next;
        } func_node_t;

        typedef struct func_s {
            bool is_valide;
            node_t *HEAD;
            char *prototyp;
            char *return_values;
        } func_t;

        typedef struct func_info_s {
            func_node_t *function_list;
            node_t *linesArray_linked;
            node_t *inlude_linked;
            node_t *define_linked;
            flag_t flag;
        } func_info_t;
#endif /* !FUNCION_H_ */
