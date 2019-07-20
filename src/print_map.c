/*
** EPITECH PROJECT, 2018
** navy
** File description:
** print navy map
*/

#include <stdlib.h>
#include "my.h"
#include "navy.h"

int	**convert_bis(int **map, int i, int n)
{
	if (map[i][n] == 'x')
		my_putchar('x');
	else if (map[i][n] == 'o')
		my_putchar('o');
	return (map);
}

int	**convert(int **map, int i, int n)
{
	if (map[i][n] == 0)
		my_putchar('.');
	else if (map[i][n] != 'x' && map[i][n] != 'o')
		my_put_nbr(map[i][n]);
	convert_bis(map, i, n);
	if (n != 7)
		my_putchar(' ');
	return (map);
}

int	**print_blank_map(t_map *map, int **tab)
{
	my_putstr("\nenemy's positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 0; i < 8; i++) {
		my_put_nbr(i + 1);
		my_putchar('|');
		for (int n = 0; n < 8; n++)
			convert(tab, i, n);
		my_putchar('\n');
	}
	my_putchar('\n');
	return (tab);
}

int	**print_map(char *path, t_map *map, int nb)
{
	int **tab = 0;

	if (nb == 0)
		tab = map->p1_map;
	else if (nb == 1)
		tab = map->p2_map;
	my_putstr("\nmy positions:\n");
	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int i = 0; i < 8; i++) {
		my_put_nbr(i + 1);
		my_putchar('|');
		for (int n = 0; n < 8; n++)
			convert(tab, i, n);
		my_putchar('\n');
	}
	return (tab);
}
