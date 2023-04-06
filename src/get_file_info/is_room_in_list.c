/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_room_in_list
*/

#include "lem_in.h"

int is_room_in_list(elt_t *array_list, int start, int end)
{
    if (array_list == NULL)
        return KO;
    elt_t *tmp = array_list;
    while (tmp != NULL){
        if (tmp->data->nb_room != start && tmp->data->nb_room != end)
            return OK;
        tmp = tmp->next;
    }
    return KO;
}
