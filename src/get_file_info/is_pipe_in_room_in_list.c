/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_pipe_in_room_in_list
*/

#include "lem_in.h"

int is_pipe_in_room_in_list(elt_t *array_list)
{
    if (array_list == NULL)
        return KO;
    elt_t *tmp = array_list;
    while (tmp != NULL){
        if (tmp->data->sub_branches != NULL)
            return OK;
        tmp = tmp->next;
    }
    return KO;
}
