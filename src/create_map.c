/*
** EPITECH PROJECT, 2018
** navy
** File description:
** create map
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "navy.h"
#include "get_next_line.h"
#include "my.h"

int	**line(int **tab, t_coord *coord, int ships)
{
	if (coord->x1 < coord->x2) {
		for (int i = coord->x1; i <= coord->x2; i++) {
			if (check_ships(tab, coord->y1, i) == -1)
				return (NULL);
			tab[i][coord->y1] = ships;
		}
	} else if (coord->x2 < coord->x1) {
		for (int i = coord->x1; i >= coord->x2; i--) {
			if (check_ships(tab, coord->y1, i) == -1)
				return (NULL);
			tab[i][coord->y1] = ships;
		}
	}
	return (tab);
}

int	**column(int **tab, t_coord *coord, int ships)
{
	if (coord->y1 < coord->y2) {
		for (int i = coord->y1; i <= coord->y2; i++) {
			if (check_ships(tab, i, coord->x1) == -1)
				return (NULL);
			tab[coord->x1][i] = ships;
		}
	} else if (coord->y2 < coord->y1) {
		for (int i = coord->y1; i >= coord->y2; i--) {
			if (check_ships(tab, i, coord->x1) == -1)
				return (NULL);
			tab[coord->x1][i] = ships;
		}
	}
	return (tab);
}

int	**put_ships(int **tab, char *pos, int ships)
{
	t_coord *coord = malloc(sizeof(t_coord));
	int boat = pos[0] - 48;

	coord->x1 = pos[3] - 49;
	coord->x2 = pos[6] - 49;
	coord->y1 = pos[2] - 65;
	coord->y2 = pos[5] - 65;
	if (check_s(tab, boat) == -1)
		return (NULL);
	if (pos[2] == pos[5])
		tab =  line(tab, coord, ships);
	else if (pos[2] != pos[5])
		tab = column(tab, coord, ships);
	if (tab == NULL)
		return (NULL);
	free(coord);
	return (tab);
}

int	**ships_pos(int **tab, char *path)
{
	int fd = 0;
	char *pos = NULL;
	int ships = 0;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	for (;;) {
		pos = get_next_line(fd);
		if (pos == NULL)
			return (tab);
		ships = pos[0] - 48;
		tab = put_ships(tab, pos, ships);
		if (tab == NULL)
			return (NULL);
	}
	close(fd);
	return (tab);
}

int	**create_map(char *path, t_map *map)
{
	int n = 0;

	map->p1_map = 0;
	map->p1_blank_map = 0;
	map->p1_map = malloc(8 * sizeof(int*) + 40);
	map->p1_blank_map = malloc(8 * sizeof(int*) + 40);
	if (map->p1_map == NULL)
		return (NULL);
	for (int i = 0; i < 8; i++) {
		map->p1_map[i] = malloc(8 * sizeof(int*) + 40);
		map->p1_blank_map[i] = malloc(8 * sizeof(int*) + 40);
		while (n < 8) {
			map->p1_map[i][n] = 0;
			map->p1_blank_map[i][n] = 0;
			n++;
		}
		n = 0;
	}
	return (map->p1_map);
}
