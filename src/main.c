/*
** EPITECH PROJECT, 2018
** lemIPC
** File description:
** main
*/

#include "lemipc.h"

int main(int ac, char **av)
{
	if (parse_params(ac, av) == 84)
		return (84);
	printf("OK\n");
	return (0);
}