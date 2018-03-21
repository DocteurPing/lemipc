/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** display_map
*/

#include "lemipc.h"

void display_map(map_t map)
{
	int x = 0;
	int y = 0;

	for (x = 0; x < MAP_SIZE * 2 + 2; x++)
		printf("-");
	printf("\n");
	for (; y < MAP_SIZE; y++) {
		x = 0;
		printf("|");
		for (; x < MAP_SIZE; x++) {
			if (map.map[y][x].team_nbr == 0)
				printf("  ");
			else
				printf("%ld ", map.map[y][x].team_nbr);
		}
		printf("|\n");
	}
	for (x = 0; x < MAP_SIZE * 2 + 2; x++)
		printf("-");
	printf("\n");
}