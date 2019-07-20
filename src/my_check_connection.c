/*
** EPITECH PROJECT, 2018
** check
** File description:
** check
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>
#include "my.h"
#include "navy.h"

void sighandler(int sig, siginfo_t *info, void *context)
{
	if (sig == SIGUSR1) {
		var = info->si_pid;
	}
	if (sig == SIGUSR2) {
		var = 1;
	}
}

int my_check_serveur_connection(struct sigaction act, t_game *game)
{
	my_putstr("my_pid: ");
	my_put_nbr(getpid());
	my_putstr("\n");
	my_putstr("waiting for enemy connection...\n");
	sigaction(SIGUSR1, &act, NULL);
	pause();
	game->foe_pid = var;
	var = 0;
	kill(game->foe_pid, SIGUSR2);
	sigaction(SIGUSR2, &act, NULL);
	pause();
	if (var == 1)
		my_putstr("\nenemy connected\n");
	return (0);
}

int my_check_client_connection(int pid, struct sigaction act, t_game *game)
{
	struct timespec delay;
	delay.tv_sec = 0;
	delay.tv_nsec = 500000000L;
	my_putstr("my_pid: ");
	my_put_nbr(getpid());
	my_putstr("\n");
	kill(pid, SIGUSR1);
	sigaction(SIGUSR2, &act, NULL);
	if (nanosleep(&delay, 0) != -1) {
		my_putstr("wrond pid\n");
		return (-1);
	}
	kill(pid, SIGUSR2);
	if (var == 1)
		my_putstr("successfully connected\n");
	return (0);
}
