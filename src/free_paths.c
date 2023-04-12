/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** free_paths
*/

#include "lem_in.h"

int free_paths(list_road_t *paths)
{
    list_road_t *tmp = NULL;
    list_room_t *tmp_2 = NULL;
    while (paths != NULL){
        tmp = paths;
        while (tmp->data != NULL){
            tmp_2 = tmp->data;
            tmp->data = tmp->data->next;
            free(tmp_2->name_room);
            free(tmp_2);
        }
        paths = paths->next;
        free(tmp);
    }
    return OK;
}
