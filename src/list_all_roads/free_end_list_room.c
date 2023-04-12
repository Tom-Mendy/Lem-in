/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** free_end_list_room
*/

#include "lem_in.h"

static list_room_t *get_end_node(list_room_t *possible_road)
{
    list_room_t *tmp = possible_road;
    for (;tmp->next != NULL;){
        tmp = tmp ->next;
    }
    return tmp;
}

int free_end_list_room(list_room_t **possible_road)
{
    list_room_t *end_node = get_end_node(*possible_road);
    list_room_t *end_node_prev = end_node->prev;
    if (end_node_prev != NULL)
        end_node_prev->next = NULL;
    free(end_node->name_room);
    free(end_node);
    return 0;
}
