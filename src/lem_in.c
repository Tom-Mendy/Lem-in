/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** lem_in
*/

#include "lem_in.h"

int lem_in(int argc, char **argv)
{
    char **str = my_load_file_in_array("Makefile");
    if (str == NULL)
        return 84;
    for (int i = 0; str[i] != NULL ; i += 1){
        printf("%s\n", str[i]);
    }
    for (int i = 0; str[i] != NULL; i += 1){
        free(str[i]);
    }
    free(str);
    return 0;
}
