/*
** EPITECH PROJECT, 2018
** navy 
** File description:
** check if the ships coordinates are well written/placed
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include "navy.h"
#include "my.h"

int	check_bis(char *map, int i)
{
	int start = 0;
	int end = 0;

	if (map[2] == map[5]) {
		if (right_map(start, end, i, map) == 84)
			return (84);
	} else if (map[3] != map[6])
		return (84);
	if (horizontal(map, i) == 84)
		return (84);
	return (0);
}

int	check(char *map)
{
	int i = 0;
	int len = my_strlen(map);

	if (len != 7)
		return (84);
	if ((map[0] < '2' || map[0] > '5') || map[1] != ':')
		return (84);
	if ((map[2] < 'A' || map[2] > 'H') || map[4] != ':')
		return (84);
	i = map[0] - 48;
	if (check_bis(map, i) == 84)
		return (84);
	return (0);
}

int	check_coordinate(char *path)
{
	int fd = 0;
	char *map = NULL;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (-1);
	for (int i = 0; i < 5; i++) {
		map = get_next_line(fd);
		if (map == NULL && i == 0 || (map == NULL && i != 4))
			return (-1);
		if (map == NULL)
			return (0);
		if (check(map) == 84) {
			my_putstr("Wrong map\n");
			close(fd);
			return (-1);
		}
	}
	close(fd);
	return (0);
}
