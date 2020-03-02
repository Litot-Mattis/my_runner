##
## EPITECH PROJECT, 2018
## Makefile_my_hunter
## File description:
## makefile
##

CC	=	gcc -I include

SRC	=	src/my_hunter.c		\
		src/my_create.c		\
		src/my_putstr.c 	\
		src/parralax.c 	\
		src/parralax2.c 	\
		src/main.c		\
		src/last_fond.c		\
		src/second_fond.c 	\
		src/first_fond.c	\
		src/menu.c		\
		src/rect.c 		\
		src/ground.c 	\
		src/map.c 		\
		src/obstacle.c 	\
		src/second_main.c 	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_runner

all: $(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) -g3 -l csfml-graphics -l csfml-audio -l csfml-system -lcsfml-window -l m

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: clean fclean re
