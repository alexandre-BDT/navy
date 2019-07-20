/*
** EPITECH PROJECT, 2017
** atoi
** File description:
** atoi
*/

int my_atoi(char *str)
{
	int i = 0;
	int negativ = 1;
	int number = 0;

	while ((str[i] == ' ') ||
	(str[i] == '\t') ||
	(str[i] == '\n') ||
	(str[i] == '\v') ||
	(str[i] == '\f') ||
	(str[i] == '\r'))
		i++;
	if (str[i] == 45)
		negativ = -1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57) {
		number *= 10;
		number += ((int)str[i] - 48);
		i++;
	}
	return (number * negativ);
}
