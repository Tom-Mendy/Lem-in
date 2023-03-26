/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** print_data_of_connected_links
*/

#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

void print_data_of_connected_links(link_t *link)
{
    if (link != NULL) {
        for (int i = 0; link->sub_branches[i] != NULL; i += 1) {
            print_link(link->sub_branches[i]);
        }
    }
}
