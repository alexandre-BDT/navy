/*
** EPITECH PROJECT, 2018
** navy
** File description:
** game loop
*/

#include <stdlib.h>
#include "get_next_line.h"
#include "my.h"
#include "navy.h"

t_shots	*my_create_shot(t_shots *shot)
{
	shot = malloc(sizeof(t_shots));
	shot->my_shot = malloc(sizeof(char) * 3);
	shot->foe_shot = malloc(sizeof(char) * 3);
	shot->touched = 0;
	return (shot);
}

int	game_p1(char **av, struct sigaction act, t_game *game, t_map *map)
{
	if (check_coordinate(av[2]) == -1)
		return (84);
	if (player_two(av, map, game, act) == 84)
		return (84);
	return (0);
}

int	game_p2(char **av, struct sigaction act, t_game *game, t_map *map)
{
	if (check_coordinate(av[1]) == -1)
		return (84);
	if (player_one(av, map, game, act) == 84)
		return (84);
	return (0);
}

int	loop_p1(char **av, t_map *map, t_game *game, struct sigaction act)
{
	char *coord = NULL;
	t_shots *shot = my_create_shot(shot);

	while (1) {
		print_map(av[2], map, 1);
		print_blank_map(map, map->p2_blank_map);
		my_putstr("waiting for enemy's attack...\n");
		coord = my_rescive_attak(game, shot);
		if (coord == NULL)
			return (-1);
		put_shot(map->p2_map, coord, game);
		my_putchar('\n');
		if (my_attak(game, av, shot) == -1)
			return (-1);
		hit_shot(act, shot);
		update_map(shot, map->p2_blank_map);
		if (count_boat(map->p2_map, map->p2_blank_map) == 1
			|| count_boat(map->p2_map, map->p2_blank_map) == -1)
			return (0);
	}
	return (0);
}

int	loop_p2(char **av, t_map *map, t_game *game, struct sigaction act)
{
	char *coord = NULL;
	t_shots *shot = my_create_shot(shot);

	while (1) {
		print_map(av[1], map, 0);
		print_blank_map(map, map->p1_blank_map);
		if (my_attak(game, av, shot) == -1)
			return (-1);
		hit_shot(act, shot);
		update_map(shot, map->p1_blank_map);
		my_putstr("\nwaiting for enemy's attack...\n");
		coord = my_rescive_attak(game, shot);
		if (coord == NULL)
			return (-1);
		put_shot(map->p1_map, coord, game);
		if (count_boat(map->p1_map, map->p1_blank_map) == 1
			|| count_boat(map->p1_map, map->p1_blank_map) == -1)
			return (0);
	}
	return (0);
}
