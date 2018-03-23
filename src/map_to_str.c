/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** map_to_str
*/

#include "lemipc.h"

static char *map_to_str(map_t map)
{
	char *str = malloc(sizeof(char) * (MAP_SIZE + 1) * MAP_SIZE);
	int x = 0;
	int y = 0;

	for (; y < MAP_SIZE; y++) {
		x = 0;
		for (; x < MAP_SIZE; x++) {
			str[x + (y * (MAP_SIZE + 1))] =
				map.map[y][x].team_nbr + 48;
		}
		str[x + (y * (MAP_SIZE + 1))] = '\n';
	}
	str[x + (y * (MAP_SIZE + 1)) + 1] = '\0';
	printf("%s\n", str);
	return (str);
}