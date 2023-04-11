/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** connect_two_link
*/

#include "lem_in.h"

int connect_two_link(elt_t *array_list, char * first_name, char * second_name)
{
    list_type_t *tmp_1 = get_room_in_list_from_nb_room(first_name, array_list);
    list_type_t *tmp_2 = get_room_in_list_from_nb_room(second_name, array_list);
    if (tmp_1 == NULL || tmp_2 == NULL){
        return KO;
    }
    if (connect_links(tmp_1, tmp_2) == KO)
        return KO;
    if (connect_links(tmp_2, tmp_1) == KO)
        return KO;
    return OK;
}
