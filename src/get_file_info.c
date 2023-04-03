/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** get_file_info
*/

#include "lem_in.h"

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
    if (my_str_is_num(file[0]) == false)
        return KO;
    file_info_n->nb_ant = my_get_nbr(file[0]);
    for (int i = 1; file[i] != NULL; i += 1) {
        add_line_info_to_struct(file[i], &(file_info_n->array_list), &i);
    }
    free_map(file);
    return OK;
}
