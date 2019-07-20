##
## EPITECH PROJECT, 2018
## make
## File description:
## make
##

NAME	=	libmy.a

SRC	=	my_strlen.c		\
		my_atoi.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_getnbr_base.c	\
		my_putchar.c		\
		my_strcpy.c		\

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
