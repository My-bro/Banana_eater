/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** how_many_char_inside
*/

int how_many_char_inside(char *str, char c)
{
    unsigned int nb_c = 0;
    for (unsigned int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] == c) {
            nb_c += 1;
        }
    }
    return nb_c;
}