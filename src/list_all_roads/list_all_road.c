/*
** EPITECH PROJECT, 2023
** list_all_roads
** File description:
** list_all_road
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

list_room_t *get_end_node(list_room_t *possible_road)
{
    list_room_t *tmp = possible_road;
    for (;tmp->next != NULL;){
        tmp = tmp ->next;
    }
    return tmp;
}

int free_end_list(list_room_t **possible_road)
{
    list_room_t *end_node = get_end_node(*possible_road);
    list_room_t *end_node_prev = end_node->prev;
    if (end_node_prev != NULL)
        end_node_prev->next = NULL;
    free(end_node->name_room);
    free(end_node);
    return 0;
}

list_type_t *get_all_path(file_info_t *file_info, list_room_t *possible_road,
list_road_t **possible_paths, char *name_actual_room)
{
    put_end_list_room(&possible_road, name_actual_room);
    display_list_possible_road(possible_road);
    list_type_t *actual_room_state = get_room_in_list_from_nb_room(
    name_actual_room, file_info->array_list);
    if (my_str_cmp(name_actual_room, file_info->name_end_room) == OK){
        free_end_list(&possible_road);
        return NULL;
    }
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
    free_end_list(&possible_road);
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
