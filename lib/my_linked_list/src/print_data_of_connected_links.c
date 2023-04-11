/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** print_data_of_connected_links
*/

#include <unistd.h>
#include <stdio.h>
#include "my_linked_list.h"

static void print_data_of_connected_links_sub(list_type_t *link)
{
    if (link->sub_branches != NULL) {
        for (int i = 0; link->sub_branches[i] != NULL; i += 1) {
            my_put_str(link->sub_branches[i]->name_room);
        }
    }
}

void print_data_of_connected_links(list_type_t *link)
{
    if (link != NULL) {
        if (link->sub_branches != NULL) {
            print_data_of_connected_links_sub(link);
        }
    }
}
