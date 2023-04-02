/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** get_file_info
*/

#include "lem_in.h"

int point_with_cordinate(char *line, ssize_t nread, elt_t **array_list)
{
    write(1, line, nread);
    char **str_plit = spliter(line, " ");
    list_type_t *tmp = create_link(my_get_nbr(str_plit[0]),
    my_get_nbr(str_plit[1]), my_get_nbr(str_plit[2]));
    put_end_list(array_list, tmp);
    free_map(str_plit);
    return 0;
}

int add_line_info_to_struct(char *line, ssize_t nread, elt_t **array_list)
{
    int nb_space = my_count_nb_char_in_str(line, ' ');
    int nb_dash = my_count_nb_char_in_str(line, '-');
    if (my_str_cmp(line, "##start\n") == OK)
        write(1, line, nread);
    if (my_str_cmp(line, "##end\n") == OK)
        write(1, line, nread);
    if (nb_space == 2)
        point_with_cordinate(line, nread, array_list);
    if (nb_dash == 1 && line[0] != '-' && line[my_str_len(line) - 1] != '-'){
        write(1, line, nread);
        char **str_plit = spliter(line, "-");
        int first_nb = my_get_nbr(str_plit[0]);
        int second_nb = my_get_nbr(str_plit[1]);
        connect_two_link((*array_list), first_nb, second_nb);
        free_map(str_plit);
    }
    return 0;
}

int get_file_info(file_info_t *file_info_n)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    nread = getline(&line, &len, stdin);
    file_info_n->nb_ant = my_get_nbr(line);
    while (nread != -1) {
        add_line_info_to_struct(line, nread, &(file_info_n->array_list));
        nread = getline(&line, &len, stdin);
    }
    free(line);
    return 0;
}
