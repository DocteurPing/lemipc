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
	
	for(; y < MAP_SIZE; y++) {
		x = 0;
		for (; x < MAP_SIZE; x++)
			printf("%ld\t", map.map[y][x].team_nbr);
		printf("\n");
	}
}