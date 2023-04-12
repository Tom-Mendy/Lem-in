/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** display_list_possible_road
*/

#include "lem_in.h"

void display_list_possible_road(list_room_t *possible_road)
{
    list_room_t *tmp = possible_road;
    for (int i = 0; tmp != NULL; i += 1){
        my_put_str(tmp->name_room);
        my_put_char('\n');
        tmp = tmp->next;
    }
}
