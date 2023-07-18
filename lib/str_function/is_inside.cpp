/*
** EPITECH PROJECT, 2023
** Banana_eater
** File description:
** is_inside
*/

static int check_banned(char *str, char *banned, int i)
{
    for (int j = 0; banned[j] != '\0'; j += 1) {
        if (str[i] == banned[j]) {
            return 1;
        }
    }
    return 0;
}

int is_inside(char *str, char *banned)
{
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (check_banned(str, banned, i) == 1) {
            return 1;
        }
    }
    return 0;
}

int how_many_insie(char *str, char *banned)
{
    int count = 0;
    for (int i = 0; str[i] != '\0'; i += 1) {
        if (check_banned(str, banned, i) == 1) {
            count += 1;
        }
    }
    return count;
}
