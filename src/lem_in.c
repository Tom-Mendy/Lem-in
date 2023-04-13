/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int print_paths(list_road_t *paths)
{
    if (paths == NULL){
        my_put_str("No paths found\n");
        return OK;
    }
    list_road_t *tmp = paths;
    while (tmp != NULL){
        display_list_possible_road(tmp->data);
        tmp = tmp->next;
        my_put_str("rrrrrrrrrrrrrrrrrrrrrr\n");
    }
    return OK;
}

int lem_in(void)
{
    file_info_t file_info_n = {.array_list = NULL, .nb_ant = 0,
    .name_end_room = NULL, .name_start_room = NULL, .start = 0, .end = 0};
    if (get_file_info(&file_info_n) == KO){
        free_link_list_room(file_info_n.array_list);
        if (file_info_n.name_end_room != NULL)
            free(file_info_n.name_end_room);
        if (file_info_n.name_start_room != NULL)
            free(file_info_n.name_start_room);
        return KO;
    }
    list_road_t *paths = list_all_road(&file_info_n);
    sort_roads(paths);
    free_paths(paths);
    free_map(file_info_n.file);
    free_link_list_room(file_info_n.array_list);
    free(file_info_n.name_start_room);
    free(file_info_n.name_end_room);
    return 0;
}
