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
    for (; tmp != NULL; tmp = tmp->next) {
        len++;
    }
    free(tmp);
    return len;
}

static bool is_node_inside_road(list_room_t *node, list_room_t *road)
{
    list_room_t *tmp_road = road;
    tmp_road = tmp_road->next;
    for (; road->next->next != NULL; road = road->next) {
        if (my_str_cmp(node->name_room, road->name_room) == 0) {
            free(tmp_road);
            return true;
        }
    }
    free(tmp_road);
    return false;
}

bool is_common_node(list_room_t *road1, list_room_t *road2)
{
    list_room_t *node = road1;
    list_room_t *tmp_road2 = road2;
    for (; node->next != NULL; node = node->next) {
        if (is_node_inside_road(node, tmp_road2) == true) {
            free(node);
            free(tmp_road2);
            return true;
        }
    }
    free(node);
    free(tmp_road2);
    return false;
}
