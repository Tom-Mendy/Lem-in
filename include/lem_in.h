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
    #define OK 0
    #define KO 84
    int lem_in(void);
    int free_map(char **map);
    void display_all_link(elt_t *array_list);
    int my_count_nb_char_in_str(char *str, char spe_char);
    void print_cordinate_link(list_type_t *link);
#endif /* !LEM_IN_H_ */
