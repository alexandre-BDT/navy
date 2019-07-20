/*
** EPITECH PROJECT, 2018
** strlen
** File description:
** strlen
*/

int my_strlen(char *str)
{
	int i = 0;

	while (*str) {
		*str++;
		i++;
	}
	return (i);
}
