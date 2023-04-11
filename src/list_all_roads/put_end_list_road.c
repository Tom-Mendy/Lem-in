/*
** EPITECH PROJECT, 2023
** B-MUL-100-BDX-1-1-myradar-tom.mendy
** File description:
** put_end_list
*/

#include "lem_in.h"

int put_end_list_road(list_road_t **list, list_room_t *value)
{
    list_road_t *node = *list;
    if (node != NULL) {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = malloc(sizeof(list_road_t));
        if (node->next == NULL)
            return 84;
        node->next->data = value;
        node->next->next = NULL;
        node->next->prev = node;
    } else {
        (*list) = malloc(sizeof(list_road_t));
        if ((*list) == NULL)
            return 84;
        (*list)->data = value;
        (*list)->next = NULL;
        (*list)->prev = NULL;
    }
    return 0;
}
