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
    .name_end_room = 0, .name_start_room = 0};
    if (get_file_info(&file_info_n) == KO){
        free_link_list_room(file_info_n.array_list);
        return KO;
    }
    list_road_t *paths = list_all_road(&file_info_n);
    list_room_t *toto = paths->data;
    print_paths(paths);
    for (int i = 0; file_info_n.file[i] != NULL; i += 1){
        my_put_str(file_info_n.file[i]);
        my_put_char('\n');
    }
    sort_roads(paths);
    free_map(file_info_n.file);
    free_paths(paths);
    free_link_list_room(file_info_n.array_list);
    free(file_info_n.name_start_room);
    free(file_info_n.name_end_room);
    return 0;
}
