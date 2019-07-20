##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

CC	=	gcc

NAME	=	navy

SRC	=	src/main.c			\
		src/my_check_connection.c	\
		src/check_pos.c			\
		src/my_attack.c			\
		src/my_rescive_attack.c		\
		src/check_pos_bis.c		\
		src/create_map.c		\
		src/create_map_bis.c		\
		src/print_map.c			\
		src/put_shot.c			\
		src/game.c			\
		src/utility.c			\

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-L./lib/ -lmy -lline

CFLAGS	+=	-I./include

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/my
	make -C lib/get_next_line
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	make -C lib/get_next_line clean
	make -C lib/my clean
	rm -f $(OBJ)

fclean: clean
	make -C lib/get_next_line fclean
	make -C lib/my fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
