/*
** EPITECH PROJECT, 2018
** navy
** File description:
** usefull function
*/

#include <stdlib.h>
#include "my.h"
#include "navy.h"

void sighandler_coord(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		var = 1;
	if (sig == SIGUSR2)
		var = 0;
}

void	sighandler_exit(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1)
		var = 1;
}

void	free_map(t_map *map, t_game *game)
{
	for (int i = 0; i < 8; i++) {
		free(map->p1_map[i]);
		free(map->p2_map[i]);
		free(map->p1_blank_map[i]);
		free(map->p2_blank_map[i]);
	}
	free(map->p1_map);
	free(map->p2_map);
	free(map->p1_blank_map);
	free(map->p2_blank_map);
	free(map);
	free(game);
}
