/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** connect_two_link
*/

#include "lem_in.h"

int connect_two_link(elt_t *array_list, int first_nb, int second_nb)
{
    elt_t *tmp_1 = array_list;
    elt_t *tmp_2 = array_list;
    for (int i = 0; tmp_1 != NULL && tmp_1->data->data != first_nb; i += 1){
        tmp_1 = tmp_1->next;
    }
    for (int i = 0; tmp_2 != NULL && tmp_2->data->data != second_nb; i += 1){
        tmp_2 = tmp_2->next;
    }
    connect_links(tmp_1->data, tmp_2->data);
    connect_links(tmp_2->data, tmp_1->data);
    return 0;
}
