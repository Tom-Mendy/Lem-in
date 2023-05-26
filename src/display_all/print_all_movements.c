/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** print_all_movements
*/

#include "lem_in.h"

char *get_name_from_name_room_list(list_room_t *room, char* name_room)
{
    list_room_t *tmp = room;
    for (int i = 0; tmp != NULL &&
    my_str_cmp(name_room, tmp->name_room); i += 1) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    return tmp->name_room;
}

char *get_name_from_index_room_list(list_room_t *room, int index)
{
    list_room_t *tmp = room;
    for (int i = 0; i < index && tmp != NULL; i += 1) {
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return NULL;
    return tmp->name_room;
}

int display_line(bool *check_display_line, int j, move_ants_t *move_ant,
int first_time_line)
{
    char * name_room_before = NULL;
    if (move_ant->name_room != NULL) {
        if (j - 1 >= 0) {
            name_room_before = get_name_from_name_room_list
            (move_ant->paths->data, move_ant->name_room);
        }
        if (name_room_before != NULL && first_time_line - j != 0)
            my_put_char(' ');
        my_put_char('P');
        my_put_nbr(move_ant->roads[j]);
        my_put_char('-');
        my_put_str(move_ant->name_room);
        (*check_display_line) = true;
    }
    return 0;
}

void check_is_begin_fisrt_move_ant_line_set(bool*
is_begin_fisrt_move_ant_line_set, int *first_time_line, int j)
{
    if (*is_begin_fisrt_move_ant_line_set == false){
        *is_begin_fisrt_move_ant_line_set = true;
        *first_time_line = j;
    }
}

int print_all_movements(int *roads, list_road_t *paths,
bool *check_display_line, file_info_t file_info_n)
{
    bool is_begin_fisrt_move_ant_line_set = false;
    int first_time_line = 0;

    for (int j = 0; j != paths->len_road; j += 1) {
        if (roads[j] > 0 && roads[j] <= file_info_n.nb_ant) {
            char * name_room = get_name_from_index_room_list(paths->data,
            j + 1);
            move_ants_t move_ant = {.name_room = name_room, .paths = paths,
            .roads = roads};
            check_is_begin_fisrt_move_ant_line_set(
            &is_begin_fisrt_move_ant_line_set, &first_time_line, j);
            display_line(check_display_line, j, &move_ant, first_time_line);
        }
    }
    return 0;
}
