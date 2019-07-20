##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

NAME	=	libline.a

SRC	=	get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I../../include

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ..

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
