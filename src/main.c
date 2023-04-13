/*
** EPITECH PROJECT, 2023
** my_scripts
** File description:
** main
*/

#include "lem_in.h"

int main(int argc, char const* const* argv)
{
    if (argc != 1 || argv[0] == NULL)
        return KO;
    return lem_in();
}
