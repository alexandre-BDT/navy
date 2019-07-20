/*
** EPITECH PROJECT, 2018
** rescive
** File description:
** rescive
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "get_next_line.h"
#include "my.h"
#include "navy.h"

int my_recive_coord(int pid, struct sigaction act)
{
	char *str = malloc(sizeof(char) * 32 + 1);

	for (int c = 0; c <= 31; c++) {
		sigaction(SIGUSR2, &act, NULL);
		sigaction(SIGUSR1, &act, NULL);
		pause();
		if (var == 1)
			str[c] = '1';
		else if (var == 0)
			str[c] = '0';
		str[c + 1] = '\0';
	}
	int res = my_get_nbr_base(str, "01");
	free(str);
	return (res);
}

char *my_reverse_coord(int coord)
{
	char *str = malloc(sizeof(char) * 3);

	str[0] = (coord / 10) + 64;
	str[1] = (coord % 10) + 48;
	return (str);
}

char	*my_rescive_attak(t_game *game, t_shots *shot)
{
	struct sigaction newact;

	newact.sa_sigaction = sighandler_coord;
	newact.sa_flags = SA_SIGINFO;
	int res = my_recive_coord(game->foe_pid, newact);
	if (res == -1)
		return (NULL);
	my_putstr(my_reverse_coord(res));
	shot->foe_shot = my_reverse_coord(res);
	return (my_reverse_coord(res));
}
