/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** create_link
*/

#include "my_linked_list.h"

list_type_t *create_link(int const data, int const x, int const y)
{
    list_type_t *new_link = malloc(sizeof(list_type_t));
    if (new_link == NULL)
        return NULL;
    new_link->data = data;
    new_link->x = x;
    new_link->y = y;
    new_link->sub_branches = NULL;
    return new_link;
}
