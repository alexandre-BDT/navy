/*
** EPITECH PROJECT, 2018
** nay
** File description:
** create map bis
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "get_next_line.h"
#include "my.h"

int	multi_ship(int **tab, int i, int pos)
{
	for (int n = 0; n < 8; n++) {
		if (tab[i][n] == pos)
			return (-1);
	}
	return (0);
}
int	check_s(int **tab, int pos)
{
	for (int i = 0; i < 8; i++) {
		if (multi_ship(tab, i, pos) == -1)
			return (-1);
	}
	return (0);
}

int	check_ships(int **tab, int x, int y)
{
	if (tab[y][x] != 0)
		return (-1);
	return (0);
}

int	**create_map_p2(char *path, t_map *map)
{
	int n = 0;

	map->p2_map = 0;
	map->p2_blank_map = 0;
	map->p2_blank_map = malloc(8 * sizeof(int*) + 40);
	map->p2_map = malloc(8 * sizeof(int*) + 40);
	if (map->p2_map == NULL)
		return (NULL);
	for (int i = 0; i < 8; i++) {
		map->p2_map[i] = malloc(8 * sizeof(int*) + 40);
		map->p2_blank_map[i] = malloc(8 * sizeof(int*) + 40);
		while (n < 8) {
			map->p2_map[i][n] = 0;
			map->p2_blank_map[i][n] = 0;
			n++;
		}
		n = 0;
	}
	return (map->p2_map);
}

int	create_map_lot(char *path, t_map *map, int nb)
{
	if (nb == 0) {
		create_map(path, map);
		if (ships_pos(map->p1_map, path) == NULL)
			return (-1);
	}
	if (nb == 1) {
		create_map_p2(path, map);
		if (ships_pos(map->p2_map, path) == NULL)
			return (-1);
	}
	return (0);
}
