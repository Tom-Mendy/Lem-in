/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** get_index_from_nb_room
*/

#include "lem_in.h"

int get_index_from_nb_room(char * name_room, list_room_t *possible_road)
{
    int index_room = 0;
    if (possible_road == NULL)
        return -1;
    list_room_t *tmp = possible_road;
    for (; tmp != NULL; index_room += 1){
        if (my_str_cmp(tmp->name_room, name_room) == OK)
            return index_room;
        tmp = tmp->next;
    }
    return -1;
}
