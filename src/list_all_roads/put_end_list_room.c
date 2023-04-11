/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-tom.mendy
** File description:
** put_end_list
*/

#include "lem_in.h"

int put_end_list_room(list_room_t **list, int name_room)
{
    list_room_t *node = *list;
    if (node != NULL) {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = malloc(sizeof(list_room_t));
        if (node->next == NULL)
            return 84;
        node->next->name_room = name_room;
        node->next->next = NULL;
        node->next->prev = node;
    } else {
        (*list) = malloc(sizeof(list_room_t));
        if ((*list) == NULL)
            return 84;
        (*list)->name_room = name_room;
        (*list)->next = NULL;
        (*list)->prev = NULL;
    }
    return 0;
}
