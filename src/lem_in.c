/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int lem_in(void)
{
    file_info_t file_info_n = {.array_list = NULL, .nb_ant = 0,
    .nb_end_room = 0, .nb_start_room = 0};
    if (get_file_info(&file_info_n) == KO){
        free_link_list_room(file_info_n.array_list);
        return KO;
    }
    display_all_link(file_info_n.array_list);
    free_link_list_room(file_info_n.array_list);
    return 0;
}
