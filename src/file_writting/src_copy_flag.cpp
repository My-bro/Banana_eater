/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** src_copy_flag
*/

#include "node.h"
#include "function.h"
#include <iostream>
#include <fstream>

void src_copy_flag(char **av, flag_t flag, node_t *linesArray_linked)
{
    std::ofstream srcFile(av[1]);
    if (flag.flag_o == true) {
        if (srcFile.is_open()) {
            while (linesArray_linked != nullptr) {
                if (linesArray_linked->valid == true) {
                    srcFile << linesArray_linked->str << "\n";
                }
                linesArray_linked = linesArray_linked->next;
            }
        }
    }
}