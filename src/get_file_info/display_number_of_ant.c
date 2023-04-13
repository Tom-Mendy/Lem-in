/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** display_number_of_ant
*/

#include "lem_in.h"

int display_number_of_ant(int nb_ant)
{
    my_put_str("#number_of_ants\n");
    my_put_nbr(nb_ant);
    my_put_char('\n');
    return OK;
}
