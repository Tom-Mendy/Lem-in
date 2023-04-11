/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_room_in_list
*/

#include "lem_in.h"

int is_room_in_list(elt_t *array_list, char *start, char *end)
{
    if (array_list == NULL)
        return KO;
    elt_t *tmp = array_list;
    while (tmp != NULL){
        if (tmp->data != NULL){
            if (my_str_cmp(tmp->data->name_room, start) != 0 &&
            my_str_cmp(tmp->data->name_room, end) != 0)
                return OK;
        }
        tmp = tmp->next;
    }
    return KO;
}
