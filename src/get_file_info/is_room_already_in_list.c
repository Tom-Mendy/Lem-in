/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_room_already_in_list
*/

#include "lem_in.h"

int is_room_already_in_list(elt_t *array_list, int nb)
{
    elt_t *tmp = array_list;
    while (tmp != NULL){
        if (tmp->data->nb_room == nb)
            return KO;
        tmp = tmp->next;
    }
    return OK;
}
