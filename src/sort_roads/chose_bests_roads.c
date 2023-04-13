/*
** EPITECH PROJECT, 2023
** chose_bests_roads
** File description:
** choose the bests two roads that doesn't have the same nodes
*/

#include "lem_in.h"

int get_len_of_road(list_room_t *road)
{
    int len = 0;
    list_room_t *tmp = road;
    for (; tmp->next != NULL; tmp = tmp->next) {
        len++;
    }
    return len;
}

static list_room_t *is_node_inside_road(list_room_t *tmp_first_road,
list_room_t *road)
{
    list_room_t *tmp_road = road;
    for (;tmp_road->next != NULL; tmp_road = tmp_road->next) {
        if (my_str_cmp(tmp_first_road->name_room, tmp_road->name_room) == 0) {
            return NULL;
        }
    }
    return road;
}

list_room_t *find_second_road(list_road_t **road)
{
    list_room_t *first_road = (*road)->data;
    list_road_t *tmp_road = *road;
    list_room_t *second_road = malloc(sizeof(list_road_t));
    for (; tmp_road->next != NULL; tmp_road = tmp_road->next) {
        list_room_t *tmp_first_road = first_road;
        for (; tmp_first_road->next != NULL;
        tmp_first_road = tmp_first_road->next) {
            second_road = is_node_inside_road(tmp_first_road, tmp_road->data);
        }
        if (second_road != NULL) {
            return second_road;
        }
    }
    return NULL;
}
