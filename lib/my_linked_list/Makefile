##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	delete_actual_node_list.c				\
				delete_first_element_list.c				\
				get_list_size.c							\
				put_end_list.c							\
				connect_links.c							\
				create_link.c							\
				print_data_of_connected_links.c			\
				print_link.c							\
				print_my_graph_data.c

EXT			=	../my_str/src/my_put_str.c				\
				../my_str/src/my_put_char.c				\
				../my_int/src/my_put_nbr.c				\
				../my_str/src/my_str_len.c				\

DIR_SRC	=		$(addprefix src/, $(SRC))

OBJ			=	$(DIR_SRC:.c=.o)

OBJ_EXT		=	$(EXT:.c=.o)

NAME		=	../libmy_linked_list.a

CPPFLAGS	=	-I include/\
				-I ../my_str/include\
				-I ../my_int/include\
				-Wextra -Wall -ggdb3

$(NAME):	$(OBJ) $(OBJ_EXT)
	ar rcs $@ $(OBJ) $(OBJ_EXT)

all: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_EXT)

fclean:	clean
	rm -f $(NAME)
	rm -f unit_tests*

re: fclean all

unit_tests:	re
		gcc -o unit_tests $(SRC) tests/test_printf.c $(CPPFLAGS)\
		--coverage -lcriterion

tests_run:	unit_tests
			./unit_tests

.PHONY: all clean fclean
