/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** print_link
*/

#include <unistd.h>
#include "my_linked_list.h"

void print_link(list_type_t *link)
{
    if (link != NULL){
        my_put_nbr(link->nb_room);
        write(1, "\n", 1);
    }
}
