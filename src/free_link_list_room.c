/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** free_link_list_room
*/

#include "lem_in.h"

void free_link_list_room(elt_t *array_list)
{
    for (int i = 0; array_list != NULL; i += 1){
        elt_t *tmp = array_list;
        if (array_list->data->sub_branches != NULL)
            free(array_list->data->sub_branches);
        free(array_list->data->name_room);
        free(array_list->data);
        array_list = array_list->next;
        free(tmp);
    }
    free(array_list);
}
