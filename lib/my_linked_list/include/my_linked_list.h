/*
** EPITECH PROJECT, 2023
** B-PSU-100-BDX-1-1-myls-tom.mendy
** File description:
** my_list
*/

#ifndef MY_LIST_H_
    #define MY_LIST_H_
    #include <stdlib.h>
    #include <stdbool.h>
    #include "my_str.h"
    #include "my_int.h"
    typedef struct list_type{
        int data;
        int x;
        int y;
        struct list_type **sub_branches;
    }list_type_t;
    typedef struct elt {
        list_type_t *data;
        struct elt *next;
        struct elt *prev;
    }elt_t;
    int get_list_size(elt_t * list);
    int put_end_list(elt_t **list, list_type_t *value);
    void delete_first_element_list(elt_t **list);
    void delete_actual_node_list(elt_t *list);
    list_type_t *create_link(int const data, int const x, int const y);
    void print_link(list_type_t *link);
    void connect_links(list_type_t *link1, list_type_t *link2);
    void print_data_of_connected_links(list_type_t *link);
    void print_my_graph_data(list_type_t *graph);
#endif /* !MY_LIST_H_ */
