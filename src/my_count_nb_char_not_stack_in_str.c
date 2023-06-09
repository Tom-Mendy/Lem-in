/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** my_count_nb_char_in_str
*/

#include "lem_in.h"

int my_count_nb_char_in_str(char *str, char spe_char)
{
    if (str == NULL)
        return -1;
    int nb_word = 0;
    for (int k = 0; str[k + 1] != '\0'; k += 1) {
        if (str[k] == spe_char && str[k + 1] != spe_char)
            nb_word += 1;
    }
    return nb_word;
}
