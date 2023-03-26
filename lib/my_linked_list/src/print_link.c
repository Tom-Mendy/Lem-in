/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** print_link
*/

#include <stdio.h>
#include "graph.h"

void print_link(link_t *link)
{
    if (link != NULL)
        printf("%d\n", link->data);
}
