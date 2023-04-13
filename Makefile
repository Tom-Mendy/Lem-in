##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile
##

SRC			=	lem_in.c												\
				free_map.c												\
				my_count_nb_char_in_str.c								\
				display_all_link.c										\
				print_cordinate_link.c									\
				my_map_len.c											\
				free_link_list_room.c									\
				get_index_from_nb_room.c								\
				get_room_in_list_from_nb_room.c							\
				free_paths.c											\
				get_file_info/generate_malloc_str_from_str.c			\
				get_file_info/connect_two_link.c						\
				get_file_info/check_good_formating_line.c				\
				get_file_info/my_load_stdin_in_array.c					\
				get_file_info/my_load_stdin_in_memory.c					\
				get_file_info/clear_commente_in_file.c					\
				get_file_info/add_line_info_to_struct.c					\
				get_file_info/is_start_end.c							\
				get_file_info/get_file_info.c							\
				get_file_info/is_pipe_in_room_in_list.c					\
				get_file_info/is_room_in_list.c							\
				get_file_info/is_room_coordinate_already_in_list.c		\
				get_file_info/is_room_already_in_list.c					\
				get_file_info/display_title_room_tunnel.c				\
				get_file_info/link_between_room.c						\
				get_file_info/display_number_of_ant.c					\
				list_all_roads/put_end_list_road.c						\
				list_all_roads/free_end_list_room.c						\
				list_all_roads/display_list_possible_road.c				\
				list_all_roads/put_end_list_room.c						\
				list_all_roads/list_all_road.c							\
				sort_roads/chose_bests_roads.c							\
				sort_roads/sort_roads.c									\
				display_all/move_ants.c

DIR_SRC		=	$(addprefix src/, $(SRC))

MAIN_SRC	=	src/main.c

TEST		=	test.c\

DIR_TESTS	=	$(addprefix tests/, $(TEST))

OBJ_DIR_SRC	=	$(DIR_SRC:.c=.o)

OBJ_MAIN	=	$(MAIN_SRC:.c=.o)

OBJ			=	$(OBJ_DIR_SRC) $(OBJ_MAIN)

LDLIBS		=	-L lib/ -l my_str -l my_printf -l my_linked_list -l my_int

CPPFLAGS	=	-I include/ -I lib/my_str/include -I lib/my_printf/include\
				-I lib/my_linked_list/include -I lib/my_int/include

CFLAGS		=	-Wall -Wextra -ggdb3

NAME		=	lem_in

LIBS		=	lib/libmy_str.a\
				lib/libmy_printf.a\
				lib/libmy_linked_list.a\
				lib/libmy_int.a

all: make_libs $(NAME)

$(NAME):	$(LIBS) $(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDLIBS) $(CPPFLAGS) $(CFLAGS)

make_libs:
	make -C lib/my_int
	make -C lib/my_str
	make -C lib/my_printf
	make -C lib/my_linked_list

clean:
		make clean -C lib/my_int
		make clean -C lib/my_str
		make clean -C lib/my_printf
		make clean -C lib/my_linked_list
		rm -f $(OBJ)

fclean: clean
		make fclean -C lib/my_int
		make fclean -C lib/my_str
		make fclean -C lib/my_printf
		make fclean -C lib/my_linked_list
		rm -rf unit_tests
		rm -rf *.gcov
		rm -f $(NAME)

re:		fclean all

unit_tests:	re
		mkdir unit_tests
		make unit_tests -C lib/my_int
		make unit_tests -C lib/my_str
		gcc -o unit_tests/unit_tests $(DIR_SRC) $(DIR_TESTS)\
		$(CPPFLAGS) $(LDLIBS) --coverage -lcriterion

tests_run:	unit_tests
		make tests_run -C lib/my_int
		make tests_run -C lib/my_str
		./unit_tests/unit_tests

.PHONY: all clean fclean re make_libs tests_run
