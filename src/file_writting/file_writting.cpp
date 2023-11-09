/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** file_writting
*/

#include <iostream>
#include <fstream>
#include "node.h"
#include "function.h"
#include "flag.h"

std::ofstream open_copy(const std::string& filename, const std::string& extension);

void file_writting(int ac, char **av, func_info_t func_info)
{
    std::ofstream srcFile(av[1]);
    // std::ofstream destFile(av[2]);

    std::string fileExtension = ".c";

    if (func_info.flag.flag_o == true) {

        if (srcFile.is_open()) {
            while (func_info.linesArray_linked != nullptr) {
                if (func_info.linesArray_linked->valid == true) {
                    srcFile << func_info.linesArray_linked->str << "\n";
                }
                func_info.linesArray_linked = func_info.linesArray_linked->next;
            }
        }

    } else if (func_info.flag.flag_c == true) {

        size_t originalLength = strlen(av[1]);
        char* newString = new char[originalLength - 1];
        strncpy(newString, av[1], originalLength - 2);
        newString[originalLength - 2] = '\0';
        std::ofstream srcFilecopy = open_copy(newString, fileExtension);

        if (srcFile.is_open()) {
            node_t *local_head = func_info.linesArray_linked;
            while (local_head != nullptr) {
                srcFile << local_head->str << "\n";
                local_head = local_head->next;
            }
        }

        if (srcFilecopy.is_open()) {
            node_t *local_head = func_info.linesArray_linked;
            while (local_head != nullptr) {
                if (local_head->valid == true) {
                    srcFilecopy << local_head->str << "\n";
                }
                local_head = local_head->next;
            }
        }
    }

    if (func_info.flag.flag_do == true) {

    } else if (func_info.flag.flag_dc == true) {

    }
}