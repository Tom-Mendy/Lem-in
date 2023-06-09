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

int is_element_in_list(elt_t *array_list, char *start, char *end)
{
    if (is_room_in_list(array_list, start, end) == KO)
        return KO;
    if (is_pipe_in_room_in_list(array_list) == KO)
        return KO;
    return OK;
}

int loop_get_file_info(file_info_t *file_info_n)
{
    for (int i = 1; file_info_n->file[i] != NULL; i += 1) {
        if (is_start_end(file_info_n->file, file_info_n, i) == KO)
            return KO;
        if (get_file_info_sub(file_info_n, file_info_n->file, i) == KO)
            return KO;
        display_title_room_tunnel(file_info_n, i);
        if (!(file_info_n->room == 0 && my_str_cmp(file_info_n->file[i],
        "##start") == 0)){
            my_put_str(file_info_n->file[i]);
            my_put_char('\n');
        }
    }
    return OK;
}

int get_file_info(file_info_t *file_info_n)
{
    file_info_n->file = my_load_stdin_in_array();
    if (file_info_n->file == NULL)
        return KO;
    if (*file_info_n->file == NULL)
        return KO;
    clear_commente_in_file(file_info_n->file);
    if (get_nb_ant(file_info_n, file_info_n->file) == KO)
        return KO;
    display_number_of_ant(file_info_n->nb_ant);
    if (loop_get_file_info(file_info_n) == KO)
        return KO;
    if (file_info_n->start == 0 || file_info_n->end == 0){
        free_map(file_info_n->file);
        return KO;
    }
    if (is_element_in_list(file_info_n->array_list,
    file_info_n->name_start_room, file_info_n->name_end_room) == KO)
        return KO;
    return OK;
}
