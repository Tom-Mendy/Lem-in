/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** print_data_of_connected_links
*/

#include "my_linked_list.h"

static void print_data_of_connected_links_sub(list_type_t *link)
{
    for (int i = 0; link->sub_branches[i] != NULL; i += 1) {
        print_link(link->sub_branches[i]);
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
