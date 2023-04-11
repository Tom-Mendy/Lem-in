/*
** EPITECH PROJECT, 2023
** sort_roads
** File description:
** take in parameter a list of roads and will sort from
** the shortest to the longest
*/

#include "lem_in.h"

static void split_list(list_road_t *list_roads,
list_road_t **left, list_road_t **right)
{
    list_road_t (*slow) = list_roads;
    list_road_t (*fast) = list_roads->next;
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }
    (*left) = list_roads;
    (*right) = slow->next;
    slow->next = NULL;
}

static list_road_t *merge_lists(list_road_t *left, list_road_t *right)
{
    list_road_t (*result) = NULL;
    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (left->data <= right->data) {
        result = left;
        result->next = merge_lists(left->next, right);
    } else {
        result = right;
        result->next = merge_lists(left, right->next);
    }
    return result;
}

static void merge_sort(list_road_t *list_roads)
{
    if (list_roads == NULL || list_roads->next == NULL)
        return;
    list_road_t (*left);
    list_road_t (*right);
    split_list(list_roads, &left, &right);
    merge_sort(left);
    merge_sort(right);
    list_roads = merge_lists(left, right);
}

static void print_list(list_road_t *list_roads)
{
    list_road_t *tmp = list_roads;
    while (list_roads != NULL) {
        my_put_nbr(list_roads->len_road);
        list_roads = list_roads->next;
    }
    my_put_char('\n');
    free(tmp);
}

list_road_t *sort_roads(list_road_t *list_roads)
{
    list_road_t *tmp_road = list_roads;
    for (; tmp_road != NULL; tmp_road = tmp_road->next) {
        tmp_road->len_road = get_len_of_road(tmp_road->data);
    }
    my_put_str("Original list:\n");
    print_list(list_roads);
    merge_sort(list_roads);
    my_put_str("Sorted list:\n");
    print_list(list_roads);
    return list_roads;
}
