##
## EPITECH PROJECT, 2018
## philosopher
## File description:
## makefile
##

CC      =	gcc

CFLAGS  =	-pedantic -Wall -Wextra -Winit-self -Wwrite-strings
CFLAGS  +=      -Wcast-align -Wshadow -Wredundant-decls -Wfloat-equal
CFLAGS  +=      -Wlogical-op -Winline -Wdouble-promotion
CFLAGS  +=      -Wunreachable-code -Iinclude/ -Ofast

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
<<<<<<< HEAD
		is_alive.c		\
		display_map_ncurses.c	\
		check_end.c		\
		continue_display.c	\
		check_start.c
=======
		display_map_ncurses.c \
		is_alive.c
>>>>>>> 07ad9759c618d14e942de096c9c46812e1d032c1

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
