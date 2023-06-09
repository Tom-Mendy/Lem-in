/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#ifndef LEM_IN_H_
    #define LEM_IN_H_
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <stdio.h>
    #include "my_str.h"
    #include "my_int.h"
    #include "my_linked_list.h"
    #include "spliter.h"
    typedef struct file_info_s{
        int nb_ant;
        char * name_start_room;
        char *name_end_room;
        elt_t *array_list;
        char **file;
        int start;
        int end;
        int room;
        int tunnel;
    }file_info_t;
    typedef struct list_room_s{
        char * name_room;
        struct list_room_s *next;
        struct list_room_s *prev;
    }list_room_t;
    typedef struct list_road_s{
        list_room_t *data;
        int len_road;
        struct list_road_s *next;
        struct list_road_s *prev;
    }list_road_t;
    typedef struct move_ants_s {
        char *name_room;
        int *roads;
        list_road_t *paths;
    }move_ants_t;

    #define OK 0
    #define KO 84
    int lem_in(void);
    int free_map(char **map);
    void display_all_link(elt_t *array_list);
    int my_count_nb_char_in_str(char *str, char spe_char);
    void print_cordinate_link(list_type_t *link);
    void free_link_list_room(elt_t *array_list);
    int connect_two_link(elt_t *array_list, char * first_name,
    char * second_name);
    int get_file_info(file_info_t *file_info_n);
    char *my_load_stdin_in_memory(void);
    char **my_load_stdin_in_array(void);
    int clear_commente_in_file(char **file);
    int add_line_info_to_struct(char *line, elt_t **array_list);
    int is_start_end(char **file, file_info_t *file_info_n, int i);
    int is_pipe_in_room_in_list(elt_t *array_list);
    int is_room_already_in_list(elt_t *array_list, char * name_room);
    int is_room_coordinate_already_in_list(elt_t *array_list, int x, int y);
    int is_room_in_list(elt_t *array_list, char *start, char *end);
    int my_map_len(char **map);
    int check_good_formating_room_line(char **str_plit, int nb_value);
    list_road_t *list_all_road(file_info_t *file_info);
    int put_end_list_road(list_road_t **list, list_room_t *value);
    int put_end_list_room(list_room_t **list, char * name_room);
    char *generate_malloc_str_from_str(char const *const str);
    int get_index_from_nb_room(char * name_room, list_room_t *possible_road);
    list_type_t *get_room_in_list_from_nb_room(char *name_room,\
    elt_t *array_list);
    int get_len_of_road(list_room_t *road);
    void display_list_possible_road(list_room_t *possible_road);
    int free_end_list_room(list_room_t **possible_road);
    int free_paths(list_road_t *paths);
    list_road_t *sort_roads(list_road_t *list_roads);
    list_room_t *find_second_road(list_road_t **road);
    void print_list(list_road_t *list_roads);
    int link_between_room(char *line, elt_t **array_list);
    int display_title_room_tunnel(file_info_t *file_info_n, int i);
    int display_number_of_ant(int nb_ant);
    void move_ants(file_info_t file_info_n, list_road_t *paths);
    int print_all_movements(int *roads, list_road_t *paths,
    bool *check_display_line, file_info_t file_info_n);
#endif /* !LEM_IN_H_ */
