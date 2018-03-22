/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** initplayer
*/

#include "lemipc.h"

int get_rand_nbr()
{
	int nbr = rand() % MAP_SIZE + 0;
	return nbr;
}

map_t *init_player(map_t *map_struct, char *team_char)
{
	srand(time(NULL));
	int x = get_rand_nbr();
	int y = get_rand_nbr();
	printf("x: %d\ny: %d\n", x, y);
	int team_nbr = atoi(team_char);
	pid_t pid = getpid();
	map_struct->map[x][y].team_nbr = team_nbr;
	map_struct->map[x][y].pid = pid;
	printf("map[x][y].team_nbr : %ld", map_struct->map[x][y].team_nbr);
	return map_struct;
}