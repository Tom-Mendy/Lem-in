/*
** EPITECH PROJECT, 2023
** list_all_roads
** File description:
** list_all_road
*/

#include "lem_in.h"


list_road_t *list_all_road(file_info_t *file_info)
{
    list_road_t *possible_paths = NULL;
    // int index_start = get_index_from_nb_room(file_info->nb_start_room, file_info->array_list);
    int index_start = file_info->nb_start_room;
    int index_end = file_info->nb_end_room;
    // int index_end = get_index_from_nb_room(file_info->nb_end_room, file_info->array_list);
    printf("%d  %d\n", index_start, index_end);
    return possible_paths;
}