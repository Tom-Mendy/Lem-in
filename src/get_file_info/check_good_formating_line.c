/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** check_good_formating_line
*/

#include "lem_in.h"

int check_good_formating_room_line(char **str_plit, int nb_value)
{
    if (my_map_len(str_plit) != nb_value){
        free_map(str_plit);
        return KO;
    }
    for (int j = 1; str_plit[j] != NULL; j += 1){
        if (my_str_is_num(str_plit[j]) == false){
            free_map(str_plit);
            return KO;
        }
    }
    return OK;
}
