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
    print_paths(paths);
    display_all_link(file_info_n.array_list);
    free_link_list_room(file_info_n.array_list);
    return 0;
}
