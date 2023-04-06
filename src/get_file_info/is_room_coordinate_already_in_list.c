/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_room_coordinate_already_in_list
*/

#include "lem_in.h"

int is_room_coordinate_already_in_list(elt_t *array_list, int x, int y)
{
    elt_t *tmp = array_list;
    while (tmp != NULL){
        if (tmp->data->x == x && tmp->data->y == y)
            return KO;
        tmp = tmp->next;
    }
    return OK;
}
