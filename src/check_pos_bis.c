/*
** EPITECH PROJECT, 2018
** my_navy
** File description:
** check ships position
*/

#include "navy.h"
#include "my.h"

int	right_map(int start, int end, int i, char *map)
{
	start = map[3] - 48;
	end = map[6] - 48;
	if (start == 0 || start == 9 || end == 0 || end == 9)
		return (84);
	if (vertical(start, end, i) == 84)
		return (84);
	return (0);
}

int     horizontal(char *map, int i)
{
	if (map[2] < map[5]) {
		if (map[2] + i - 1 != map[5])
			return (84);
	} else if (map[2] > map[5]) {
		if (map[5] + i - 1 != map[2])
			return (84);
	}
	return (0);
}

int	vertical(int start, int end, int i)
{
	if (start < end) {
		if ((start - 1) + i != end)
			return (84);
	} else if (start > end) {
		if ((end - 1) + i != start)
			return (84);
	}
	return (0);
}
