/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_start_end
*/

#include "lem_in.h"

static int get_nb_start(char **file, file_info_t *file_info_n, int i)
{
    if (my_str_cmp(file[i - 1], "##start") == OK){
        int nb_space = my_count_nb_char_in_str(file[i], ' ');
        if (nb_space != 2)
            return KO;
        char **line_split = spliter(file[i], " ");
        file_info_n->nb_start_room = my_get_nbr(line_split[0]);
    }
    return OK;
}

static int get_nb_end(char **file,file_info_t *file_info_n, int i)
{
    if (my_str_cmp(file[i - 1], "##end") == OK){
        int nb_space = my_count_nb_char_in_str(file[i], ' ');
        if (nb_space != 2)
            return KO;
        char **line_split = spliter(file[i], " ");
        file_info_n->nb_end_room = my_get_nbr(line_split[0]);
    }
    return OK;
}

int is_start_end(char **file, file_info_t *file_info_n)
{
    int start = 0;
    int end = 0;
    for (int i = 1; file[i] != NULL; i += 1){
        if ((my_str_cmp(file[i], "##start") == OK && start == 1) ||
        (my_str_cmp(file[i], "##end") == OK && start == 1 && end == 1))
            return KO;
        if (my_str_cmp(file[i], "##start") == OK)
            start = 1;
        if (get_nb_start(file, file_info_n, i) == KO)
            return KO;
        if (my_str_cmp(file[i], "##end") == OK && start == 1)
            end = 1;
        if (get_nb_end(file, file_info_n, i) == KO)
            return KO;
    }
    if (start == 0 || end == 0)
        return KO;
    return OK;
}
