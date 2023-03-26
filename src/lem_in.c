/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int display_line(char *line, ssize_t nread, elt_t **array_list)
{
    int nb_space = my_count_nb_char_in_str(line, ' ');
    int nb_dash = my_count_nb_char_in_str(line, '-');
    if (my_str_cmp(line, "##start\n") == OK)
        write(1, line, nread);
    if (my_str_cmp(line, "##end\n") == OK)
        write(1, line, nread);
    if (nb_space == 2) {
        write(1, line, nread);
        char **str_plit = spliter(line, " \n");
        list_type_t *tmp = create_link(my_get_nbr(str_plit[0]),
        my_get_nbr(str_plit[1]), my_get_nbr(str_plit[2]));
        put_end_list(array_list, tmp);
        free_map(str_plit);
    }
    if (nb_dash == 1 && line[0] != '-')
        write(1, line, nread);
    return 0;
}

void print_cordinate_link(list_type_t *link)
{
    if (link != NULL){
        my_put_nbr(link->x);
        write(1, "\n", 1);
        my_put_nbr(link->y);
        write(1, "\n", 1);
    }
}

void free_all(elt_t *array_list)
{
    for (int i = 0; array_list != NULL; i += 1){
        print_link(array_list->data);
        print_cordinate_link(array_list->data);
        print_data_of_connected_links(array_list->data);
        elt_t *tmp = array_list;
        free(array_list->data);
        array_list = array_list->next;
        free(tmp);
    }
    free(array_list);
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
        display_line(line, nread, &array_list);
        nread = getline(&line, &len, stdin);
    }
    free(line);
    write(1, "\n==========================\n", 28);
    free_all(array_list);
    return 0;
}
