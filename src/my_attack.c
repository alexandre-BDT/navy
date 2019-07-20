/*
** EPITECH PROJECT, 2018
** attak
** File description:
** attak
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include "get_next_line.h"
#include "my.h"
#include "navy.h"

int my_convert_coord(char *str)
{
	int res = 0;

	if (str == NULL)
		return (100);
	if (!(str[0] >= 'A' && str[0] <= 'H')) {
		my_putstr("wrong position\n");
		return (-1);
	}
	if (!(str[1] >= '1' && str[1] <= '8')) {
		my_putstr("wrong position\n");
		return (-1);
	}
	if (my_strlen(str) > 2){
		my_putstr("wrong position\n");
		return (-1);
	}
	res = str[0] - 64;
	res *= 10;
	res += str[1] - 48;
	return (res);
}

void my_send_coord(int coord, int pid)
{
	int k = 0;
	int c = 0;
	int n = coord;
	int res = 0;

	for (c = 31; c >= 0; c--) {
		k = n >> c;
		if (k & 1) {
			res = n >> 1;
			kill(pid, SIGUSR1);
		} else {
			res = n >> 0;
			kill(pid, SIGUSR2);
		}
		usleep(2000);
	}
}

int my_attak(t_game *game, char **av, t_shots *shot)
{
	int coord = -1;
	char *str = NULL;

	while (coord < 0) {
		my_putstr("attack: ");
		str = get_next_line(0);
		if (str == NULL) {
			for (int c = 31; c >= 0; c--) {
				kill(game->foe_pid, SIGUSR1);
				usleep(3000);
			}
			return (-1);
		}
		coord = my_convert_coord(str);
	}
	shot->my_shot = my_strcpy(shot->my_shot, my_reverse_coord(coord));
	my_send_coord(coord, game->foe_pid);
}
