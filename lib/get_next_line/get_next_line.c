/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char *my_strcat(char *dest, char *src)
{
	int j = 0;
	int i = 0;

	if (dest == NULL || src == NULL)
		return (NULL);
	while (dest[j])
		j++;
	while (src[i] != '\0') {
		dest[j] = src[i];
		i++;
		j++;
	}
	dest[j] = '\0';
	return (dest);
}

int my_find(char *str, int mod)
{
	int i = 0;

	if (str == NULL)
		return (0);
	if (mod == 0) {
		while (str[i])
			i++;
		return (i);
	}
	while (str[i]) {
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char *my_realloc(char *str, int size)
{
	char *tmp = NULL;
	int i = 0;

	if (str == NULL) {
		str = malloc(sizeof(char) * (size + 1));
		if (str == NULL)
			return (NULL);
		str[0] = 0;
		return (str);
	}
	if (size == 0)
		return (str);
	tmp = malloc(sizeof(char) * (my_find(str, 0) + READ_SIZE + 1));
	while (str[i]) {
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char *my_find_res(char *str, char *res, int i)
{
	res = malloc(sizeof(char) * (my_find(str, 0) + 2));
	if (res == NULL)
		return (NULL);
	while (str[i] && str[i] != '\n') {
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char *get_next_line(int fd)
{
	static char *buff = NULL;
	char *tmp = malloc(sizeof(char) * (READ_SIZE + 1));
	int c = 0;

	if (fd < 0 || READ_SIZE < 1 || tmp == NULL)
		return (0);
	tmp[0] = 0;
	while (my_find(buff, 1) == 0) {
		c = read(fd, tmp, READ_SIZE);
		if (c <= 0) {
			buff = my_realloc(buff, 1);
			buff = NULL;
			return (buff);
		}
		tmp[c] = 0;
		buff = my_realloc(buff, c);
		buff = my_strcat(buff, tmp);
	}
	char *res = my_find_res(buff, NULL, 0);
	buff = &buff[my_find(res, 0) + 1];
	return (res);
}
