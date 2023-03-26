/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int display_line(char *line, ssize_t nread)
{
    int nb_space = my_count_nb_char_in_str(line, ' ');
    int nb_dash = my_count_nb_char_in_str(line, '-');
    if (my_str_cmp(line, "##start\n") == OK)
        write(1, line, nread);
    if (my_str_cmp(line, "##end\n") == OK)
        write(1, line, nread);
    if (nb_space == 2)
        write(1, line, nread);
    if (nb_dash == 1 && line[0] != '-')
        write(1, line, nread);
    return 0;
}

int lem_in(void)
{
    elt_t *array_list = NULL;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread = 0;
    nread = getline(&line, &len, stdin);
    int nb_ant = my_get_nbr(line);
    while (nread != -1) {
        display_line(line, nread);
        nread = getline(&line, &len, stdin);
    }
    free(line);
    return 0;
}
