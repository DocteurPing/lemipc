##
## EPITECH PROJECT, 2018
## philosopher
## File description:
## makefile
##

CC      =	gcc

CFLAGS  =	-pedantic -Wall -Wextra -Winit-self -Wwrite-strings
CFLAGS  +=      -Wcast-align -Wshadow -Wredundant-decls -Wfloat-equal
CFLAGS  +=      -Wundef -Wlogical-op -Winline -Wdouble-promotion
CFLAGS  +=      -Wunreachable-code -Iinclude/ -Ofast

NAME    =	lemipc

RM      =	rm -f

SRCDIR	=	src

SRC     =	main.c			\
		parse_params.c		\
		print_usage.c		\
		check_start.c		\
		close_and_clean.c	\
		display_map.c

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
