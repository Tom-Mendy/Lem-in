/*
** EPITECH PROJECT, 2023
** display
** File description:
** display
*/
#include "lem_in.h"

int check_file(char *str)
{
    for (int a = 0; str[a] != '\0'; a += 1){
        if (str[a] == '-')
            return 1;
    }
    return 0;
}

void display_all(file_info_t file_info_n)
{
    int res = 0;
    my_put_str("#number_of_ants");
    my_put_char('\n');
    for (int i = 0; file_info_n.file[i] != NULL; i += 1){
        if (i == 1){
            my_put_str("#rooms");
            my_put_char('\n');
        }
        if (check_file(file_info_n.file[i]) == 1 && res == 0){
            my_put_str("#tunnels");
            my_put_char('\n');
            res = 1;
        }
        my_put_str(file_info_n.file[i]);
        my_put_char('\n');
    }
my_put_str("#moves");
my_put_char('\n');
}
