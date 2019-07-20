/*
** EPITECH PROJECT, 2018
** navy
** File description:
** navy
*/

#ifndef		NAVY_H_
#define		NAVY_H_

#include <signal.h>

extern int var;

typedef struct s_shots
{
	char *my_shot;
	int touched;
	char *foe_shot;
} t_shots;

typedef struct s_game
{
	int foe_pid;
} t_game;

typedef struct s_coordinate
{
	int x1;
	int y1;
	int x2;
	int y2;
} t_coord;

typedef struct s_map
{
	int **p1_map;
	int **p2_map;
	int **p1_blank_map;
	int **p2_blank_map;
} t_map;

int	game_p1(char **, struct sigaction, t_game *, t_map *);
int	game_p2(char **, struct sigaction, t_game *, t_map *);
int	loop_p1(char **av, t_map *map, t_game *game, struct sigaction act);
int	loop_p2(char **av, t_map *map, t_game *game, struct sigaction act);
int     player_one(char **av, t_map *map, t_game *game, struct sigaction act);
int     player_two(char **av, t_map *map, t_game *game, struct sigaction act);
int	my_attak(t_game *game, char **av, t_shots *shot);
int	my_recive_coord(int pid, struct sigaction act);
int	my_check_serveur_connection(struct sigaction act, t_game*);
int	my_check_client_connection(int pid, struct sigaction act, t_game*);
int	check_coordinate(char *);
int	check_ships(int **, int, int);
int	check_s(int **tab, int pos);
int	horizontal(char *, int);
int	vertical(int , int , int);
int	right_map(int, int, int, char *);
int	receive(int);
int	count_boat(int **, int **);
int	create_map_lot(char *, t_map *, int);
void	sighandler_coord(int sig, siginfo_t *info, void *context);
void	sighandler(int sig, siginfo_t *info, void *context);
void	sighandler_player(int, siginfo_t *, void *);
void	hit_shot(struct sigaction, t_shots *shot);
void	update_map(t_shots *, int **);
void	free_map(t_map *, t_game *);
char	*my_rescive_attak(t_game *game, t_shots *shot);
char	*my_reverse_coord(int coord);
int	**print_blank_map(t_map *, int **);
int	**ships_pos(int **tab, char *path);
int	**create_map(char *, t_map *);
int	**print_map(char *, t_map *, int);
int	**convert(int **, int, int);
int	**second_map(char *, char *, t_map *);
int	**enemy_map();
int	**put_shot(int **, char *, t_game *);

#endif		/*!NAVY_H_*/
