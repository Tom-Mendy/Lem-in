/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** is_start_end
*/

#include "lem_in.h"

static int get_nb_start_end(char **file,file_info_t *file_info_n, int const i,
char const * const str)
{
    if (my_str_cmp(file[i - 1], str) == OK){
        int nb_space = my_count_nb_char_in_str(file[i], ' ');
        if (nb_space != 2)
            return KO;
        char **line_split = spliter(file[i], " ");
        if (check_good_formating_room_line(line_split, 3) == KO)
            return KO;
        if (my_str_cmp(str, "##end") == 0)
            file_info_n->name_end_room = line_split[0];
        if (my_str_cmp(str, "##start") == 0)
            file_info_n->name_start_room = line_split[0];
        for (int i = 1; line_split[i] != NULL; i += 1){
            free(line_split[i]);
        }
        free(line_split);
    }
    return OK;
}

int is_start_end(char **file, file_info_t *file_info_n, int i)
{
    if ((my_str_cmp(file[i], "##start") == OK && file_info_n->start == 1) ||
    (my_str_cmp(file[i], "##end") == OK && file_info_n->start == 1 &&
    file_info_n->end == 1))
        return KO;
    if (my_str_cmp(file[i], "##start") == OK)
        file_info_n->start = 1;
    if (get_nb_start_end(file, file_info_n, i, "##start") == KO)
        return KO;
    if (my_str_cmp(file[i], "##end") == OK && file_info_n->start == 1)
        file_info_n->end = 1;
    if (get_nb_start_end(file, file_info_n, i, "##end") == KO)
        return KO;
    return OK;
}
