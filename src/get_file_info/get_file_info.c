/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** get_file_info
*/

#include "lem_in.h"

int get_nb_ant(file_info_t *file_info_n, char **file)
{
    if (my_str_is_num(file[0]) == false){
        free_map(file);
        return KO;
    }
    file_info_n->nb_ant = my_get_nbr(file[0]);
    return OK;
}

int get_file_info_sub(file_info_t *file_info_n, char **file, int i)
{
    if (add_line_info_to_struct(file[i], &(file_info_n->array_list)) == KO){
        free_map(file);
        return KO;
    }
    return OK;
}

int is_element_in_list(elt_t *array_list, int start, int end)
{
    if (is_room_in_list(array_list, start, end) == KO)
        return KO;
    if (is_pipe_in_room_in_list(array_list) == KO)
        return KO;
    return OK;
}

int get_file_info(file_info_t *file_info_n)
{
    char **file = my_load_stdin_in_array();
    if (file == NULL)
        return KO;
    if (*file == NULL)
        return KO;
    clear_commente_in_file(file);
    if (is_start_end(file, file_info_n) == KO)
        return KO;
    if (get_nb_ant(file_info_n, file) == KO)
        return KO;
    for (int i = 1; file[i] != NULL; i += 1) {
        if (get_file_info_sub(file_info_n, file, i) == KO)
            return KO;
    }
    free_map(file);
    if (is_element_in_list(file_info_n->array_list, file_info_n->nb_start_room,
    file_info_n->nb_end_room) == KO)
        return KO;
    return OK;
}
