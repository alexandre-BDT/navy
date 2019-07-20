/*
** EPITECH PROJECT, 2017
** putnbr
** File description:
** putnbr
*/

#include <unistd.h>

void my_putchar(char c)
{
	write(1, &c, 1);
}

int my_put_nbr(int nb)
{
	if (nb < 0) {
		my_putchar('-');
		nb = -nb;
	}
	if (nb > 9) {
		my_put_nbr(nb / 10);
		my_put_nbr(nb % 10);
	} else {
		my_putchar(nb + 48);
	}
	return (0);
}
