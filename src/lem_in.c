/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int connect_two_link(elt_t *array_list, int first_nb, int second_nb)
{
    elt_t *tmp_1 = array_list;
    elt_t *tmp_2 = array_list;
    for (int i = 0; tmp_1 != NULL && tmp_1->data->data != first_nb; i += 1){
        tmp_1 = tmp_1->next;
    }
    for (int i = 0; tmp_2 != NULL && tmp_2->data->data != second_nb; i += 1){
        tmp_2 = tmp_2->next;
    }
    connect_links(tmp_1->data, tmp_2->data);
    connect_links(tmp_2->data, tmp_1->data);
    return 0;
}

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

int display_line(char *line, ssize_t nread, elt_t **array_list)
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
        int first_nb = atoi(str_plit[0]);
        int second_nb = atoi(str_plit[1]);
        connect_two_link((*array_list), first_nb, second_nb);
        free_map(str_plit);
    }
    return 0;
}

void free_all(elt_t *array_list)
{
    for (int i = 0; array_list != NULL; i += 1){
        elt_t *tmp = array_list;
        if (array_list->data->sub_branches != NULL)
            free(array_list->data->sub_branches);
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
    write(1, "\n=========================================\n", 43);
    display_all_link(array_list);
    free_all(array_list);
    return 0;
}
