/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** file_opener
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <vector>
#include <string>

char **file_opener(char **av)
{
    std::ifstream file(av[1]);
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
        exit(84);
        return nullptr;
    }
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    char **linesArray = new char*[lines.size() + 1];
    for (size_t i = 0; i < lines.size(); ++i) {
        linesArray[i] = new char[lines[i].length() + 1];
        std::strcpy(linesArray[i], lines[i].c_str());
    }
    linesArray[lines.size()] = nullptr;
    return linesArray;
}
