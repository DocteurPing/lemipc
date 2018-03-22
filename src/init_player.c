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
	srand(time(NULL));
	int x = rand() % MAP_SIZE + 0;
	int y = rand() % MAP_SIZE + 0;
	printf("x: %d\ny: %d\n", x, y);
	int team_nbr = atoi(team_char);
	pid_t pid = getpid();

	if (get_access_memory(lemipc->sem_id)) {
		tmp->map[x][y].team_nbr = team_nbr;
		tmp->map[x][y].pid = pid;
		left_memory_access(lemipc->sem_id);
		#ifdef DEBUG
			printf("map[x][y].team_nbr : %ld\n",
				((map_t *)lemipc)->map[x][y].team_nbr);
		#endif
	} else {
		lemipc->addr = init_player(lemipc, team_char);
	}
	return (map_t *)lemipc->addr;
}