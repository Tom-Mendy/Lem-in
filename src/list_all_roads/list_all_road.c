/*
** EPITECH PROJECT, 2023
** list_all_roads
** File description:
** list_all_road
*/

#include "lem_in.h"

list_room_t *copy_list_room(list_room_t *possible_road)
{
    list_room_t *result = NULL;
    list_room_t *tmp = possible_road;
    while (tmp != NULL){
        char *tmp_name_room = generate_malloc_str_from_str(tmp->name_room);
        put_end_list_room(&result, tmp_name_room);
        tmp = tmp->next;
    }
    return result;
}

int is_a_good_road(file_info_t *file_info, list_room_t *possible_road,
list_road_t **possible_paths, char *name_actual_room)
{
    if (my_str_cmp(name_actual_room, file_info->name_end_room) == OK){
        list_room_t *tmp_road = copy_list_room(possible_road);
        put_end_list_road(possible_paths, tmp_road);
        free_end_list_room(&possible_road);
        return 1;
    }
    return OK;
}

list_type_t *get_all_path(file_info_t *file_info, list_room_t *possible_road,
list_road_t **possible_paths, char *name_actual_room)
{
    put_end_list_room(&possible_road, name_actual_room);
    list_type_t *actual_room_state = get_room_in_list_from_nb_room(
    name_actual_room, file_info->array_list);
    if (is_a_good_road(file_info, possible_road, possible_paths,
    name_actual_room) == 1)
        return NULL;
    for (int i = 0; actual_room_state->sub_branches[i] != NULL; i += 1){
        int tmp = get_index_from_nb_room(actual_room_state->sub_branches[i]\
        ->name_room, possible_road);
        if (tmp == -1){
            char *new_name_room = generate_malloc_str_from_str(
                actual_room_state->sub_branches[i]->name_room);
            get_all_path(file_info, possible_road, possible_paths,
            new_name_room);
        }
    }
    free_end_list_room(&possible_road);
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
    char *start_room_str = generate_malloc_str_from_str(start_room->name_room);
    list_type_t *tmp = get_all_path(file_info, possible_road, &possible_paths,
    start_room_str);
    my_put_str(start_room->name_room);
    my_put_char('\n');
    my_put_str(end_room->name_room);
    my_put_char('\n');
    return possible_paths;
}
