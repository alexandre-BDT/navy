/*
** EPITECH PROJECT, 2018
** putstr
** File description:
** putstr
*/

#include <unistd.h>
#include "my.h"

void my_putstr(char *str)
{
	write(1, str, my_strlen(str));
}
