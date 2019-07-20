/*
** EPITECH PROJECT, 2018
** gentbase
** File description:
** getbase
*/

#include "my.h"

int    	base_nbr_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i] != '\0') {
		if (c == base[i])
			return (i);
		i++;
	}
	return (0);
}

int    	my_get_nbr_base(char *str, char *base)
{
	int	nb_final = 0;
	int	base_l = my_strlen(base);
	int	str_l = my_strlen(str) - 1;
	int     conv_fact = 1;

	if (str[0] == '-')
		return (-my_get_nbr_base(str + 1, base));
	while (str_l >= 0) {
		nb_final = nb_final + base_nbr_index(str[str_l], base)
		* conv_fact;
		conv_fact = base_l * conv_fact;
		str_l = str_l - 1;
	}
	return (nb_final);
}
