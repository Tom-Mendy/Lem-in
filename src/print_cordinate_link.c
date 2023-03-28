/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** print_cordinate_link
*/

#include "lem_in.h"

void print_cordinate_link(list_type_t *link)
{
    if (link != NULL){
        my_put_nbr(link->x);
        write(1, "\n", 1);
        my_put_nbr(link->y);
        write(1, "\n", 1);
    }
}
