/*
** EPITECH PROJECT, 2018
** navy
** File description:
** put the shots
*/

#include <stdlib.h>
#include <unistd.h>
#include "navy.h"
#include "get_next_line.h"
#include "my.h"

int	count_boat(int **tab, int **tab2)
{
	int nb = 0;
	int nb2 = 0;

	for (int i = 0; i < 8; i++) {
		for (int n = 0; n < 8; n++) {
			if (tab[i][n] == 'x')
				nb++;
			if (tab2[i][n] == 'x')
				nb2++;
		}
	}
	if (nb == 14) {
		my_putstr("Ennemy won\n\n");
		return (0);
	} else if (nb2 == 14) {
		my_putstr("I won\n\n");
		return (1);
	}
	return (2);
}

void	handler_hit(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1) {
		var = 2;
	}
	if (sig == SIGUSR2) {
		var = 3;
	}
}

void	hit_shot(struct sigaction act_shot, t_shots *shot)
{
	act_shot.sa_sigaction = handler_hit;
	act_shot.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act_shot, NULL);
	sigaction(SIGUSR2, &act_shot, NULL);
	pause();
	if (var == 2)
		shot->touched = 1;
	else if (var == 3)
		shot->touched = -1;
	var = 0;
}

int	**put_shot(int **tab, char *coord, t_game *game)
{
	int y = coord[0] - 65;
	int x = coord[1] - 49;

	my_putstr(": ");
	usleep(5000);
	if (coord != NULL) {
		if (tab[x][y] == 0) {
			my_putstr("missed\n");
			kill(game->foe_pid, SIGUSR1);
		} else if (tab[x][y] >= 2 || tab[x][y] <= 5) {
			my_putstr("hit\n");
			tab[x][y] = 'x';
			kill(game->foe_pid, SIGUSR2);
		}
	}
	return (tab);
}

void	update_map(t_shots *shot, int **tab)
{
	int y = shot->my_shot[0] - 65;
	int x = shot->my_shot[1] - 49;

	if (shot->touched == -1) {
		tab[x][y] = 'x';
		my_putstr(shot->my_shot);
		my_putstr(": hit\n");
	} else if (shot->touched == 1) {
		tab[x][y] = 'o';
		my_putstr(shot->my_shot);
		my_putstr(": missed\n");
	}
}
