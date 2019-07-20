/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "get_next_line.h"
#include "my.h"
#include "navy.h"

int var = 0;

int	player_two(char **av, t_map *map, t_game *game, struct sigaction act)
{
	if (create_map_lot(av[2], map, 1) == -1)
		return (84);
	if (my_check_client_connection(my_atoi(av[1]), act, game) == 0) {
		game->foe_pid = my_atoi(av[1]);
		loop_p1(av, map, game, act);
		return (0);
	} else
		return (84);
	return (0);
}

int	player_one(char **av, t_map *map, t_game *game, struct sigaction act)
{
	if (create_map_lot(av[1], map, 0) == -1)
		return (84);
	if (my_check_serveur_connection(act, game) == 0)
		loop_p2(av, map, game, act);
	else
		return (84);
	return (0);
}

int	main(int ac, char **av)
{
	struct sigaction act;
	t_game *game = malloc(sizeof(t_game));
	t_map *map = malloc(sizeof(t_map));

	act.sa_sigaction = sighandler;
	sigemptyset(&act.sa_mask);
	act.sa_flags = SA_SIGINFO;
	var = 0;
	if (ac == 3) {
		if (game_p1(av, act, game, map) == 84)
			return (84);
	} else if (ac == 2){
		if (game_p2(av, act, game, map) == 84)
			return (84);
	}
	return (0);
}
