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
void src_copy_flag(char **av, flag_t flag, node_t *linesArray_linked);
void src_dest_flag(char **av, flag_t flag, node_t *linesArray_linked, std::string fileExtension);

void file_writting(int ac, char **av, func_info_t func_info)
{
    // std::ofstream destFile(av[2]);

    std::string fileExtension = ".c";

    src_copy_flag(av, func_info.flag, func_info.linesArray_linked);
    src_dest_flag(av, func_info.flag, func_info.linesArray_linked, fileExtension);

    if (func_info.flag.flag_do == true) {

    } else if (func_info.flag.flag_dc == true) {

    }
}