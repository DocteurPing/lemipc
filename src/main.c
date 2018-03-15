/*
** EPITECH PROJECT, 2018
** lemIPC
** File description:
** main
*/

#include "lemipc.h"

int main(int ac, char **av)
{
	lemipc_t *lemipc = NULL;

	if (parse_params(ac, av) == 84)
		return (84);
	check_start(lemipc, av[1]);
	return (0);
}