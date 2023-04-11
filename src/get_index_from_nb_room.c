/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** get_index_from_nb_room
*/

#include "lem_in.h"

int get_index_from_nb_room(int nb_room, elt_t *array_list)
{
    int index_room = 0;
    if (array_list == NULL)
        return -1;
    elt_t *tmp = array_list;
    for (; tmp != NULL; index_room += 1){
        if (tmp->data->nb_room == nb_room)
            return index_room;
        tmp = tmp->next;
    }
    return -1;
}
