/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** open_copy
*/

#include <iostream>
#include <fstream>
#include <sstream>

std::ofstream open_copy(const std::string& filename, const std::string& extension)
{
    std::ifstream testFile(filename + extension);
    int count = 0;
    while (testFile.is_open()) {
        testFile.close();
        count++;
        std::ostringstream newFilename;
        newFilename << filename << "(" << count << ")" << extension;
        testFile.open(newFilename.str());
    }
    return std::ofstream(filename + "(" + std::to_string(count) + ")" + extension);
}
