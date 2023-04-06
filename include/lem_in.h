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
        int nb_start_room;
        int nb_end_room;
        elt_t *array_list;
    }file_info_t;
    #define OK 0
    #define KO 84
    int lem_in(void);
    int free_map(char **map);
    void display_all_link(elt_t *array_list);
    int my_count_nb_char_in_str(char *str, char spe_char);
    void print_cordinate_link(list_type_t *link);
    void free_link_list_room(elt_t *array_list);
    int connect_two_link(elt_t *array_list, int first_nb, int second_nb);
    int get_file_info(file_info_t *file_info_n);
    char *my_load_stdin_in_memory(void);
    char **my_load_stdin_in_array(void);
    int clear_commente_in_file(char **file);
    int add_line_info_to_struct(char *line, elt_t **array_list);
    int is_start_end(char **file, file_info_t *array_list);
    int is_pipe_in_room_in_list(elt_t *array_list);
    int is_room_already_in_list(elt_t *array_list, int nb);
    int is_room_coordinate_already_in_list(elt_t *array_list, int x, int y);
    int is_room_in_list(elt_t *array_list, int start, int end);
#endif /* !LEM_IN_H_ */
