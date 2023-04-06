/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** add_line_info_to_struct
*/

#include "lem_in.h"

int point_with_cordinate(char *line, elt_t **array_list)
{
    char **str_plit = spliter(line, " ");
    int nb_room = my_get_nbr(str_plit[0]);
    int x = my_get_nbr(str_plit[1]);
    int y = my_get_nbr(str_plit[2]);
    if (is_room_already_in_list(*array_list, nb_room) == 84) {
        free_map(str_plit);
        return KO;
    }
    if (is_room_coordinate_already_in_list(*array_list, x, y) == 84) {
        free_map(str_plit);
        return KO;
    }
    list_type_t *tmp = create_link(nb_room, x, y);
    put_end_list(array_list, tmp);
    free_map(str_plit);
    return OK;
}

int add_line_info_to_struct(char *line, elt_t **array_list)
{
    int nb_space = my_count_nb_char_in_str(line, ' ');
    int nb_dash = my_count_nb_char_in_str(line, '-');
    if (nb_space == 2)
        return point_with_cordinate(line, array_list);
    if (nb_dash == 1 && line[0] != '-' && line[my_str_len(line) - 1] != '-') {
        char **str_plit = spliter(line, "-");
        int first_nb = my_get_nbr(str_plit[0]);
        int second_nb = my_get_nbr(str_plit[1]);
        if (connect_two_link((*array_list), first_nb, second_nb) == KO)
            return KO;
        free_map(str_plit);
        return OK;
    }
    return OK;
}
