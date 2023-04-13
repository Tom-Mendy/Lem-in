/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** link_between_room
*/

#include "lem_in.h"

int is_two_the_same_room(char *first_name, char *second_name)
{
    if (my_str_cmp(first_name, second_name) == OK){
        free(first_name);
        free(second_name);
        return KO;
    }
    return OK;
}

int is_two_room_already_link(char *first_name, char *second_name,
elt_t *array_list)
{
    elt_t * tmp = array_list;
    while (tmp != NULL && my_str_cmp(tmp->data->name_room, first_name) != 0){
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return KO;
    if (tmp->data->sub_branches == NULL)
        return OK;
    for (int i = 0; tmp->data->sub_branches[i] != NULL; i += 1){
        if (my_str_cmp(tmp->data->sub_branches[i]->name_room, second_name)
        == OK){
            free(first_name);
            free(second_name);
            return KO;
        }
    }
    return OK;
}

int is_str_split_link_good_len(char **str_plit, elt_t **array_list)
{
    if (my_map_len(str_plit) != 2){
        free_link_list_room(*array_list);
        free_map(str_plit);
        return KO;
    }
    return OK;
}

int link_between_room(char *line, elt_t **array_list)
{
    char **str_plit = spliter(line, "-");
    if (is_str_split_link_good_len(str_plit, array_list) == KO)
        return KO;
    char *first_name = generate_malloc_str_from_str(str_plit[0]);
    char *second_name = generate_malloc_str_from_str(str_plit[1]);
    free_map(str_plit);
    if (is_two_the_same_room(first_name, second_name) == KO)
        return KO;
    if (is_two_room_already_link(first_name, second_name, *array_list) == KO)
        return KO;
    if (connect_two_link((*array_list), first_name, second_name) == KO){
        free(first_name);
        free(second_name);
        return KO;
    }
    free(first_name);
    free(second_name);
    return OK;
}
