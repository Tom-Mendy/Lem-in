/*
** EPITECH PROJECT, 2023
** minishell2
** File description:
** test_load_file_in_memory
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_str.h"

Test(load_file_in_memory, basic) {
    char *tkt = my_load_file_in_memory("Makefile");
    char *Makfefile_info = "##\n\
## EPITECH PROJECT, 2023\n\
## makefile\n\
## File description:\n\
## makefile\n\
##\n\
\n\
SRC     =	my_count_nb_char_in_str.c					\\\n\
			my_is_alpha.c								\\\n\
			my_is_lower.c								\\\n\
			my_is_num.c									\\\n\
			my_is_printable.c							\\\n\
			my_is_upper.c								\\\n\
			my_load_file_in_array.c						\\\n\
			my_load_file_in_memory.c					\\\n\
			my_put_char.c								\\\n\
			my_put_str.c								\\\n\
			my_rev_str.c								\\\n\
			my_show_word_array.c						\\\n\
			my_str_capitalize.c							\\\n\
			my_str_cat.c								\\\n\
			my_str_cmp.c								\\\n\
			my_str_cpy.c								\\\n\
			my_str_is_alpha.c							\\\n\
			my_str_is_lower.c							\\\n\
			my_str_is_num.c								\\\n\
			my_str_is_printable.c						\\\n\
			my_str_is_upper.c							\\\n\
			my_str_len.c								\\\n\
			my_str_low_case.c							\\\n\
			my_str_n_cat.c								\\\n\
			my_str_n_cmp.c								\\\n\
			my_str_n_cpy.c								\\\n\
			my_str_str.c								\\\n\
			my_str_up_case.c							\\\n\
			spliter/add_word.c							\\\n\
			spliter/change_begin_str.c					\\\n\
			spliter/generate_tab.c						\\\n\
			spliter/str_only_contain_str_delimiter.c	\\\n\
			spliter/spliter.c							\\\n\
			my_swap.c									\\\n\
\n\
DIR_SRC	=		$(addprefix src/, $(SRC))\n\
\n\
TEST	=	test_my_put_char.c							\\\n\
			test_load_file_in_memory.c					\\\n\
			test_my_put_str.c							\\\n\
			test_my_rev_str.c							\\\n\
			test_my_show_word_array.c					\\\n\
			test_my_str_capitalize.c					\\\n\
			test_my_str_cat.c							\\\n\
			test_my_str_cmp.c							\\\n\
			test_my_str_cpy.c							\\\n\
			test_my_str_is_alpha.c						\\\n\
			test_my_str_is_lower.c						\\\n\
			test_my_str_is_num.c						\\\n\
			test_my_str_is_printable.c					\\\n\
			test_my_str_is_upper.c						\\\n\
			test_my_str_len.c							\\\n\
			test_my_str_low_case.c						\\\n\
			test_my_str_n_cat.c							\\\n\
			test_my_str_n_cmp.c							\\\n\
			test_my_str_n_cpy.c							\\\n\
			test_my_str_str.c							\\\n\
			test_my_str_up_case.c						\\\n\
			test_my_swap.c								\\\n\
			test_spliter.c								\\\n\
\n\
DIR_TESTS	=		$(addprefix tests/, $(TEST))\n\
\n\
OBJ			=		$(DIR_SRC:.c=.o)\n\
\n\
OBJ_TESTS	=		$(DIR_TESTS:.c=.o)\n\
\n\
CPPFLAGS	= -I include -Wextra -Wall -ggdb3\n\
\n\
NAME		=		../libmy_str.a\n\
\n\
$(NAME):		$(OBJ)\n\
	ar rcs $(NAME) $(OBJ)\n\
\n\
all: $(NAME)\n\
\n\
clean:\n\
	rm -f $(OBJ)\n\
\n\
fclean: clean\n\
	rm -rf unit_tests\n\
	rm -rf *.gcov\n\
	rm -f $(NAME)\n\
\n\
re: fclean all\n\
\n\
unit_tests: re\n\
	mkdir unit_tests\n\
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS) -I include/\\\n\
		--coverage -lcriterion\n\
\n\
tests_run:	unit_tests\n\
			./unit_tests/unit_tests\n\
\n\
.PHONY: all clean fclean re tests_run\n\
";
    cr_assert_str_eq(tkt, Makfefile_info);
    free(tkt);
}

Test(load_file_in_memory, rigor) {
    char *str = NULL;
    cr_assert_eq(my_put_str(str), -1);
}
