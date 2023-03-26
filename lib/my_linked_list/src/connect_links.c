/*
** EPITECH PROJECT, 2023
** bslem-in
** File description:
** connect_links
*/

#include <stdlib.h>
#include "graph.h"

static int get_nb_sub_branches(link_t **link_sub_branches)
{
    if (link_sub_branches == NULL)
        return 0;
    int i = 0;
    for (; link_sub_branches[i] != NULL; i += 1);
    return i;
}

static link_t **realloc_link(link_t *link, int nb_sub_branches_link)
{
    link_t **link_save = malloc(sizeof(link_t *) *
        (nb_sub_branches_link + 1));
    for (int i = 0; link->sub_branches[i] != NULL; i += 1) {
        link_save[i] = link->sub_branches[i];
    }
    link_save[nb_sub_branches_link] = NULL;
    free(link->sub_branches);
    return link_save;
}

void connect_links(link_t *link1, link_t *link2)
{
    if (link1->sub_branches != NULL) {
        int len = get_nb_sub_branches(link1->sub_branches);
        link1->sub_branches = realloc_link(link1, len + 1);
        link1->sub_branches[len] = link2;
        link1->sub_branches[len + 1] = NULL;
    } else {
        link1->sub_branches = malloc(sizeof(link_t *) * (2));
        link1->sub_branches[0] = link2;
        link1->sub_branches[1] = NULL;
    }
}
