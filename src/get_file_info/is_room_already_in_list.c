/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_room_already_in_list
*/

#include "lem_in.h"

int is_room_already_in_list(elt_t *array_list, char * name_room)
{
    elt_t *tmp = array_list;
    while (tmp != NULL){
        if (my_str_cmp(tmp->data->name_room, name_room) == 0)
            return KO;
        tmp = tmp->next;
    }
    return OK;
}
