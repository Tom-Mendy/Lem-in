/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_start_end
*/

#include "lem_in.h"

static int get_nb_start(char **file,file_info_t *array_list, int i)
{
    if (my_str_cmp(file[i - 1], "##start\n") == OK){
        int nb_dash = my_count_nb_char_in_str(file[i], '-');
        if (nb_dash == 2){
            char **line_split = spliter(file[i], "\n");
            array_list->nb_start_room = my_get_nbr(line_split[0]);
        }
    }
    return KO;
}

int is_start_end(char **file, file_info_t *array_list)
{
    int start = 1;
    int end = 1;
    for (int i = 1; file[i] != NULL; i += 1){
        if (my_str_cmp(file[i], "##start\n") == OK)
            start = 1;
        get_nb_start(file, array_list, i);
        if (my_str_cmp(file[i], "##end\n") == OK)
            end = 1;
    }
    if (start == 0 || end == 0)
        return KO;
    return OK;
}
