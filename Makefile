##
## EPITECH PROJECT, 2018
## philosopher
## File description:
## makefile
##

CC      =	gcc

CFLAGS  =	-W -Wall -Wextra -Iinclude

LFLAGS	=	-lncurses

NAME    =	lemipc

RM      =	rm -f

SRCDIR	=	src

SRC     =	main.c			\
		parse_params.c		\
		print_usage.c		\
		fill_main_struct.c	\
		close_and_clean.c	\
		init_player.c 		\
		display_map.c		\
		my_semaphore.c		\
		player_action.c		\
		game_loop.c		\
		get_tab_player.c	\
		is_alive.c		\
		display_map_ncurses.c	\
		check_end.c		\
		continue_display.c	\
		check_start.c

SRC     :=      $(addprefix $(SRCDIR)/, $(SRC))

OBJ     =       $(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LFLAGS)

debug:	CFLAGS+= -DDEBUG -g3
debug:	$(NAME)

clean:
	$(RM) $(addsuffix ~, $(SRC))
	$(RM) $(OBJ)

fclean:
	$(RM) $(addsuffix ~, $(SRC))
	$(RM) $(OBJ)
	$(RM) $(NAME)

re:	fclean all

.PHONY: all libs clean fclean re
