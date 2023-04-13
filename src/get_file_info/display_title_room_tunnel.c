/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** display_title_room_tunnel
*/

#include "lem_in.h"

int display_title_room_tunnel(file_info_t *file_info_n, int i)
{
    int nb_space = my_count_nb_char_in_str(file_info_n->file[i], ' ');
    int nb_dash = my_count_nb_char_in_str(file_info_n->file[i], '-');
    if (nb_space == 2 && file_info_n->room == 0){
        my_put_str("#rooms\n");
        if (file_info_n->start == 1)
            my_put_str("##start\n");
        file_info_n->room = 1;
    }
    if (nb_dash == 1 && file_info_n->file[i][0] != '-' &&
    file_info_n->file[i][my_str_len(file_info_n->file[i]) - 1] != '-' &&
    file_info_n->tunnel == 0) {
        my_put_str("#tunnels\n");
        file_info_n->tunnel = 1;
    }
    return KO;
}
