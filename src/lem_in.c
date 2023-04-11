/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int get_index_from_nb_room(int nb_room, elt_t *array_list)
{
    int index_room = 0;
    for (; array_list[index_room].data->nb_room != nb_room; index_room += 1) {
    }
    return index_room;
}

void print_paths(list_road_t *paths, file_info_t *file_info)
{
    if (paths == NULL)
        printf("No paths found\n");
    else {
        for (int i = 0; paths->next[i] != NULL; i += 1) {
            printf("Current list : %d\n", i);
            list_road_t *sub_paths = paths->next_sub_list;
            while (sub_paths != NULL && sub_paths->connected_rooms != file_info->array_list[get_index_from_nb_room(file_info->nb_end_room, file_info->array_list)].data->nb_room) {
                printf("%d -", sub_paths->connected_rooms);
                sub_paths = sub_paths->next_sub_list;
            }
            printf("\n");
        }
    }
}

int lem_in(void)
{
    file_info_t file_info_n = {.array_list = NULL, .nb_ant = 0,
    .nb_end_room = 0, .nb_start_room = 0};
    if (get_file_info(&file_info_n) == KO)
        return KO;

    list_road_t *paths = list_all_road(&file_info_n);
    print_paths(paths, &file_info_n);
    // display_all_link(file_info_n.array_list);
    free_link_list_room(file_info_n.array_list);
    return 0;
}
