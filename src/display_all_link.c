/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** display_all_link
*/

#include "lem_in.h"

void display_all_link(elt_t *array_list)
{
    elt_t *tmp = array_list;
    for (int i = 0; tmp != NULL; i += 1){
        print_link(tmp->data);
        print_cordinate_link(tmp->data);
        write(1, "-----------------------------------------\n", 43);
        print_data_of_connected_links(tmp->data);
        write(1, "\n_________________________________________\n", 43);
        tmp = tmp->next;
    }
}
