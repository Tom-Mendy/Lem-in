/*
** EPITECH PROJECT, 2023
** list_all_roads
** File description:
** list_all_road
*/

#include "lem_in.h"

list_type_t *get_room_in_list_from_nb_room(int nb_room, elt_t *array_list)
{
    int index_room = 0;
    if (array_list == NULL)
        return NULL;
    elt_t *tmp = array_list;
    for (; tmp != NULL; index_room += 1){
        if (tmp->data->nb_room == nb_room)
            return tmp->data;
        tmp = tmp->next;
    }
    return NULL;
}

list_type_t *get_all_path(file_info_t *file_info, list_room_t *possible_road,
list_road_t **possible_paths, int nb_actual_room)
{
    put_end_list_room(&possible_road, nb_actual_room);
    list_type_t *actual_room_state = get_room_in_list_from_nb_room(
    possible_road->name_room, file_info->array_list);
    for (int i = 0; actual_room_state->sub_branches[i] == NULL; i += 1){
        if (get_index_from_nb_room(actual_room_state->sub_branches[i]->nb_room,
        file_info->array_list) == -1){
            get_all_path(file_info, possible_road, possible_paths,
            actual_room_state->sub_branches[i]->nb_room);
        }
    }
    return NULL;
}

list_road_t *list_all_road(file_info_t *file_info)
{
    list_road_t *possible_paths = NULL;
    list_type_t *start_room = get_room_in_list_from_nb_room(
    file_info->name_start_room, file_info->array_list);
    list_type_t *end_room = get_room_in_list_from_nb_room(
    file_info->name_end_room, file_info->array_list);
    list_room_t *possible_road = NULL;
    list_type_t *tmp = get_all_path(file_info, possible_road, &possible_paths,
    start_room->nb_room);

    printf("%d  %d\n", start_room->nb_room, end_room->nb_room);
    return possible_paths;
}
