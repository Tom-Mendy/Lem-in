/*
** EPITECH PROJECT, 2023
** new_project_folder_file
** File description:
** my_load_file_in_array
*/

#include <stdlib.h>
#include "spliter.h"
#include "my_str.h"
#include "lem_in.h"

char **my_load_stdin_in_array(void)
{
    char *str = my_load_stdin_in_memory();
    if (str == NULL)
        return NULL;
    char **array = spliter(str, "\n");
    free(str);
    return array;
}
