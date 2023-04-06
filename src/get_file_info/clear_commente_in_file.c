/*
** EPITECH PROJECT, 2023
** Lem-in
** File description:
** clear_commente_in_file
*/

#include "lem_in.h"

static void clear_commente_in_file_sub(char **file, int const i)
{
    free(file[i]);
    int j = i;
    for (; file[j] != NULL; j += 1) {
        file[j] = file[j + 1];
    }
}

int clear_commente_in_file(char **file)
{
    if (file == NULL)
        return KO;
    for (int i = 1; file[i] != NULL; i += 1) {
        int nb_hashtag = my_count_nb_char_in_str(file[i], '#');
        if ((nb_hashtag == 1 && file[i][0] == '#'))
            clear_commente_in_file_sub(file, i);
    }
    return OK;
}
