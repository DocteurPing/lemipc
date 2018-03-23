/*
** EPITECH PROJECT, 2018
** PSU_lemipc_2017
** File description:
** initplayer
*/

#include "lemipc.h"

map_t *init_player(lemipc_t *lemipc, char *team_char)
{
	map_t *tmp = (map_t *)lemipc->addr;
	int x = rand() % MAP_SIZE + 0;
	int y = rand() % MAP_SIZE + 0;
	int team_nbr = atoi(team_char);
	pid_t pid = getpid();

	srand(time(NULL));
	get_access_memory(lemipc->sem_id);
	while (tmp->map[x][y].team_nbr != 0) {
		x = rand() % MAP_SIZE + 0;
		y = rand() % MAP_SIZE + 0;
	}
	tmp->map[x][y].team_nbr = team_nbr;
	tmp->map[x][y].pid = pid;
	left_memory_access(lemipc->sem_id);
	return (map_t *)lemipc->addr;
}