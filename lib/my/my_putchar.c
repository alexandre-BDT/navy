/*
** EPITECH PROJECT, 2017
** 
** File description:
** 
*/

#include <unistd.h>
#include <stdarg.h>
#include "../../include/printf.h"
#include "../../include/my.h"

void	my_putchar(char c)
{
	write(1, &c, 1);
}
