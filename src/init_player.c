/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** initplayer
*/

#include "lemipc.h"

map_t *init_player(map_t *map_struct, char *team_char)
{
	srand(time(NULL));
	int x = rand() % MAP_SIZE + 0;
	int y = rand() % MAP_SIZE + 0;
	printf("x: %d\ny: %d\n", x, y);
	int team_nbr = atoi(team_char);
	pid_t pid = getpid();
	map_struct->map[x][y].team_nbr = team_nbr;
	map_struct->map[x][y].pid = pid;
	printf("map[x][y].team_nbr : %ld\n", map_struct->map[x][y].team_nbr);
	return map_struct;
}