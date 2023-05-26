/*
** EPITECH PROJECT, 2023
** move ants
** File description:
** move ants
*/

#include "lem_in.h"

static void move_ants_in_tab(list_road_t *paths, int *roads)
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
