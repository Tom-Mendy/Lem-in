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
    for (int i = 0; tmp_1 != NULL && tmp_1->data->nb_room != first_nb; i += 1){
        tmp_1 = tmp_1->next;
    }
    for (int i = 0; tmp_2 != NULL && tmp_2->data->nb_room != second_nb; i += 1){
        tmp_2 = tmp_2->next;
    }
    if (tmp_1 == NULL || tmp_2 == NULL)
        return KO;
    if (connect_links(tmp_1->data, tmp_2->data) == KO)
        return KO;
    if (connect_links(tmp_2->data, tmp_1->data) == KO)
        return KO;
    return OK;
}
