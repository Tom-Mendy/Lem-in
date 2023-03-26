/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** create_link
*/

#include <stdlib.h>
#include "graph.h"

link_t *create_link(int data)
{
    link_t *new_link = malloc(sizeof(link_t));
    if (new_link == NULL)
        return NULL;
    new_link->data = data;
    new_link->sub_branches = NULL;
    return new_link;
}
