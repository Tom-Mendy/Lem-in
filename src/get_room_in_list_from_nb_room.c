/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** get_room_in_list_from_nb_room
*/

#include "lem_in.h"

list_type_t *get_room_in_list_from_nb_room(char *name_room, elt_t *array_list)
{
    int index_room = 0;
    if (array_list == NULL)
        return NULL;
    elt_t *tmp = array_list;
    for (; tmp != NULL; index_room += 1){
        if (tmp->data != NULL){
            if (my_str_cmp(tmp->data->name_room, name_room) == 0)
                return tmp->data;
        }
        tmp = tmp->next;
    }
    return NULL;
}
