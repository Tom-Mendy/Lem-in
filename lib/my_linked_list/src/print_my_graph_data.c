/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** print_my_graph_data
*/

#include <stdlib.h>
#include "graph.h"

void print_my_graph_data(link_t *graph)
{
    print_link(graph);
    if (graph->sub_branches != NULL) {
        for (int i = 0; graph->sub_branches[i] != NULL; i += 1) {
            print_my_graph_data(graph->sub_branches[i]);
        }
    }
}
