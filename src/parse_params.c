/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** parse_params
*/

#include "lemipc.h"

int check_nbr(char *nbr)
{
	int i = 0;

	for (; nbr[i]; i++) {
		if (nbr[i] < '0' || nbr[i] > '9')
			return (84);
	}
	return (0);
}

int parse_params(int ac, char **av)
{
	if (ac == 2 && strcmp("--help", av[1]) == 0)
		print_usage();
	if (ac != 3) {
		return (84);
	}
	return (check_nbr(av[2]));
}