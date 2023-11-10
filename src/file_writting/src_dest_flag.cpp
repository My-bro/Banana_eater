/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** src_dest_flag
*/

#include "function.h"
#include <iostream>
#include <fstream>
#include <cstring>

std::ofstream open_copy(const std::string& filename, const std::string& extension);

void src_dest_flag(char **av, flag_t flag, node_t *linesArray_linked, std::string fileExtension)
{
    std::ofstream srcFile(av[1]);
    if (flag.flag_c == true) {

        size_t originalLength = strlen(av[1]);
        char* newString = new char[originalLength - 1];
        strncpy(newString, av[1], originalLength - 2);
        newString[originalLength - 2] = '\0';
        std::ofstream srcFilecopy = open_copy(newString, fileExtension);

        if (srcFile.is_open()) {
            node_t *local_head = linesArray_linked;
            while (local_head != nullptr) {
                srcFile << local_head->str << "\n";
                local_head = local_head->next;
            }
        }

        if (srcFilecopy.is_open()) {
            node_t *local_head = linesArray_linked;
            while (local_head != nullptr) {
                if (local_head->valid == true) {
                    srcFilecopy << local_head->str << "\n";
                }
                local_head = local_head->next;
            }
        }
    }
}