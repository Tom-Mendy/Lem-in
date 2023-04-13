/*
** EPITECH PROJECT, 2023
** move ants
** File description:
** move ants
*/

#include "lem_in.h"

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

int display_line(bool *check_display_line, int j, move_ants_t *move_ant)
{
    if (move_ant->name_room != NULL) {
        char * name_room_before = NULL;
        if (j - 1 >= 0) {
            name_room_before = get_name_from_index_room_list
            (move_ant->paths->data, move_ant->roads[j - 1]);
        }
        if (name_room_before != NULL)
            my_put_char(' ');
        my_put_char('P');
        my_put_nbr(move_ant->roads[j]);
        my_put_char('-');
        my_put_str(move_ant->name_room);
        (*check_display_line) = true;
    }
    return 0;
}

int print_all_movements(int *roads, list_road_t *paths,
bool *check_display_line, file_info_t file_info_n)
{
    for (int j = 0; j != paths->len_road; j += 1) {
        if (roads[j] > 0 && roads[j] <= file_info_n.nb_ant) {
            char * name_room = get_name_from_index_room_list(paths->data,
            j + 1);
            move_ants_t move_ant = {.name_room = name_room, .paths = paths,
            .roads = roads};
            display_line(check_display_line, j, &move_ant);
        }
    }
    return 0;
}

void move_ants_in_tab(list_road_t *paths, int *roads)
{
    for (int j = 1; j != paths->len_road ; j += 1){
        if (roads[j - 1] > 0)
            roads[j] = roads[j - 1] - 1;
    }
}

void move_ants(file_info_t file_info_n, list_road_t *paths)
{
    my_put_str("#moves\n");
    int *roads = malloc(sizeof(int) * (paths->len_road + 1));
    bool check_display_line = false;
    for (int i = 0; i != paths->len_road; i += 1) {
        roads[i] = 0;
    }
    for (int i = 1; roads[paths->len_road - 1] != file_info_n.nb_ant; i += 1){
        roads[0] = i;
        check_display_line = false;
        move_ants_in_tab(paths, roads);
        print_all_movements(roads, paths, &check_display_line, file_info_n);
        if (check_display_line == true)
            my_put_char('\n');
    }
    free(roads);
}
