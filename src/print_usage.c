/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** print_usage
*/

#include "lemipc.h"

void print_usage(void)
{
	printf("USAGE\n");
	printf("\t./lemipc PATH TEAM_NUMBER\n\n");
	printf("DESCRIPTION\n");
	printf("\tPATH\t\tpath you'll give to ftok\n");
	printf("\tTEAM_NUMBER\tteam number of the current ");
	printf("champion (greater than 0)\n");
	exit (0);
}